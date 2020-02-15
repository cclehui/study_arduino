

//读取温度传感器数据， 控制led

int inputValue = 0;
int outputPin = 5;//输出引脚
int outValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);

  analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:
  //温度传感器
  wenduKongZhi();
  
}

//温度控制
//参考 http://www.360doc.com/content/18/0616/21/8052724_762939609.shtml
void wenduKongZhi() {
    int digitalValue = analogRead(A2); //
    float wendu = (float)digitalValue / 1023 * 110.00;
    //Serial.println(wendu);从
    //delay(500);
    //return;
    int i = 0;
    if (wendu >= 28) {
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
