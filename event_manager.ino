#include "header.h"

void lcd_eventHandler()
{
    lcd.setCursor(0, 0);

    /*switch (evento_ultimo.codigo_evento)
    {
    case EV_NINGUNO: //No hay ningun evento, dejarla vacia q despues le mando para que muestre el menu desde aca.

        break;
    case EV_TEMP_ALTA:
        if (millis() < evento_ultimo.tiempo_evento + 1000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
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
        if (millis() < evento_ultimo.tiempo_evento + 1000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
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
    case EV_HUMEDAD_BAJA:
        if (millis() < evento_ultimo.tiempo_evento + 1000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
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
        if (millis() < evento_ultimo.tiempo_evento + 1000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
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
    case EV_LUZ_ALTA:
        if (millis() < evento_ultimo.tiempo_evento + 1000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_LUZ_ALTA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    case EV_LUZ_BAJA:
        if (millis() < evento_ultimo.tiempo_evento + 1000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
        {
            if (FUNCIONAMIENTO_MODO == MODO_AUTOMATICO)
            {
                TEX_EV_LUZ_BAJA();
            }
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    }*/
}

void lcd_createEvent(uint8_t codigo, uint8_t tipo)
{
    //cargar los datos del evento en la estructura.
    evento_ultimo.codigo_evento = codigo;
    evento_ultimo.tipo_evento = tipo;
    evento_ultimo.tiempo_evento = millis();

    evento_lista[evento_ultimoIndice] = evento_ultimo; //guardar el evento en la lista.

    if (evento_ultimoIndice < EVENTOS_MEMORIA)
        evento_ultimoIndice++;
    else
        evento_ultimoIndice = 0; //se sobrepaso, volver a 0...

    lcd_eventHandler();
}

void TEX_EV_TEMP_ALTA()
{
    lcd.setCursor(4, 0);
    lcd.print(F("INFORMACION:    ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(2, 1);                //Ir al segundo renglon
    lcd.print(F("TEMPERATURA ALTA  ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(1, 2);                  //Ir al tercer renglon
    lcd.print(F("PRENDIENDO EXTRATOR ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd_clearLine(3);
}
void TEX_EV_TEMP_BAJA()
{

    lcd.setCursor(2, 1);                //Ir al segundo renglon
    lcd.print(F("TEMPERATURA BAJA  ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(0, 2);                   //Ir al tercer renglon
    lcd.print(F("PRENDIENDO CALEFACTOR")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd_clearLine(3);
}
void TEX_EV_HUMEDAD_ALTA()
{

    lcd.setCursor(4, 1);              //Ir al segundo renglon
    lcd.print(F("HUMEDAD ALTA    ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(0, 2);                 //Ir al tercer renglon
    lcd.print(F("APAGANDO SIST.RIEGO")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd_clearLine(3);
}
void TEX_EV_HUMEDAD_BAJA()
{
    lcd.setCursor(4, 1);              //Ir al segundo renglon
    lcd.print(F("HUMEDAD BAJA    ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(0, 2);                   //Ir al tercer renglon
    lcd.print(F("PRENDIENDO SIST.RIEGO")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd_clearLine(3);
}
void TEX_EV_LUZ_ALTA()
{
    lcd.setCursor(6, 1);            //Ir al segundo renglon
    lcd.print(F("LUZ ALTA      ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(5, 2);                 //Ir al tercer renglon
    lcd.print(F("APAGANDO LUCES     ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd_clearLine(3);
}
void TEX_EV_LUZ_BAJA()
{
    lcd.setCursor(6, 1);            //Ir al segundo renglon
    lcd.print(F("LUZ BAJA      ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd.setCursor(2, 2);                //Ir al tercer renglon
    lcd.print(F("PRENDIENDO LUCES  ")); //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

    lcd_clearLine(3);
}
