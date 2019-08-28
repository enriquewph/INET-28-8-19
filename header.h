#ifndef header_h
#define header_h

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TIMER_ENTRADAS_TIEMPO 1000

#define PIN_LM35 A0
#define PIN_HUMEDAD A1
#define PIN_LDR A2

#define PIN_RELAY_MOTOR 3
#define PIN_RELAY_CALEFACTOR 4
#define PIN_RELAY_RIEGO 5
#define PIN_DIMMER_LUZ 6


//Variables de funcionamiento:

uint8_t FUNCIONAMIENTO_MODO = MODO_AUTOMATICO;
#define MODO_MANUAL 0
#define MODO_AUTOMATICO 1

uint8_t FUNCIONAMIENTO_TEMP;
#define MODO_TEMP_STANDBY 0
#define MODO_TEMP_CALENTANDO 1
#define MODO_TEMP_ENFRIANDO 2

uint8_t FUNCIONAMIENTO_REGADO;
#define MODO_REGADO_APAGADO 0
#define MODO_REGADO_ENCENDIDO 1

//Entradas / salidas:

float TEMPERATURA;
uint8_t HUMEDAD;
uint16_t LUX;
uint8_t POTENCIA_LUCES;

#endif