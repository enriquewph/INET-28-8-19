#include "header.h"

/*
	INFORMACION (screensaver si no se tocan cosas x 10 seg).
	MODO: [MANUAL/AUTOMATICO]
	CONTROL MANUAL
	    EXTRACTOR [ON/OFF] (solo se cambian si esta en manual...)
	    CALEFACTOR [ON/OFF]
	    RIEGO[ON/OFF]
	    ILUMINACION[0-100%]
	EVENTOS
	    LISTA DE EVENTOS
	    ULTIMO EVENTO
*/

void lcd_subrutina_displayONOFF(uint8_t variable)
{
    if (variable)
        lcd.print(F("ON   "));
    else
        lcd.print(F("OFF  "));
}


void lcd_menu_update()
{
    lcd.setCursor(0, 0);

    if (lcd_index_2 == 0)
        lcd_subrutina_menuPrincipal();
    if (lcd_index_1 == 0 && lcd_index_2 == 1)
        lcd_subrutina_screenInfo();
    if (lcd_index_1 == 2 && lcd_index_2 > 0)
        lcd_subrutina_menuControlManual();
    if (lcd_index_1 == 3 && lcd_index_2 > 0)
        lcd_subrutina_menuEventos();
}

void lcd_subrutina_menuEventos()
{
    
    lcd_subrutina_printFlecha(lcd_index_2 == 1);
    lcd.print(F("LISTA DE EVENTOS   "));
    
    lcd.setCursor(0, 1);
    lcd_subrutina_printFlecha(lcd_index_2 == 2);
    lcd.print(F("ULTIMO EVENTO      "));

    lcd_clearLine(2);
    lcd_clearLine(3);
}

void lcd_subrutina_menuControlManual()
{
    lcd_subrutina_printFlecha(lcd_index_2 == 1);
    lcd.print(F("EXTRACTOR:    "));
    lcd_subrutina_displayONOFF(SALIDA_EXTRACTOR);
    
    lcd.setCursor(0, 1);
    lcd_subrutina_printFlecha(lcd_index_2 == 2);
    lcd.print(F("CALEFACTOR:   "));
    lcd_subrutina_displayONOFF(SALIDA_CALEFACTOR);
    
    lcd.setCursor(0, 2);
    lcd_subrutina_printFlecha(lcd_index_2 == 3);
    lcd.print(F("SIST. RIEGO:  "));
    lcd_subrutina_displayONOFF(SALIDA_REGADOR);

    lcd.setCursor(0, 3);
    lcd_subrutina_printFlecha(lcd_index_2 == 4);
    lcd.print(F("ILUMINACION:  "));
    sprintf(lcdBuffer, "%3u%% ", POTENCIA_LUCES);
    lcd.print(lcdBuffer);
}

void lcd_subrutina_menuPrincipal()
{
    lcd_subrutina_printFlecha(lcd_index_1 == 0);
    lcd.print(F("INFORMACION        "));

    lcd.setCursor(0, 1);
    lcd_subrutina_printFlecha(lcd_index_1 == 1);
    lcd.print(F("MODO: "));
    lcd_subrutina_printModo();

    lcd.setCursor(0, 2);
    lcd_subrutina_printFlecha(lcd_index_1 == 2);
    lcd.print(F("CONTROL MANUAL     "));

    lcd.setCursor(0, 3);
    lcd_subrutina_printFlecha(lcd_index_1 == 3);
    lcd.print(F("EVENTOS            "));
}