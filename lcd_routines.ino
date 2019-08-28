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
            
            lcd.setCursor(0, 3);
            lcd.print(F("                    "));
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

            lcd.setCursor(0, 3);
            lcd.print(F("                    "));
            break;
        }
        break;
    }
}