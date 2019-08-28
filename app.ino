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
    
}

void loop()
{
    //lcd_menu_update();

    if (millis() >= timer_entradas + TIMER_ENTRADAS_TIEMPO)
    {
        IO_rutina();
        timer_entradas = millis();
    }
}
