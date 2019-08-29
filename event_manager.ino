#include "header.h"

void lcd_eventHandler()
{
    lcd.setCursor(0, 0);

    switch (evento_ultimo.codigo_evento)
    {
    case EV_NINGUNO: //No hay ningun evento, dejarla vacia q despues le mando para que muestre el menu desde aca.
        lcd_menu_update();
        teclado_update();

        break;
    case EV_TEMP_ALTA:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_TEMP_ALTA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_TEMP_BAJA:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_TEMP_BAJA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_TEMP_ESTABILIZADA:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_TEMP_ESTABILIZADA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_HUMEDAD_BAJA:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_HUMEDAD_BAJA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_HUMEDAD_ALTA:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_HUMEDAD_ALTA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_ERROR_SENSOR_HUMEDAD:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_ERROR_SENSOR_HUMEDAD();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_ERROR_SENSOR_TEMPERATURA:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_ERROR_SENSOR_TEMPERATURA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_ERROR_SENSOR_LDR:
        if (FUNCIONAMIENTO_MODO == MODO_MANUAL)
            evento_ultimo.codigo_evento = EV_NINGUNO;
        if (millis() < evento_ultimo.tiempo_evento + TIEMPO_AVISO_LCD) //entiendase TIEMPO_AVISO_LCD por el tiempo que muestra el mensaje (TIEMPO_AVISO_LCD miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_ERROR_SENSOR_LDR();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    }
}

void lcd_createEvent(uint8_t codigo, uint8_t tipo)
{
    //cargar los datos del evento en la estructura.
    evento_ultimo.codigo_evento = codigo;
    evento_ultimo.tipo_evento = tipo;
    evento_ultimo.tiempo_evento = millis();
    ultimo_evento = codigo;

    evento_ultimoIndice = 0;
    evento_lista[evento_ultimoIndice] = evento_ultimo; //guardar el evento en la lista.

    


    if (evento_ultimoIndice < EVENTOS_MEMORIA)
        evento_ultimoIndice++;
    else
        evento_ultimoIndice = 0; //se sobrepaso, volver a 0...

    lcd_eventHandler();
}

void Serial_printEvent(evento_t evento_en_cuestion)
{
    String codigo_string;
    switch (evento_en_cuestion.codigo_evento)
    {
    case EV_NINGUNO:
        codigo_string = "NULL";
        break;
    case EV_TEMP_ALTA:
        codigo_string = "Temperatura maxima excedida, encendiendo ventilacion.";
        break;
    case EV_TEMP_BAJA:
        codigo_string = "Temperatura minima excedida, encendiendo calefaccion.";
        break;
    case EV_TEMP_ESTABILIZADA:
        codigo_string = "Temperatura estabilizada.";
        break;
    case EV_HUMEDAD_BAJA:
        codigo_string = "Humedad por debajo de limite, encendiendo regadores.";
        break;
    case EV_HUMEDAD_ALTA:
        codigo_string = "Humedad estabilizada.";
        break;
    }

    switch (evento_en_cuestion.tipo_evento);
}

void TEX_EV_TEMP_ALTA()
{
    lcd.print(F("AVISO:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("TEMPERATURA ALTA.   "));

    lcd.setCursor(0, 2);
    lcd.print(F("ENCENDIENDO         "));

    lcd.setCursor(0, 3);
    lcd.print(F("EXTRACTOR.          "));
}

void TEX_EV_TEMP_ESTABILIZADA()
{
    lcd.print(F("AVISO:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("TEMPERATURA         "));

    lcd.setCursor(0, 2);
    lcd.print(F("ESTABILIZADA        "));

    lcd_clearLine(3);
}

void TEX_EV_TEMP_BAJA()
{
    lcd.print(F("AVISO:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("TEMPERATURA BAJA.   "));

    lcd.setCursor(0, 2);
    lcd.print(F("ENCENDIENDO         "));

    lcd.setCursor(0, 3);
    lcd.print(F("CALEFACTOR.         "));
}

void TEX_EV_HUMEDAD_ALTA()
{
    lcd.print(F("AVISO:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("HUMEDAD ESTABILIZADA"));

    lcd.setCursor(0, 2);
    lcd.print(F("APAGANDO REGADORES. "));

    lcd_clearLine(3);
}
void TEX_EV_HUMEDAD_BAJA()
{
    lcd.print(F("AVISO:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("HUMEDAD BAJO LIMITE "));

    lcd.setCursor(0, 2);
    lcd.print(F("ENCENDIENDO         "));

    lcd.setCursor(0, 3);
    lcd.print(F("REGADORES.          "));
}

void TEX_EV_ERROR_SENSOR_TEMPERATURA()
{
    lcd.print(F("ERROR:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("ERROR EN SENSOR     "));

    lcd.setCursor(0, 2);
    lcd.print(F("DE TEMPERATURA      "));

    lcd_clearLine(3);
}

void TEX_EV_ERROR_SENSOR_HUMEDAD()
{
    lcd.print(F("ERROR:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("ERROR EN SENSOR     "));

    lcd.setCursor(0, 2);
    lcd.print(F("DE HUMEDAD          "));

    lcd_clearLine(3);
}

void TEX_EV_ERROR_SENSOR_LDR()
{
    lcd.print(F("ERROR:              "));

    lcd.setCursor(0, 1);
    lcd.print(F("ERROR EN SENSOR     "));

    lcd.setCursor(0, 2);
    lcd.print(F("DE LUZ AMBIENTE     "));

    lcd_clearLine(3);
}