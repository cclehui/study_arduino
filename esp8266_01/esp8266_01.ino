


#include<SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);  // RX, TX

void setup() {
  Serial.begin(9600); 
  while (!Serial) {;}
  Serial.println("hardware serial!");
  mySerial.begin(115200);
  //mySerial.println("software seria");
}

void loop() {
  if(mySerial.available())
    Serial.write(mySerial.read());

 // if(Serial.available())
   // mySerial.write(Serial.read());
}


/*  链接wifi
#include "demo_01.h"
#include "mqtt_test.h"


void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
    Serial.println();
    //connectWifi();
    //connectWifiForHttp();

    //mqtt 实验
    mqttSetUpWifiAndInit();//初始化wifi
    mqttClient.setServer(mqttServer, mqttServerPort); //连接mqtt server
    mqttClient.setCallback(mqttCallback);
 

}

void loop() {
  // put your main code here, to run repeatedly:

    //httpTest();

    if (!mqttClient.connected()) {
       mqttReconnect();
    }
    mqttClient.loop();
    return;

    delay(5000);

}





void httpTest() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://118.24.111.175/")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

}

*/
