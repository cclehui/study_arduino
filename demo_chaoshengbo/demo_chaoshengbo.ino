//超声波demo程序： https://www.w3cschool.cn/arduino/arduino_ultrasonic_sensor.html


const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 8; // Echo Pin of Ultrasonic Sensor
int outputPin = 5;
int outputValue = 0;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal

   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(outputPin, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   Serial.println(11111);
   
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);

   if (cm > 255) {
      outputValue = 255; 
   } else {
       outputValue = cm;
   }

   analogWrite(outputPin, outputValue);
   
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
