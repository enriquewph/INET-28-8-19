#include "header.h"

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

uint8_t CharCentigrados[8] = { //Index: 2
    0x18,
    0x18,
    0x03,
    0x04,
    0x04,
    0x04,
    0x03,
    0x00};

uint8_t CharVolver[8] = { //Index: 3
    0x04,
    0x08,
    0x1E,
    0x09,
    0x05,
    0x01,
    0x11,
    0x0E};

uint8_t CharFlechaAbajo[8] = { //Index: 4
    0x00,
    0x04,
    0x04,
    0x04,
    0x15,
    0x0E,
    0x04,
    0x00};

uint8_t CharFlechaArriba[8] = { //Index: 5
    0x00,
    0x04,
    0x0E,
    0x15,
    0x04,
    0x04,
    0x04,
    0x00};

void lcd_subrutina_init()
{
    lcd.init();
    lcd.begin(20, 4);
    // Print a message to the LCD.
    lcd.backlight();
    lcd.createChar(0, CharFlechaTilde);
    lcd.createChar(1, CharFlechaVolver);
    lcd.createChar(2, CharCentigrados);
    lcd.createChar(3, CharVolver);
    lcd.createChar(4, CharFlechaAbajo);
    lcd.createChar(5, CharFlechaArriba);
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
    double temp_double = TEMPERATURA;
    lcd.print(dtostrf(temp_double, 5, 2, lcdBuffer));
    /*
    char* dtostrf 	( 	double  	__val,
		signed char  	__width,
		unsigned char  	__prec,
		char *  	__s 
	) 	
    */
    lcd.write(2);

    sprintf(lcdBuffer, " |%3u%%", HUMEDAD);
    lcd.print(lcdBuffer);

    sprintf(lcdBuffer, "|%5uLx", LUX);
    lcd.print(lcdBuffer);

    lcd.setCursor(0, 1);
    lcd.print(F("ESTADO"));
    lcd.write(4);
    lcd.print(F("   LUCES:"));
    sprintf(lcdBuffer, "%3u%%", POTENCIA_LUCES);
    lcd.print(lcdBuffer);

    lcd.setCursor(0, 2);
    if (FUNCIONAMIENTO_TEMP == MODO_TEMP_STANDBY)
        lcd.print(F("TEMP: OK      "));
    else if (FUNCIONAMIENTO_TEMP == MODO_TEMP_CALENTANDO)
        lcd.print(F("CALENTANDO    "));
    else if (FUNCIONAMIENTO_TEMP == MODO_TEMP_ENFRIANDO)
        lcd.print(F("ENFRIANDO     "));

    lcd.setCursor(0, 3);
    if (FUNCIONAMIENTO_REGADO == MODO_REGADO_APAGADO)
        lcd.print(F("RIEGO: OFF  VOLVER:"));
    else
        lcd.print(F("RIEGO: ON   VOLVER:"));
    lcd.write(3);

    lcd.setCursor(14, 2);
    if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
        lcd.print(F("  AUTO"));
    else
        lcd.print(F("MANUAL"));
}

void lcd_clearLine(uint8_t linea)
{
    lcd.setCursor(0, linea);
    lcd.print(F("                    "));
}