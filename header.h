#ifndef header_h
#define header_h

//Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

//Inicializacion LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);
char lcdBuffer[32];

//Definiciones de pines

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
uint8_t FUNCIONAMIENTO_MODO;

#define MODO_TEMP_STANDBY 0
#define MODO_TEMP_CALENTANDO 1
#define MODO_TEMP_ENFRIANDO 2
uint8_t FUNCIONAMIENTO_TEMP; //el control manual debe hacer un override a esto.

#define MODO_REGADO_APAGADO 0
#define MODO_REGADO_ENCENDIDO 1
uint8_t FUNCIONAMIENTO_REGADO;

//Variables de tiempo:
uint32_t timer_entradas;
uint32_t timeout_screensaver;

#define TIMER_ENTRADAS_TIEMPO 1000
#define TIMEOUT_TECLADO 10000 //milisegundos sin apretar nada para que la pantalla vaya a info.

//Cosas de interfaz:
uint8_t lcd_index_1 = 0;
uint8_t lcd_index_2 = 1;

bool lcd_editando = 0;

char TECLA_PRESIONADA = NO_KEY;

#define TECLA_ARRIBA 'A'
#define TECLA_ENTER 'B'
#define TECLA_VOLVER 'C'
#define TECLA_ABAJO 'D'

//teclado.ino
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

//Entradas / salidas:

float TEMPERATURA;
uint8_t HUMEDAD;
uint16_t LUX;

#define LM35_CORRECCION 0.0f

uint8_t SALIDA_EXTRACTOR;
uint8_t SALIDA_CALEFACTOR;
uint8_t SALIDA_REGADOR;
uint8_t POTENCIA_LUCES;

bool TEMPERATURA_BAJA_ESTADO;
float TEMPERATURA_BAJA_TRIGGER;

bool TEMPERATURA_ALTA_ESTADO;
float TEMPERATURA_ALTA_TRIGGER;

float TEMPERATURA_RELEASE; //calculado con funcion: TEMPERATURA_UPDATE_RELEASE();

bool HUMEDAD_ESTADO;
uint8_t HUMEDAD_TRIGGER;
uint8_t HUMEDAD_RELEASE;

uint16_t LUX_BAJO;
uint16_t LUX_ALTO;

//EVENTOS

//LISTA DE CODIGOS DE EVENTOS
uint8_t ultimo_evento;
#define EV_NINGUNO 0

#define EV_TEMP_ALTA 1
#define EV_TEMP_BAJA 2
#define EV_TEMP_ESTABILIZADA 3

#define EV_HUMEDAD_BAJA 4
#define EV_HUMEDAD_ALTA 5

#define EV_ERROR_SENSOR_HUMEDAD 6 //para 0% y > 100%
#define EV_ERROR_SENSOR_TEMPERATURA 7 //para mas de 100ºC
#define EV_ERROR_SENSOR_LDR 8 //para 0lux

#define EV_ERROR_TIEMPO_PARPADEO 8000

bool EV_ERROR_PRESENTE;
uint32_t EV_ERROR_ULTIMO_PARPADEO;
bool EV_ERROR_SENSOR_HUMEDAD_ACTIVADO = 0;
bool EV_ERROR_SENSOR_TEMPERATURA_ACTIVADO = 0;
bool EV_ERROR_SENSOR_LDR_ACTIVADO = 0;


//LISTA DE TIPOS DE EVENTOS
#define EV_INFORMACION 0
#define EV_ADVERTENCIA 1
#define EV_ERROR 2

//CANTIDAD DE EVENTOS A GUARDAR
#define EVENTOS_MEMORIA 5

#define TIEMPO_AVISO_LCD 2000 //tiempo en milisegundos a mostrar el aviso en el lcd.

typedef struct eventos
{
    uint8_t codigo_evento;  //EV_TYPE
    uint8_t tipo_evento;    //ERROR, ADVERTENCIA, INFORMACION
    uint32_t tiempo_evento; //millis()
} evento_t;

evento_t evento_ultimo;
evento_t evento_lista[EVENTOS_MEMORIA];
uint8_t evento_ultimoIndice = 0;

bool lcd_mostrarevento = 0;
uint8_t lcd_mostrarevento_id;

//EEPROM

#define EEPROM_ADDRESS_FUNCIONAMIENTO_MODO 0
#define EEPROM_ADDRESS_TEMPERATURA_BAJA_TRIGGER 1
#define EEPROM_ADDRESS_TEMPERATURA_ALTA_TRIGGER 10
#define EEPROM_ADDRESS_HUMEDAD_TRIGGER 20
#define EEPROM_ADDRESS_HUMEDAD_RELEASE 30
#define EEPROM_ADDRESS_LUX_BAJO 40
#define EEPROM_ADDRESS_LUX_ALTO 50

#endif
