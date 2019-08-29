#include "header.h"
#include <EEPROM.h>
/*
ITS VILLADA - INET - GRUPO 7 - 28/08/2019
INTEGRANTES:
- Davalle, Lucas
- Philippeaux, Enrique
*/

/*
TODO:
- implementar eeprom --LISTO

- implementar eventos
- implementar control para el luxometro y las luces.
- implementar bloqueo al cambio de variables automaticamente cuando esta en modo manual.
- implementar salidas tanto en manual como en automatico, que el automatico actualize las del manual....
       probaro lo de arriba

- implementar un amplificador al lm35 para obtener mayor resolucion de ganancia X10
- https://electronics.stackexchange.com/questions/194165/increasing-the-resolution-of-a-sensor-by-using-an-amplifier
- organizar, distribuir y comentar el codigo.
*/

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    EEPROM.begin();

    pinMode(PIN_LM35, INPUT);
    pinMode(PIN_HUMEDAD, INPUT);
    pinMode(PIN_LDR, INPUT);

    pinMode(PIN_RELAY_MOTOR, OUTPUT);
    pinMode(PIN_RELAY_CALEFACTOR, OUTPUT);
    pinMode(PIN_RELAY_RIEGO, OUTPUT);
    pinMode(PIN_DIMMER_LUZ, OUTPUT);

    cargar_variables();
    lcd_subrutina_init();

    timer_entradas = millis();
    timeout_screensaver = millis();
}

void loop()
{
    lcd_menu_update();
    teclado_update();

    if (millis() >= timer_entradas + TIMER_ENTRADAS_TIEMPO)
    {
        IO_rutina();
        timer_entradas = millis();
    }
}

void IO_rutina()
{
    HUMEDAD = HUM_leer();
    TEMPERATURA = TEMP_leer();
    LUX = LDR_leer();
    EV_CREACION();

    if (FUNCIONAMIENTO_MODO = MODO_AUTOMATICO) //solo si se esta en automatico procesar y actualizar salidas.
    {
        control_HUMEDAD();
        control_TEMP();

        SALIDA_EXTRACTOR = (FUNCIONAMIENTO_TEMP == MODO_TEMP_ENFRIANDO);
        SALIDA_CALEFACTOR = (FUNCIONAMIENTO_TEMP == MODO_TEMP_CALENTANDO);
        SALIDA_REGADOR = (FUNCIONAMIENTO_REGADO == MODO_REGADO_ENCENDIDO);
    }

    setearSalidas();
}