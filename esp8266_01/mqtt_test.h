#ifndef MQTT_TEST_h
#define MQTT_TEST_h

#include <Arduino.h>
#include "demo_01.h"


//mqtt 链接wifi 和相关初始化
void mqttSetUpWifiAndInit() {

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

  //初始化随机数种子
  randomSeed(micros());
}

//mqtt 收到消息处理回掉函数
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

}


//mqtt 断线重连
void mqttReconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (mqttClient.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqttClient.publish("outTopic", "hello world");
      // ... and resubscribe
      mqttClient.subscribe("cclehui_test");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


#endif