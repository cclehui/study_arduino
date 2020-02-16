//引入依赖
#include <LiquidCrystal.h>  

// 初始化LCD针脚
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
int count = 0;

LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
   Serial.println("xxxxxxxxxx");
  LCD.begin(16,2);    //初始化,设置列行
 
  LCD.clear();    //清除屏幕
  LCD.print("Hello World!");  //在屏幕上显示"Hello World!"
}

void loop() {
  Serial.println(count);
  LCD.setCursor(1, 1);
    //LCD.clear();    //清除屏幕
    LCD.print(count);  //在屏幕上显示"Hello World!"
    count++;
    Serial.println(count);
    delay(1000);
}
