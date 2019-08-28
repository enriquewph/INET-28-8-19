#include "header.h"

float TEMP_leer()
{
    float temp = (analogRead(PIN_LM35) * 5 * 100 / 1024);

    return (temp);
}
float HUM_leer()
{
    float humedad = analogRead(PIN_HUMEDAD);
    return (humedad);
}
uint16_t LDR_leer()
{
    const long A = 1000; //Resistencia en oscuridad en KΩ
    const int B = 15;    //Resistencia a la luz (10 Lux) en KΩ
    const int Rc = 10;   //Resistencia calibracion en KΩ

    int valor_ldr = analogRead(PIN_LDR);

    int ilum = ((long)valor_ldr * A * 10) / ((long)B * Rc * (1024 - valor_ldr)); //usar si LDR entre A0 y Vcc (como en el esquema anterior)
    return (ilum);
}

void IO_rutina()
{
    float a = TEMP_leer();
    Serial.println("Temperatura: " + String(a));

    float b = HUM_leer();
    Serial.println("humedad: " + String(b));

    uint16_t c = LDR_leer();
    Serial.println("lux: " + String(c));
}