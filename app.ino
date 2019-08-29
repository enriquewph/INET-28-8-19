#include "header.h"
/*
ITS VILLADA - INET - GRUPO 7 - 28/08/2019
INTEGRANTES:
- Davalle, Lucas
- Philippeaux, Enrique
*/

uint32_t timer_entradas;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    timer_entradas = millis();
    lcd_subrutina_init();

    TEMPERATURA_UPDATE_RELEASE(); //incluir que esta funcion se ejecute cuando se cargen variables de eeprom o se editen x menu.
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
