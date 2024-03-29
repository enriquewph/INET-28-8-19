#include "header.h"
#include <EEPROM.h>

void cargar_variables()
{
    FUNCIONAMIENTO_MODO = EEPROM.get(EEPROM_ADDRESS_FUNCIONAMIENTO_MODO, FUNCIONAMIENTO_MODO);
    TEMPERATURA_BAJA_TRIGGER = EEPROM.get(EEPROM_ADDRESS_TEMPERATURA_BAJA_TRIGGER, TEMPERATURA_BAJA_TRIGGER);
    TEMPERATURA_ALTA_TRIGGER = EEPROM.get(EEPROM_ADDRESS_TEMPERATURA_ALTA_TRIGGER, TEMPERATURA_ALTA_TRIGGER);
    HUMEDAD_TRIGGER = EEPROM.get(EEPROM_ADDRESS_HUMEDAD_TRIGGER, HUMEDAD_TRIGGER);
    HUMEDAD_RELEASE = EEPROM.get(EEPROM_ADDRESS_HUMEDAD_RELEASE, HUMEDAD_RELEASE);
    LUX_BAJO = EEPROM.get(EEPROM_ADDRESS_LUX_BAJO, LUX_BAJO);
    LUX_ALTO = EEPROM.get(EEPROM_ADDRESS_LUX_ALTO, LUX_ALTO);

    //actualizar variables para schmitt triggers.
    TEMPERATURA_UPDATE_RELEASE(); //incluir que esta funcion se ejecute cuando se cargen variables de eeprom o se editen x menu.
}

void guardar_variables() //ejecutado cuando se cambia alguna variable x software
{
    EEPROM.put(EEPROM_ADDRESS_FUNCIONAMIENTO_MODO, FUNCIONAMIENTO_MODO);
    EEPROM.put(EEPROM_ADDRESS_TEMPERATURA_BAJA_TRIGGER, TEMPERATURA_BAJA_TRIGGER);
    EEPROM.put(EEPROM_ADDRESS_TEMPERATURA_ALTA_TRIGGER, TEMPERATURA_ALTA_TRIGGER);
    EEPROM.put(EEPROM_ADDRESS_HUMEDAD_TRIGGER, HUMEDAD_TRIGGER);
    EEPROM.put(EEPROM_ADDRESS_HUMEDAD_RELEASE, HUMEDAD_RELEASE);
    EEPROM.put(EEPROM_ADDRESS_LUX_BAJO, LUX_BAJO);
    EEPROM.put(EEPROM_ADDRESS_LUX_ALTO, LUX_ALTO);

    //actualizar variables para schmitt triggers.
    TEMPERATURA_UPDATE_RELEASE(); //incluir que esta funcion se ejecute cuando se cargen variables de eeprom o se editen x menu.
    timeout_screensaver = millis();
}