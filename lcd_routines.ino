#include "header.h"

/*
	INFORMACION (screensaver si no se tocan cosas x 10 seg).
	MODO: [MANUAL/AUTOMATICO]
	CONTROL MANUAL
	    EXTRACTOR [ON/OFF] (solo se cambian si esta en manual...)
	    CALEFACTOR [ON/OFF]
	    RIEGO[ON/OFF]
	    ILUMINACION[0-100%]
    ...

    ...
	EVENTOS
	    LISTA DE EVENTOS
	    ULTIMO EVENTO
    PARAMETROS
        --------------------
               MIN     MAX  
        TEMP  00.00C  00.00C
        HUM    000%    000% 
        LUX      00000lux

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

    if (millis() >= timeout_screensaver + TIMEOUT_TECLADO) //timeout
    {
        lcd_index_1 = 0;
        lcd_index_2 = 1;
        timeout_screensaver = millis();
    }


    if (lcd_index_2 == 0)
        lcd_subrutina_menuPrincipal();
    if (lcd_index_1 == 0 && lcd_index_2 == 1)
        lcd_subrutina_screenInfo();
    if (lcd_index_1 == 2 && lcd_index_2 > 0)
        lcd_subrutina_menuControlManual();
    if (lcd_index_1 == 5 && lcd_index_2 > 0)
        lcd_subrutina_menuEventos();
    if (lcd_index_1 == 6 && lcd_index_2 > 0)
        lcd_subrutina_menuParametros();
}

void lcd_subrutina_menuParametros()
{
    /*      --------------------
               MIN     MAX  
        TEMP >00.00C >00.00C
        HUM   >000%   >000% 
        LUX      >00000lx       
*/

    lcd.print(F("       MIN     MAX  "));

    lcd.setCursor(0, 1);
    lcd.print(F("TEMP "));
    lcd_subrutina_printFlecha(lcd_index_2 == 1);
    lcd_subrutina_printTemp(TEMPERATURA_BAJA_TRIGGER);
    lcd.print(" ");
    lcd_subrutina_printFlecha(lcd_index_2 == 2);
    lcd_subrutina_printTemp(TEMPERATURA_ALTA_TRIGGER);

    lcd.setCursor(0, 2);
    lcd.print(F("HUM   "));
    lcd_subrutina_printFlecha(lcd_index_2 == 3);
    lcd_subrutina_printHumedad(HUMEDAD_TRIGGER);
    lcd.print("   ");
    lcd_subrutina_printFlecha(lcd_index_2 == 4);
    lcd_subrutina_printHumedad(HUMEDAD_RELEASE);
    lcd.print(" ");

    lcd.setCursor(0, 3);
    lcd.print(F("LUX      "));
    lcd_subrutina_printFlecha(lcd_index_2 == 5);
    lcd_subrutina_printLux(LUX_TARGET);
    lcd.print(F("       "));
    
    if (lcd_editando)
    {
        switch (lcd_index_2)
        {
        case 1:
            TEMPERATURA_BAJA_TRIGGER = lcd_subrutina_editarVar2digitos(TEMPERATURA_BAJA_TRIGGER, 0, TEMPERATURA_ALTA_TRIGGER, 6, 1);
            guardar_variables();
            break;
        case 2:
            TEMPERATURA_ALTA_TRIGGER = lcd_subrutina_editarVar2digitos(TEMPERATURA_ALTA_TRIGGER, TEMPERATURA_BAJA_TRIGGER, 100, 14, 1);
            guardar_variables();
            break;
        case 3:
            HUMEDAD_TRIGGER = lcd_subrutina_editarVar3digitos(HUMEDAD_TRIGGER, 0, HUMEDAD_RELEASE, 7, 2);
            guardar_variables();
            break;
        case 4:
            HUMEDAD_RELEASE = lcd_subrutina_editarVar3digitos(HUMEDAD_RELEASE, HUMEDAD_TRIGGER, 100, 15, 2); //el max no puede ser menor que el minimo...
            guardar_variables();
            break;
        case 5:
            LUX_TARGET = lcd_subrutina_editarVar5digitos(LUX_TARGET, 0, 50000, 10, 3);
            guardar_variables();
            break;
        }
    }
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

    if (lcd_editando)
        POTENCIA_LUCES = lcd_subrutina_editarVar3digitos(POTENCIA_LUCES, 0, 100, 15, 3);
}

void lcd_subrutina_menuPrincipal()
{
    if (lcd_index_1 <= 3)
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
        lcd.print(F(" ...                "));
    }
    else //siguiente pagina
    {
        lcd.print(F(" ...                "));

        lcd.setCursor(0, 1);
        lcd_subrutina_printFlecha(lcd_index_1 == 5);
        lcd.print(F("EVENTOS            "));

        lcd.setCursor(0, 2);
        lcd_subrutina_printFlecha(lcd_index_1 == 6);
        lcd.print(F("PARAMETROS         "));

        lcd_clearLine(3);
    }
}

float lcd_subrutina_editarVar2digitos(float variable, float limite_inferior, float limite_superior, uint8_t cur_x, uint8_t cur_y)
{
    lcd.setCursor(cur_x, cur_y);
    lcd.blink();

    uint8_t cifra = 0; //0 centena, 1 decena, 2 unidad

    char digitos[3];
    uint8_t in_var = variable;
    sprintf(digitos, "%02u\0", in_var);

    while (lcd_editando)
    {
        lcd.setCursor(cur_x, cur_y);
        sprintf(lcdBuffer, "%s", digitos);
        lcd.print(lcdBuffer);

        lcd.setCursor(cur_x + cifra, cur_y);

        char entrada = keypad.waitForKey();

        switch (entrada)
        {
        case '#':
            //no hacer nada...
            break;
        case '*':
            //no hacer nada...
            break;
        case TECLA_ARRIBA:
            //no hacer nada...
            break;
        case TECLA_ABAJO:
            //no hacer nada...
            break;

        case TECLA_ENTER: //terminado
            lcd_editando = 0;
            break;

        case TECLA_VOLVER: //volver cifra anterior

            if (cifra > 0)
                cifra--;
            else
                cifra = 1;
            break;

        default: //se presiono algun numero.......
            digitos[cifra] = entrada;

            if (cifra < 1)
                cifra++;
            else
                cifra = 0;
            break;
        }
    }

    lcd.noBlink();

    String string_editado = digitos;
    float numero_editado = (float) string_editado.toInt();

    if (numero_editado <= limite_superior && numero_editado >= limite_inferior)
        return (numero_editado);
    else
        return variable;
}


uint8_t lcd_subrutina_editarVar3digitos(uint8_t variable, uint8_t limite_inferior, uint8_t limite_superior, uint8_t cur_x, uint8_t cur_y)
{
    lcd.setCursor(cur_x, cur_y);
    lcd.blink();

    uint8_t cifra = 0; //0 centena, 1 decena, 2 unidad

    char digitos[4];
    sprintf(digitos, "%03u\0", variable);

    while (lcd_editando)
    {
        lcd.setCursor(cur_x, cur_y);
        sprintf(lcdBuffer, "%s", digitos);
        lcd.print(lcdBuffer);

        lcd.setCursor(cur_x + cifra, cur_y);

        char entrada = keypad.waitForKey();

        switch (entrada)
        {
        case '#':
            //no hacer nada...
            break;
        case '*':
            //no hacer nada...
            break;
        case TECLA_ARRIBA:
            //no hacer nada...
            break;
        case TECLA_ABAJO:
            //no hacer nada...
            break;

        case TECLA_ENTER: //terminado
            lcd_editando = 0;
            break;

        case TECLA_VOLVER: //volver cifra anterior

            if (cifra > 0)
                cifra--;
            else
                cifra = 2;
            break;

        default: //se presiono algun numero.......
            digitos[cifra] = entrada;

            if (cifra < 2)
                cifra++;
            else
                cifra = 0;
            break;
        }
    }

    lcd.noBlink();

    String string_editado = digitos;
    uint8_t numero_editado = string_editado.toInt();

    if (numero_editado <= limite_superior && numero_editado >= limite_inferior)
        return (numero_editado);
    else
        return variable;
}




uint16_t lcd_subrutina_editarVar5digitos(uint16_t variable, uint16_t limite_inferior, uint16_t limite_superior, uint8_t cur_x, uint8_t cur_y)
{
    lcd.setCursor(cur_x, cur_y);
    lcd.blink();

    uint8_t cifra = 0; //0 centena, 1 decena, 2 unidad

    char digitos[6];
    sprintf(digitos, "%05u\0", variable);

    while (lcd_editando)
    {
        lcd.setCursor(cur_x, cur_y);
        sprintf(lcdBuffer, "%s", digitos);
        lcd.print(lcdBuffer);

        lcd.setCursor(cur_x + cifra, cur_y);

        char entrada = keypad.waitForKey();

        switch (entrada)
        {
        case '#':
            //no hacer nada...
            break;
        case '*':
            //no hacer nada...
            break;
        case TECLA_ARRIBA:
            //no hacer nada...
            break;
        case TECLA_ABAJO:
            //no hacer nada...
            break;

        case TECLA_ENTER: //terminado
            lcd_editando = 0;
            break;

        case TECLA_VOLVER: //volver cifra anterior

            if (cifra > 0)
                cifra--;
            else
                cifra = 4;
            break;

        default: //se presiono algun numero.......
            digitos[cifra] = entrada;

            if (cifra < 4)
                cifra++;
            else
                cifra = 0;
            break;
        }
    }

    lcd.noBlink();

    String string_editado = digitos;
    uint16_t numero_editado = string_editado.toInt();

    if (numero_editado <= limite_superior && numero_editado >= limite_inferior)
        return (numero_editado);
    else
        return variable;
}