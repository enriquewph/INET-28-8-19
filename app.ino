#include "header.h"
/*
ITS VILLADA - INET - GRUPO 7 - 28/08/2019
INTEGRANTES:
- Davalle, Lucas
- Philippeaux, Enrique
*/


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  float a =TEMP_leer();
  Serial.println("Temperatura: " + String(a));

  float b =HUM_leer();
  Serial.println("humedad: " + String(b));

  uint16_t c =LDR_leer();
  Serial.println("lux: " + String(c));

  delay(2000);
}
