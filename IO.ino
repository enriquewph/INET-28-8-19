#include "header.h"

float TEMP_leer()
{
    Serial.println(analogRead(PIN_LM35));
    float temp =  (analogRead(PIN_LM35)*5*100/1023) ;
    Serial.println(temp);
    return (temp);
   
}
float HUM_leer()
{
    float humedad = (analogRead(PIN_HUMEDAD) / 10.24);
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

    float B[5];
    for (byte i=0; i < 5; i++)
    {
        B[i] = a;
        
    }
    float y = 0;
    float suma = 0;
    for (byte i = 0; i < 5; i++)
    {
        suma += B[i]; 
    }
    Serial.println(suma);
    y = suma / 5;

    Serial.println("Temperatura: " + String(y));

    float b = HUM_leer();
    Serial.println("humedad: " + String(b));

    uint16_t c = LDR_leer();
    Serial.println("lux: " + String(c));
}