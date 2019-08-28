#include "header.h"


void control_HUMEDAD()
{
    if (HUMEDAD <= HUMEDAD_BAJA_TRIGGER && HUMEDAD_BAJA_ESTADO == 0)
    {
        HUMEDAD_BAJA_ESTADO = 1;
    }
    if (HUMEDAD >= HUMEDAD_BAJA_RELEASE && HUMEDAD_BAJA_ESTADO == 1)
    {
        HUMEDAD_BAJA_ESTADO = 0;
    }

    Serial.println(HUMEDAD_BAJA_ESTADO);
}