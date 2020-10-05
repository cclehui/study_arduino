#include <ESP8266WiFi.h>


void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200);
  Serial.println();

  WiFi.begin("HUAWEI-cclehui", "clh123456");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
