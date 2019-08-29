#ifndef header_h
#define header_h

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
char lcdBuffer[32];

#define TIMER_ENTRADAS_TIEMPO 1000

#define PIN_LM35 A2
#define PIN_HUMEDAD A1
#define PIN_LDR A0


#define PIN_RELAY_MOTOR 3
#define PIN_RELAY_CALEFACTOR 4
#define PIN_RELAY_RIEGO 5
#define PIN_DIMMER_LUZ 6

#define PIN_TECLADO_COLUMNA_1 22
#define PIN_TECLADO_COLUMNA_2 23
#define PIN_TECLADO_COLUMNA_3 24
#define PIN_TECLADO_COLUMNA_4 25
#define PIN_TECLADO_FILA_1 26
#define PIN_TECLADO_FILA_2 27
#define PIN_TECLADO_FILA_3 28
#define PIN_TECLADO_FILA_4 29

//Variables de funcionamiento:

#define MODO_MANUAL 0
#define MODO_AUTOMATICO 1
uint8_t FUNCIONAMIENTO_MODO = MODO_AUTOMATICO;

#define MODO_TEMP_STANDBY 0
#define MODO_TEMP_CALENTANDO 1
#define MODO_TEMP_ENFRIANDO 2
uint8_t FUNCIONAMIENTO_TEMP; //el control manual debe hacer un override a esto.

#define MODO_REGADO_APAGADO 0
#define MODO_REGADO_ENCENDIDO 1
uint8_t FUNCIONAMIENTO_REGADO;



//lcd_routines:
uint8_t lcd_index_1 = 2;
uint8_t lcd_index_2 = 4;
uint8_t lcd_index_3 = 0;

char TECLA_PRESIONADA = NO_KEY;
#define TECLA_ARRIBA 'A'
#define TECLA_ENTER 'B'
#define TECLA_VOLVER 'C'
#define TECLA_ABAJO 'D'

//Entradas / salidas:

float TEMPERATURA;
uint8_t HUMEDAD;
uint16_t LUX;
/*
Direct sunlight is approximately 32,000 to 100,000 lux. 
Full-sun plants usually need at least 25,000 to 50,000 lux to do well, 
with increased productivity occurring when light levels are near full sunlight.
*/

uint8_t SALIDA_EXTRACTOR;
uint8_t SALIDA_CALEFACTOR;
uint8_t SALIDA_REGADOR;
uint8_t POTENCIA_LUCES;

#define TEMPERATURA_TRIGGER 24.00
#define TEMPERATURA_RELEASE 28.00
bool TEMPERATURA_BAJA_ESTADO;
bool TEMPERATURA_ALTA_ESTADO;

#define HUMEDAD_TRIGGER 50
#define HUMEDAD_RELEASE 70
bool HUMEDAD_ESTADO;

#endif
