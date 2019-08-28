#include "header.h"

void control_TEMP()
{
    int salida ;
 
    if (HUMEDAD <= HUMEDAD_BAJA_TRIGGER)
    {
        //digitalWrite(PIN_RELAY_CALEFACTOR, 1);
        salida = 1;
    }
    if (  HUMEDAD >= HUMEDAD_BAJA_RELEASE)
    {
        //digitalWrite(PIN_RELAY_CALEFACTOR, 1);
        salida = 0;
    }

    Serial.println(salida);
}