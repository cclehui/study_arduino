
//滚珠开关控制led 
// 参考： https://jingyan.baidu.com/article/a3a3f8112df7eb8da2eb8a17.html 

int outputPin = 5;//输出引脚
int outPutValue = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int inputValue = analogRead(A1);
  
  if (inputValue < 512) {
      delay(100);
      inputValue = analogRead(A1);
      if (inputValue < 512) {
          Serial.println(inputValue);
          if (outPutValue == LOW) {
              outPutValue = HIGH;
          } else {
              outPutValue = LOW;
          }
      }
  }

  digitalWrite(outputPin, outPutValue);
  delay(100);
}
