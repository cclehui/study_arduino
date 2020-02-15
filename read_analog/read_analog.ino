

//读取模拟电压
//电位器 ,电位器 滑动电阻控制led灯亮度

//光明电阻控制led  光控

int inputValue = 0;
int outputPin = 5;//输出引脚
int outValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //滑动电阻
  //huadongDianZu();

  //光敏电阻
  guangMinDianZu();

  //蜂鸣器
  //fengmingqi();

  //温度传感器
  //wenduKongZhi();
  
}

//温度控制
void wenduKongZhi() {
    int wendu = analogRead(A2);
    //Serial.println(wendu);
    int i = 0;
    if (wendu >= 55) {
      for(i=0;i<=80;i++){
        
        digitalWrite(outputPin, HIGH);
        
        delay(1);//wait for 1ms
        
        digitalWrite(outputPin, LOW);
        
        delay(1);//wait for 1ms
        
    }
  } else {
    analogWrite(outputPin, LOW );  //关闭led
  }
}

//光敏电阻
void guangMinDianZu() {
  inputValue = analogRead(A1);
  //Serial.println(inputValue);

  if (inputValue > 400) {
      analogWrite(outputPin, 255); //点亮led
  } else {
    analogWrite(outputPin, 0);  //关闭led
  }
  
  //Serial.println(outValue);

  //delay(50);
}

//滑动电阻电位器
void huadongDianZu() {

  inputValue = analogRead(A1);
  //Serial.println(inputValue);

  outValue = map(inputValue, 0, 1024, 0, 255);

  analogWrite(outputPin, outValue);
  //Serial.println(outValue);

  delay(500);
}

//蜂鸣器
void fengmingqi() {
  inputValue = analogRead(A1);
  //Serial.println(inputValue);
  int i = 0;

  if (inputValue > 500) {
      //for(i=0;i<=80;i++){
        
        digitalWrite(outputPin, HIGH);
        
        delay(1);//wait for 1ms
        
        digitalWrite(outputPin, LOW);
        
        delay(1);//wait for 1ms
        
    //}
  } else {
    analogWrite(outputPin, LOW  );  //关闭led
  }
  
  //Serial.println(outValue);

  //delay(50);
}
