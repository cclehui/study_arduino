
int ledPin=5;
//int ledPin=13;
int brightness=0;
int add = 5;

void setup() {
  // put your setup code here, to run once:

  char my_str[6]; // an array big enough for a 5 character string
   Serial.begin(9600);
   my_str[0] = 'H'; // the string consists of 5 characters
   my_str[1] = 'e';
   my_str[2] = 'l';
   my_str[3] = 'l';
   my_str[4] = 'o';
   my_str[5] = 0; // 6th array element is a null terminator
   Serial.println(my_str);

   pinMode(ledPin, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println("1111111111");

  //analogWrite(ledPin, brightness);
  
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  //Serial.println(HIGH);
  //Serial.println(LOW);
  delay(1000);
  return 

  brightness+= add;

  if (brightness >= 150 || brightness <=0) {
    add = -add;  
  }

  //Serial.println(brightness);

  delay(100);

  /*
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  */
}
