#include <PS2X_lib.h>



void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  

  myTest();

  Serial.print("xxxx");
  Serial.print("yyyyyy");
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.print("aaaaaa");
  delay(1000);
}
