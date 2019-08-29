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
- implementar eventos
- implementar control para el luxometro y las luces.
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

    if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO) //solo si se esta en automatico procesar y actualizar salidas.
    {
        control_HUMEDAD();
        control_TEMP();

        if (FUNCIONAMIENTO_TEMP == MODO_TEMP_ENFRIANDO)
            SALIDA_EXTRACTOR = 1;
        else
            SALIDA_EXTRACTOR = 0;
        if (FUNCIONAMIENTO_TEMP == MODO_TEMP_CALENTANDO)
            SALIDA_CALEFACTOR = 1;
        else
            SALIDA_CALEFACTOR = 0;
        if (FUNCIONAMIENTO_REGADO == MODO_REGADO_ENCENDIDO)
            SALIDA_REGADOR = 1;
        else
            SALIDA_REGADOR = 0;
        
        if (LUX <= LUX_BAJO)
            POTENCIA_LUCES = 100;
        if (LUX >= LUX_ALTO)
            POTENCIA_LUCES = 0;
        if (LUX >= LUX_BAJO && LUX <= LUX_ALTO)
        {
            POTENCIA_LUCES = 100 - pwmmap(LUX, LUX_BAJO, LUX_ALTO, 0, 100); //a mayor luz detectada, menor pwm
        }
    }
    
    setearSalidas();
}
