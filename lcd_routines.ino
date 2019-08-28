#include "header.h"

/*
	INFORMACION (screensaver si no se tocan cosas x 10 seg).
	MODO: [MANUAL/AUTOMATICO]
	PARAMETROS AUTO.
	    TEMPERATURA
	        MINIMO: [VALOR]
	        MAXIMO: [VALOR]
	    HUMEDAD
	        MINIMO: [VALOR]
	        MAXIMO: [VALOR]
	    ILUMINACION
	        MINIMO: [VALOR]
	        MAXIMO: [VALOR]
	CONTROL MANUAL (solo en modo manual)
	    REFRIGREACION [ON/OFF]
	    CALEFACTOR [ON/OFF]
	    RIEGO[ON/OFF]
	    ILUMINACION[0-100%]
	EVENTOS
	    LISTA DE EVENTOS
	    ULTIMO EVENTO
*/

//lcd_routines:
uint8_t lcd_index_1 = 0;
uint8_t lcd_index_2 = 0;
uint8_t lcd_index_3 = 0;

uint8_t CharFlechaTilde[8] = { //Index: 0
    0b00000,
    0b00000,
    0b00100,
    0b00010,
    0b11111,
    0b00010,
    0b00100,
    0b00000};

uint8_t CharFlechaVolver[8] = { //Index: 1
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b00100,
    0b00100,
    0b00111,
    0b00000};

void lcd_subrutina_init()
{
    lcd.init();
    lcd.begin(20, 4);
    // Print a message to the LCD.
    lcd.backlight();
    lcd.createChar(0, CharFlechaTilde);
    lcd.createChar(1, CharFlechaVolver);
    lcd.home();
}

void lcd_subrutina_printFlecha(uint8_t flecha)
{
    switch (flecha)
    {
    case 0: //No flecha
        lcd.print(' ');
        break;
    case 1: //Tilde sola
        lcd.print('>');
        break;
    case 2: //Flecha sola
        lcd.print('-');
        break;
    case 3: //Flecha + Tilde
        lcd.print(0);
        break;
    }
}

void lcd_subrutina_printModo()
{
    if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
        lcd.print(F("AUTOMATICO   "));
    else
        lcd.print(F("MANUAL       "));
}

void lcd_subrutina_screenInfo()
{
    sprintf(lcdBuffer, "TEMP:%f3.1C LUZ:%i4L", TEMPERATURA, LUX);
    lcd.print(lcdBuffer);

    lcd.setCursor(0, 1);
    if (FUNCIONAMIENTO_TEMP == MODO_TEMP_STANDBY)
        lcd.print(F("STANDBY"));
    else if (FUNCIONAMIENTO_TEMP == MODO_TEMP_CALENTANDO)
        lcd.print(F("CALENTANDO "));
    else if (FUNCIONAMIENTO_TEMP == MODO_TEMP_ENFRIANDO)
        lcd.print(F("ENFRIANDO  "));

    lcd.setCursor(0, 2);
    sprintf(lcdBuffer, " HUM:%i3%% ", HUMEDAD);
    lcd.print(lcdBuffer);

    lcd.setCursor(0, 3);
    if (FUNCIONAMIENTO_REGADO == MODO_REGADO_APAGADO)
        lcd.print(F("STANDBY     VOLVER:X"));
    else
        lcd.print(F("REGANDO     VOLVER:X"));

    lcd.setCursor(10, 1);
    sprintf(lcdBuffer, "LUCES:%i3%%", POTENCIA_LUCES);
    lcd.print(lcdBuffer);

    lcd.setCursor(14, 2);
    if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
        lcd.print(F("  AUTO"));
    else
        lcd.print(F("MANUAL"));
}

void lcd_menu_update()
{
    lcd.setCursor(0, 0);

    switch (lcd_index_1)
    {
    case 0:
        switch (lcd_index_2)
        {
        case 0:
            lcd_subrutina_printFlecha(1);
            lcd.print(F("INFORMACION        "));

            lcd.setCursor(0, 1);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("MODO: "));
            lcd_subrutina_printModo();

            lcd.setCursor(0, 2);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("PARAMETROS AUTO    "));

            lcd.setCursor(0, 3);
            lcd.print(F(" ...                "));
            break;
        case 1:
            lcd_subrutina_screenInfo();
            break;
        }
        break;
    case 1:
        switch (lcd_index_2)
        {
        case 0:
            lcd_subrutina_printFlecha(0);
            lcd.print(F("INFORMACION        "));

            lcd.setCursor(0, 1);
            lcd_subrutina_printFlecha(1);
            lcd.print(F("MODO: "));
            lcd_subrutina_printModo();

            lcd.setCursor(0, 2);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("PARAMETROS AUTO    "));

            lcd.setCursor(0, 3);
            lcd.print(F(" ...                "));
            break;
        }
        break;
    case 2:
        switch (lcd_index_2)
        {
        case 0:
            lcd_subrutina_printFlecha(0);
            lcd.print(F("INFORMACION        "));

            lcd.setCursor(0, 1);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("MODO: "));
            lcd_subrutina_printModo();

            lcd.setCursor(0, 2);
            lcd_subrutina_printFlecha(1);
            lcd.print(F("PARAMETROS AUTO    "));

            lcd.setCursor(0, 3);
            lcd.print(F(" ...                "));
            break;
        case 1:
            lcd_subrutina_printFlecha(1);
            lcd.print(F("VOLVER ARRIBA      "));

            lcd.setCursor(0, 1);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("TEMPERATURA        "));

            lcd.setCursor(0, 2);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("HUMEDAD            "));

            lcd.setCursor(0, 3);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("ILUMINACION        "));
            break;
        case 2:
            switch (lcd_index_3)
            {
            case 0:
                lcd_subrutina_printFlecha(0);
                lcd.print(F("VOLVER ARRIBA      "));

                lcd.setCursor(0, 1);
                lcd_subrutina_printFlecha(1);
                lcd.print(F("TEMPERATURA        "));

                lcd.setCursor(0, 2);
                lcd_subrutina_printFlecha(0);
                lcd.print(F("HUMEDAD            "));

                lcd.setCursor(0, 3);
                lcd_subrutina_printFlecha(0);
                lcd.print(F("ILUMINACION        "));
                break;
            case 1:
                lcd_subrutina_printFlecha(1);
                lcd.print(F("VOLVER ARRIBA      "));

                lcd.setCursor(0, 1);
                lcd_subrutina_printFlecha(0);
                lcd.print(F("MINIMO: "));

                lcd.setCursor(0, 2);
                lcd_subrutina_printFlecha(0);
                lcd.print(F("MAXIMO: "));
                break;
            }
            break;
        }
        break;
    case 3:
        switch (lcd_index_2)
        {
        case 0:
            lcd.print(F(" ...                "));

            lcd.setCursor(0, 1);
            lcd_subrutina_printFlecha(1);
            lcd.print(F("CONTROL MANUAL     "));

            lcd.setCursor(0, 2);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("EVENTOS            "));
            break;
        }
        break;
    case 4:
        switch (lcd_index_2)
        {
        case 0:
            lcd.print(F(" ...                "));

            lcd.setCursor(0, 1);
            lcd_subrutina_printFlecha(0);
            lcd.print(F("CONTROL MANUAL     "));

            lcd.setCursor(0, 2);
            lcd_subrutina_printFlecha(1);
            lcd.print(F("EVENTOS            "));
            break;
        }
        break;
    }
}