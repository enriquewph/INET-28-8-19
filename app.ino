#include "header.h"
#include <EEPROM.h>
/*
ITS VILLADA - INET - GRUPO 7 - 28/08/2019
INTEGRANTES:
- Davalle, Lucas
- Philippeaux, Enrique
*/

void setup()
{
    //inicializar p. serie, eeprom y I/O
    Serial.begin(9600);
    EEPROM.begin();

    pinMode(PIN_LM35, INPUT);
    pinMode(PIN_HUMEDAD, INPUT);
    pinMode(PIN_LDR, INPUT);

    pinMode(PIN_RELAY_MOTOR, OUTPUT);
    pinMode(PIN_RELAY_CALEFACTOR, OUTPUT);
    pinMode(PIN_RELAY_RIEGO, OUTPUT);
    pinMode(PIN_DIMMER_LUZ, OUTPUT);

    //cargar variables de EEPROM y iniciar libreria de LCD
    cargar_variables();
    lcd_subrutina_init();

    //iniciar timers a millis
    timer_entradas = millis();
    timeout_screensaver = millis();
}

void loop()
{
    if (millis() >= timer_entradas + TIMER_ENTRADAS_TIEMPO)
    {
        IO_rutina();
        timer_entradas = millis();
    }

    //Procesar eventos, actualizar LCD, y leer teclado.
    lcd_eventHandler();
}

void IO_rutina()
{
    //leer sensores
    HUMEDAD = HUM_leer();
    TEMPERATURA = TEMP_leer();
    LUX = LDR_leer();

    //verificar si tienen errores...
    verificarSensoresPorErrores();

    //actualizar variables de salidas si se esta en modo automatico.
    if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO) //solo si se esta en automatico procesar y actualizar salidas.
    {
        control_HUMEDAD();
        control_TEMP();

        if (FUNCIONAMIENTO_TEMP == MODO_TEMP_ENFRIANDO)
            SALIDA_EXTRACTOR = 1;
        else
            SALIDA_EXTRACTOR = 0;
        if (FUNCIONAMIENTO_TEMP == MODO_TEMP_CALENTANDO)
            SALIDA_CALEFACTOR = 1;
        else
            SALIDA_CALEFACTOR = 0;
        if (FUNCIONAMIENTO_REGADO == MODO_REGADO_ENCENDIDO)
            SALIDA_REGADOR = 1;
        else
            SALIDA_REGADOR = 0;

        if (LUX <= LUX_BAJO)
            POTENCIA_LUCES = 100;
        if (LUX >= LUX_ALTO)
            POTENCIA_LUCES = 0;
        if (LUX >= LUX_BAJO && LUX <= LUX_ALTO)
        {
            POTENCIA_LUCES = 100 - pwmmap(LUX, LUX_BAJO, LUX_ALTO, 0, 100); //a mayor luz detectada, menor pwm
        }
    }

    //mandar las variables de salidas a las salidas reales.
    setearSalidas();
}

//verificamos si hay errores y los mostramos en el display 
void verificarSensoresPorErrores() 
{
    EV_ERROR_PRESENTE = 0;
    if (HUMEDAD == 0 || HUMEDAD > 100)
    {
        if (!EV_ERROR_SENSOR_HUMEDAD_ACTIVADO)
        {
            lcd_createEvent(EV_ERROR_SENSOR_HUMEDAD, EV_ERROR);
            EV_ERROR_SENSOR_HUMEDAD_ACTIVADO = 1;
        }
        if (millis() >= EV_ERROR_ULTIMO_PARPADEO + EV_ERROR_TIEMPO_PARPADEO)
        {
            EV_ERROR_SENSOR_HUMEDAD_ACTIVADO = 0;
            EV_ERROR_ULTIMO_PARPADEO = millis();
        }
    }
    else
    {
        EV_ERROR_SENSOR_HUMEDAD_ACTIVADO = 0;
    }

    if (TEMPERATURA > 100)
    {
        if (!EV_ERROR_SENSOR_TEMPERATURA_ACTIVADO)
        {
            lcd_createEvent(EV_ERROR_SENSOR_TEMPERATURA, EV_ERROR);
            EV_ERROR_SENSOR_TEMPERATURA_ACTIVADO = 1;
        }
        if (millis() >= EV_ERROR_ULTIMO_PARPADEO + EV_ERROR_TIEMPO_PARPADEO)
        {
            EV_ERROR_SENSOR_TEMPERATURA_ACTIVADO = 0;
            EV_ERROR_ULTIMO_PARPADEO = millis();
        }
    }
    else
    {
        EV_ERROR_SENSOR_TEMPERATURA_ACTIVADO = 0;
    }

    if (LUX == 0 && !EV_ERROR_SENSOR_LDR_ACTIVADO)
    {
        if (!EV_ERROR_SENSOR_LDR_ACTIVADO)
        {
            lcd_createEvent(EV_ERROR_SENSOR_LDR, EV_ERROR);
            EV_ERROR_SENSOR_LDR_ACTIVADO = 1;
        }
        if (millis() >= EV_ERROR_ULTIMO_PARPADEO + EV_ERROR_TIEMPO_PARPADEO)
        {
            EV_ERROR_SENSOR_LDR_ACTIVADO = 0;
            EV_ERROR_ULTIMO_PARPADEO = millis();
        }
    }
    else
    {
        EV_ERROR_SENSOR_LDR_ACTIVADO = 0;
    }
}