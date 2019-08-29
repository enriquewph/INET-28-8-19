#include "header.h"

void control_HUMEDAD()
{
    if (HUMEDAD <= HUMEDAD_TRIGGER && HUMEDAD_ESTADO == 0)
    {
        HUMEDAD_ESTADO = 1;
    }
    if (HUMEDAD >= HUMEDAD_RELEASE && HUMEDAD_ESTADO == 1)
    {
        HUMEDAD_ESTADO = 0;
    }
    FUNCIONAMIENTO_REGADO = HUMEDAD_ESTADO;
    Serial.println("riego " + String(HUMEDAD_ESTADO));
}
void control_TEMP()
{
    if (TEMPERATURA <= TEMPERATURA_TRIGGER && TEMPERATURA_BAJA_ESTADO == 0)
    {
        TEMPERATURA_BAJA_ESTADO = 1;
        FUNCIONAMIENTO_TEMP = MODO_TEMP_CALENTANDO;
    }
    if (TEMPERATURA >= TEMPERATURA_RELEASE && TEMPERATURA_BAJA_ESTADO == 1)
    {

        TEMPERATURA_BAJA_ESTADO = 0;
        FUNCIONAMIENTO_TEMP = MODO_TEMP_STANDBY;
    }

    if (TEMPERATURA >= TEMPERATURA_TRIGGER && TEMPERATURA_ALTA_ESTADO == 0)
    {
        TEMPERATURA_ALTA_ESTADO = 1;
        FUNCIONAMIENTO_TEMP = MODO_TEMP_ENFRIANDO;
    }
    if (TEMPERATURA <= TEMPERATURA_RELEASE && TEMPERATURA_ALTA_ESTADO == 1)
    {

        TEMPERATURA_ALTA_ESTADO = 0;
        FUNCIONAMIENTO_TEMP = MODO_TEMP_STANDBY;
    }

    Serial.println("estado calefactor " + String(TEMPERATURA_BAJA_ESTADO));
    Serial.println("estado extractor " + String(TEMPERATURA_ALTA_ESTADO));
}