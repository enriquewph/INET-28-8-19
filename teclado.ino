#include "header.h"

#define FILAS 4
#define COLUMNAS 4
char keys[FILAS][COLUMNAS] = {
    {'1', '2', '3', TECLA_ARRIBA},
    {'4', '5', '6', TECLA_ENTER},
    {'7', '8', '9', TECLA_VOLVER},
    {'#', '0', '*', TECLA_ABAJO}};
byte rowPins[FILAS] = {PIN_TECLADO_FILA_1, PIN_TECLADO_FILA_2, PIN_TECLADO_FILA_3, PIN_TECLADO_FILA_4};
byte colPins[COLUMNAS] = {PIN_TECLADO_COLUMNA_1, PIN_TECLADO_COLUMNA_2, PIN_TECLADO_COLUMNA_3, PIN_TECLADO_COLUMNA_4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, FILAS, COLUMNAS);

void teclado_update()
{
    TECLA_PRESIONADA = keypad.getKey();

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
            }
        break;
    case 2:
        switch (lcd_index_2)
        {
        case 0:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_1++;
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
            break;
        case 2:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;
            break;
        case 3:
            if (TECLA_PRESIONADA == TECLA_ABAJO)
                lcd_index_2++;
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;
            break;
        case 4:
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;
            break;
        }
        break;
    case 3:
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
                lcd_index_2 = 0;
            break;
        case 2:
            if (TECLA_PRESIONADA == TECLA_ARRIBA)
                lcd_index_2--;
            if (TECLA_PRESIONADA == TECLA_VOLVER)
                lcd_index_2 = 0;
            break;
        }
        break;
    }
}