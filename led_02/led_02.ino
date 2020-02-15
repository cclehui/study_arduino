

//led 灯控制相关demo

int ledOutput=5; //5号引脚支持 pwm 调频
int buttonIn=2;
int buttonState = 0;
int buttonStateOld = -1;
bool canChange  = true;

int lightBrightness = 0;
int lightDiff = 10;

void setup() {
  // put your setup code here, to run once:

   Serial.begin(9600);
   pinMode(ledOutput, OUTPUT);
   //pinMode(buttonIn, INPUT);
   pinMode(buttonIn, INPUT_PULLUP);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // 开关按下亮， 松开灭
  //ledDownLight();

  //每次按下 灯亮 灭切换
  ledChange();


  //呼吸灯
  //pwmLight();
  
  return; 
}

//led 开关按下亮， 松开灭
void ledDownLight() {
  buttonState = digitalRead(buttonIn);
  Serial.println(buttonState);

    if (buttonState == LOW) {
        digitalWrite(ledOutput, HIGH);
    } else {
        digitalWrite(ledOutput, LOW);
    }
} 


//每次按按钮 Led灯切换
void ledChange() {
  buttonState = digitalRead(buttonIn);
  if (buttonStateOld == -1) {
    buttonStateOld =   LOW;
    return;
  }
 // 

    if (buttonState == LOW) {
        delay(100);// 避免多次low 
        if  (buttonState == digitalRead(buttonIn) && canChange) {
          if (buttonStateOld == HIGH) {
              buttonStateOld = LOW;
           
          } else {
              buttonStateOld = HIGH;
          }
          canChange = false;
  
          Serial.println(buttonStateOld);
          Serial.println("---");
          
        }
    } else {
      canChange = true;  
    }
    
    digitalWrite(ledOutput, buttonStateOld);
} 

//呼吸灯效果
void pwmLight() {

  lightBrightness += lightDiff;
  if (lightBrightness >= 250 ||  lightBrightness <= 0) {
    lightDiff = 0 - lightDiff;
  }

  analogWrite(ledOutput, lightBrightness);

  Serial.println(lightBrightness);
  delay(100);
  
}
