/*
 *  39-geo
 *      Determinar la posicion geografica reportando
 *      APs que rodean y su intensidad de señal
 *
 *      Consultar: https://programarfacil.com/blog/arduino-blog/geolocalizacion-wifi-arduino-nodemcu/
 */

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif

#include <WifiLocation.h>

#include "wifi_ruts.h"

/*
 *  Constantes definidas en platformio.ini
 *      MY_SSID     WiFi a conectarse
 *      MY_PASS     Password del WiFi
 *      SERIAL_BAUD Baud Rate del puerto serie
 *      DEBUG_APS   Para debug, saca comentario
 *      APIKEY      Google API Key
 */

//  Creación de objetos

WifiLocation location(APIKEY);

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    connect_wifi(MY_SSID, MY_PASS);
    delay(2000);
    Serial.println("Trying to detect position");
    location_t loc = location.getGeoFromWiFi();

    Serial.println("Location request data");
#ifdef DEBUG_APS
    Serial.println(location.getSurroundingWiFiJson());
#endif
    Serial.println("Latitude Longitude");
    Serial.println(String(loc.lat, 7) + " " + String(loc.lon, 7));
    Serial.println("Accuracy: " + String(loc.accuracy));
}

void
loop(void)
{
}
