#include "header.h"

float TEMP_leer()
{
    float temp = ADC_LEER_PROMEDIO(PIN_LM35, 20) * 0.44828;
    return (temp);
}

float HUM_leer()
{
    float humedad = (ADC_LEER_PROMEDIO(PIN_HUMEDAD, 20) / 10.23);
    return (humedad);
}

uint16_t LDR_leer()
{
    const long A = 1000; //Resistencia en oscuridad en KΩ
    const int B = 11;    //Resistencia a la luz (10 Lux) en KΩ
    const int Rc = 10;   //Resistencia calibracion en KΩ

    uint16_t valor_ldr = ADC_LEER_PROMEDIO(PIN_LDR, 20);

    uint16_t ilum = ((long)valor_ldr * A * 10) / ((long)B * Rc * (1024 - valor_ldr)); //usar si LDR entre A0 y Vcc (como en el esquema anterior)
    return (ilum);
}

uint16_t ADC_LEER_PROMEDIO(uint8_t pin, uint8_t mediciones)
{
    uint32_t adcReads = 0;

    for (uint8_t i = 0; i < mediciones; i++)
    {
        adcReads += analogRead(pin);
    }
    return (adcReads / mediciones);
}



