#include "header.h"

void teclado_update()
{
    TECLA_PRESIONADA = keypad.getKey();
    if (TECLA_PRESIONADA != NO_KEY)
        timeout_screensaver = millis();
    switch (lcd_index_1)
    {
    case 0:
        switch (lcd_index_2)
        {
        case 0:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_1++;
            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_index_2++;
            break;
        case 1:
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;
            break;
        }
        break;
    case 1: //SELECTOR DE MODO
        if (TECLA_PRESIONADA == TECLA_ABAJO)
            lcd_index_1++;
        if (TECLA_PRESIONADA == TECLA_ARRIBA)
            lcd_index_1--;
        if (TECLA_PRESIONADA == TECLA_ENTER)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
                FUNCIONAMIENTO_MODO = MODO_MANUAL;
            else
                FUNCIONAMIENTO_MODO = MODO_AUTOMATICO;
            guardar_variables();
        }
        break;
    case 2:
        switch (lcd_index_2)
        {
        case 0:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_1 = 5;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_1--;
            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_index_2 = 1;
            break;
        case 1:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER && FUNCIONAMIENTO_MODO == MODO_MANUAL)
            {
                if (SALIDA_EXTRACTOR == 0)
                    SALIDA_EXTRACTOR = 1;
                else
                    SALIDA_EXTRACTOR = 0;
                guardar_variables();
            }
            break;
        case 2:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER && FUNCIONAMIENTO_MODO == MODO_MANUAL)
            {
                if (SALIDA_CALEFACTOR == 0)
                    SALIDA_CALEFACTOR = 1;
                else
                    SALIDA_CALEFACTOR = 0;
                guardar_variables();
            }
            break;
        case 3:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER && FUNCIONAMIENTO_MODO == MODO_MANUAL)
            {
                if (SALIDA_REGADOR == 0)
                    SALIDA_REGADOR = 1;
                else
                    SALIDA_REGADOR = 0;
                guardar_variables();
            }
            break;
        case 4:
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER && FUNCIONAMIENTO_MODO == MODO_MANUAL)
                lcd_editando = 1;
            break;
        }
        break;
    case 5:
        switch (lcd_index_2)
        {
        case 0:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_1++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_1 = 2;
            if (TECLA_PRESIONADA == TECLA_ENTER)
            {
                lcd_index_2 = 1;
                lcd_mostrarevento_id = evento_ultimoIndice;
            }
            break;
        case 1:
            if (!lcd_mostrarevento)
            {
                if (TECLA_PRESIONADA == TECLA_ABAJO)
                    lcd_index_2++;
            }
            else
            {
                if (TECLA_PRESIONADA == TECLA_ABAJO)
                {
                    if (lcd_mostrarevento_id > 0)
                        if (evento_lista[lcd_mostrarevento_id - 1].codigo_evento != EV_NINGUNO) //verificar si el evento siguiente existe
                            lcd_mostrarevento_id--;
                    else
                        lcd_mostrarevento_id = EVENTOS_MEMORIA;
                }

                if (TECLA_PRESIONADA == TECLA_ARRIBA)
                {
                    if (lcd_mostrarevento_id < EVENTOS_MEMORIA)
                        if (evento_lista[lcd_mostrarevento_id + 1].codigo_evento != EV_NINGUNO) //verificar si el evento siguiente existe
                            lcd_mostrarevento_id++;
                    else
                        lcd_mostrarevento_id = 0; //se sobrepaso, volver a 0...
                }
            }

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_mostrarevento)
                    lcd_mostrarevento = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_mostrarevento = 1;
            break;
        case 2:
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
            {
                lcd_index_2 = 1;
                lcd_mostrarevento_id = evento_ultimoIndice;
            }
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_mostrarevento)
                    lcd_mostrarevento = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_mostrarevento = 1;
            break;
        }
        break;
    case 6:
        switch (lcd_index_2)
        {
        case 0:
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_1--;
            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_index_2 = 1;
            break;
        case 1:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_editando = 1;
            break;
        case 2:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_editando = 1;
            break;
        case 3:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_editando = 1;
            break;
        case 4:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_editando = 1;
            break;
        case 5:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_editando = 1;
            break;
        case 6:
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;

            if (TECLA_PRESIONADA == TECLA_VOLVER)
                if (lcd_editando)
                    lcd_editando = 0;
                else
                    lcd_index_2 = 0;

            if (TECLA_PRESIONADA == TECLA_ENTER)
                lcd_editando = 1;
            break;
        }
        break;
    }
}