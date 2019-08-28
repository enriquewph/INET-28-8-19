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

//Variables de funcionamiento:

#define MODO_MANUAL 0
#define MODO_AUTOMATICO 1
uint8_t FUNCIONAMIENTO_MODO = MODO_AUTOMATICO;

#define MODO_TEMP_STANDBY 0
#define MODO_TEMP_CALENTANDO 1
#define MODO_TEMP_ENFRIANDO 2
uint8_t FUNCIONAMIENTO_TEMP;

#define MODO_REGADO_APAGADO 0
#define MODO_REGADO_ENCENDIDO 1
uint8_t FUNCIONAMIENTO_REGADO;


//lcd_routines:
uint8_t lcd_index_1 = 0;
uint8_t lcd_index_2 = 1;
uint8_t lcd_index_3 = 0;

//Entradas / salidas:

float TEMPERATURA;
uint8_t HUMEDAD;
uint16_t LUX;
uint8_t POTENCIA_LUCES;

float TEMPERATURA_BAJA_TRIGGER;
float TEMPERATURA_BAJA_RELEASE;
bool TEMPERATURA_BAJA_ESTADO;
float TEMPERATURA_ALTA_TRIGGER;
float TEMPERATURA_ALTA_RELEASE;
bool TEMPERATURA_ALTA_ESTADO;

float HUMEDAD_BAJA_TRIGGER=50;
float HUMEDAD_BAJA_RELEASE=70;
bool HUMEDAD_BAJA_ESTADO;

#endif
