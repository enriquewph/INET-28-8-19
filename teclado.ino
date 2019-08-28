#include "header.h"

const byte FILAS = 4;    //CUATRO FILAS
const byte COLUMNAS = 4; //CUATRO COLUMNAS
char keys[FILAS][COLUMNAS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'#', '0', '*', 'D'}};
byte rowPins[FILAS] = {26, 27, 28, 29};
byte colPins[COLUMNAS] = {22, 23, 24, 25};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, FILAS, COLUMNAS);

void teclado_update()
{
    char key = keypad.getKey();

    if (key != NO_KEY)
    {
        Serial.println(key);
    }

    switch (key)
    {
    case 'A':
        if (lcd_index_1 > 0)
            lcd_index_1--;
        break;
    case 'D':
        if (lcd_index_1 < 4)
            lcd_index_1++;
        break;
    case 'B':
        if (lcd_index_2 > 0)
            lcd_index_2--;
        break;
    case 'C':
        if (lcd_index_2 < 4)
            lcd_index_2++;
        break;
    }
}