#include "header.h"
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

- implementar un amplificador al lm35 para obtener mayor resolucion de ganancia X10
- https://electronics.stackexchange.com/questions/194165/increasing-the-resolution-of-a-sensor-by-using-an-amplifier
- organizar, distribuir y comentar el codigo.
*/

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

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

