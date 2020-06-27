//智能小车项目 01

//#include <IRremote.h>

/*
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
*/

int MotoBIn1 = 3; // MotoBIn1 
int MotoBIn2 = 5; //MotoBIn2

int MotoAIn1 = 6; // MotoAIn1 
int MotoAIn2 = 9; //MotoAIn2

unsigned long lastTime;
bool directionFlag = true; // 运行方向 1:正转 2:反转
int highLevel = 0;

bool stop = false; //是否停止工作 

//超声波
const int pingPin = 11; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor


//红外控制
//参考 https://www.jianshu.com/p/5add4c666983
/*
int getIRAction() {
  int irResult = 0;
  Serial.println("getIRAction");
     if(irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        //Serial.println(results.value, DEC);
        
        irrecv.resume(); // Receive the next value
  }

  return irResult;
}
*/


//超声波控制
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

int getChaoShengBoBack() {
   long duration, inches, cm;
   
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   //Serial.println(11111);
   
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm); 
   Serial.print("cm");
   Serial.print(digitalRead(echoPin));
   Serial.println();
   
   

   if (cm < 20 && cm > 6 && cm > 0) {
      return 5; 
   }

   return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(5); 

  //irrecv.enableIRIn(); // Start the receiver 启动红外接收

  pinMode(MotoBIn1, OUTPUT);
  pinMode(MotoBIn2, OUTPUT);
  
  pinMode(MotoAIn1, OUTPUT);
  pinMode(MotoAIn2, OUTPUT);

   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //getIRAction();
  //delay(500);
  //return;

  unsigned long nowTime;
  nowTime = millis();

  int action = Serial.parseInt(); //串口控制
  if (action != 1 && action != 9) {
    int action2 = getChaoShengBoBack();//超声波倒退
    if (action2 == 5) {
      action = 5;  
    }
  }
  //if (lastTime == 0 || (nowTime - lastTime) > 5000) {
  switch (action) {
    case 1:
      stop = false;
      break;
    case 5:
      if ((nowTime - lastTime) > 5000) {
      directionFlag = !directionFlag;
      lastTime = nowTime;
      Serial.println("换向");
      highLevel = 0;
      Serial.flush();
      }
      break;
    case 9:
      //停止工作
      //getIRAction();
      stop = true;
      break;
  }

  if (stop) {
    analogWrite(MotoBIn1, 0);
    analogWrite(MotoBIn2, 0);
  analogWrite(MotoAIn1, 0);
    analogWrite(MotoAIn2, 0);
    return;  
  }

  if (directionFlag) {
    //digitalWrite(MotoBIn1, HIGH);
    //digitalWrite(MotoBIn2, LOW);

    analogWrite(MotoBIn1, highLevel);
    analogWrite(MotoBIn2, 0);
  
  analogWrite(MotoAIn1, highLevel);
    analogWrite(MotoAIn2, 0);
  } else {
    //digitalWrite(MotoBIn1, LOW);
    //digitalWrite(MotoBIn2, HIGH);

    analogWrite(MotoBIn1, 0);
    analogWrite(MotoBIn2, highLevel);
  
  analogWrite(MotoAIn1, 0);
    analogWrite(MotoAIn2, highLevel);
  }

  if (highLevel < 255) {
      highLevel += 20;
      if (highLevel > 255) {
        highLevel = 255;    
      }
      delay(300);
      lastTime = nowTime;
       Serial.println(highLevel);
  }

  
  //Serial.println()
  //delay(1000);
  //digitalWrite(MotoBIn1, LOW);
  //delay(1000);
  //digitalWrite(MotoBIn2, LOW);
  
}
