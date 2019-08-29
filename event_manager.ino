#include "header.h"

void lcd_eventHandler()
{
    lcd.setCursor(0, 0);

    switch (evento_ultimo.codigo_evento)
    {
    case EV_NINGUNO: //No hay ningun evento, dejarla vacia q despues le mando para que muestre el menu desde aca.

        break;
    case EV_PRUEBA:
        if (millis() < evento_ultimo.tiempo_evento + 2000) //entiendase 2000 por el tiempo que muestra el mensaje (2000 miliSegundos)
        {
            lcd.print(F("INFORMACION:        "));   //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

            lcd.setCursor(0, 1);                    //Ir al segundo renglon
            lcd.print(F("ESTO ES UNA PRUEBA  "));   //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

            lcd.setCursor(0, 1);                    //Ir al tercer renglon
            lcd.print(F("TERCER RENGLON WACHO"));   //le agrege espacios hasta llegar al caracter numero 19 contando desde 0.

            lcd_clearLine(3);                       //borro el cuarto renglon, no hace falta setear el cursor antes.
        }
        else
        {
            evento_ultimo.codigo_evento = EV_NINGUNO; // Una vez transcurrido el tiempo, borrar el ultimo evento y volver a normalidad.
        }
        break;
    }
}

void lcd_createEvent(uint8_t codigo,uint8_t tipo)
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