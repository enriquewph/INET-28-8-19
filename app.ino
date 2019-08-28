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
    timer_entradas = millis();
    lcd_subrutina_init();
}

void loop()
{
    // put your main code here, to run repeatedly:
    lcd_menu_update();

    if (millis() >= timer_entradas + TIMER_ENTRADAS_TIEMPO)
    {
        //IO_rutina();
        timer_entradas = millis();
    }
}
