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

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

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

void lcd_routines_init()
{
    lcd.init();
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
        LCD_write(' ');
        break;
    case 1: //Tilde sola
        LCD_write('>');
        break;
    case 2: //Flecha sola
        LCD_write('-');
        break;
    case 3: //Flecha + Tilde
        LCD_write(0);
        break;
    }
}

void lcd_menu_update()
{
    LCD_setCursor(0, 0);

    switch (lcd_index_1)
    {
        case 0:
            switch (lcd_index_2)
            {
                case 0: //Menu principal: - Informacion General.
                    
                    break;
            }
            break;
    }
}