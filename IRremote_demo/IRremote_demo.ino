/*
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
*/
#include <IRremote.h>

//读取红外线传感器数据， 控制led
// https://www.jianshu.com/p/5add4c666983

int RECV_PIN = 11;
int outputPin = 5;//输出引脚
int outPutValue = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
  
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //红外传感器
  demo();
  
}

//红外控制
//参考 https://www.jianshu.com/p/5add4c666983
void demo() {
     if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        //Serial.println(results.value, DEC);
        
        if (results.value == 0xFFA857) {//增加亮度  +号
          outPutValue += 25;
          if (outPutValue > 255) {
              outPutValue = 255;
          }
          
          analogWrite(outputPin, outPutValue);
          Serial.println(outPutValue);
          
        } else if (results.value == 0xFFE01F) {//降低亮度 -号

          outPutValue -= 25;
          if (outPutValue < 0) {
              outPutValue = 0;
          }
        
          analogWrite(outputPin, outPutValue);
          Serial.println(outPutValue);
        }
        irrecv.resume(); // Receive the next value
  }
  delay(500);
}
