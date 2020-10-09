#ifndef DEMO_01_h
#define DEMO_01_h

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>
#include <PubSubClient.h>


char *wifiName = "cclhui";
char *password = "Wn1989318";

char *mqttServer = "118.24.111.175";
int mqttServerPort = 1883;

WiFiClient espClient; //wifi 实例
PubSubClient mqttClient(espClient);
ESP8266WiFiMulti WiFiMulti;

//链接wifi 显示ip
void connectWifi() {

  delay(5000);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifiName);

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifiName, password);

  Serial.print("Connecting");
  int tryNum = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("tryNum_x:");
    Serial.println(tryNum);
    tryNum++;
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}


//http
void connectWifiForHttp() {
    for (uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(wifiName, password);

    Serial.print("Connecting");
    int tryNum = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print("tryNum_x:");
        Serial.println(tryNum);
        tryNum++;
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());

}

#endif