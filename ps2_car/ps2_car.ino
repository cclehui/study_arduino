
#include <PS2X_lib.h>  //for v1.6



/******************************************************************
 * set pins connected to PS2 controller:
 *   - 1e column: original 
 *   - 2e colmun: Stef?
 * replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT        13  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

/******************************************************************
 * select modes of PS2 controller:
 *   - pressures = analog reading of push-butttons 
 *   - rumble    = motor rumbling
 * uncomment 1 of the lines for each mode selection
 ******************************************************************/
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you connect the controller, 
//or call config_gamepad(pins) again after connecting the controller.

int error = 0;
byte type = 0;
byte vibrate = 0;


//电机相关定义
int MotoAIn1 = 3; // MotoAIn1 
int MotoAIn2 = 5; //MotoAIn2
int MotoBIn1 = 6; // MotoBIn1 
int MotoBIn2 = 9; //MotoBIn2

const int maxValue = 255;
const int minValue = 0;

int badLoopCount = 0;


void setup() {

 Serial.begin(57600);
  //Serial.begin(115200);

  //配置 ps2 手柄
  bool rs = false;
  int configCount = 0;
 

  do {
      rs = configPs2();

      if (rs) {
        break;  
      }

      Serial.print("configCount:");
      Serial.println(configCount);
      configCount++;
      delay(1000);
  }while(true);

  //配置电机引脚
  pinMode(MotoBIn1, OUTPUT);
  pinMode(MotoBIn2, OUTPUT);
  
  pinMode(MotoAIn1, OUTPUT);
  pinMode(MotoAIn2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (type ==2 || error == 1) {
      Serial.println("ps2 手柄配置异常，请重试");
      return;  
  }

  int highLevel = 255;

  bool isBadInfo = false;

  int leftXValue = 127;
  int leftYValue = 127;
  int rightXValue = 127;
  int rightYValue = 127;
  
  ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed
  if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { //print stick values if either is TRUE

      leftXValue = (uint8_t)ps2x.Analog(PSS_LX);
      leftYValue = (uint8_t) ps2x.Analog(PSS_LY);

      rightXValue = (uint8_t)ps2x.Analog(PSS_RX);
      rightYValue = (uint8_t)ps2x.Analog(PSS_RY);

      if (leftXValue == maxValue && leftYValue == maxValue &&
        rightXValue == maxValue && rightYValue == maxValue ) {
          isBadInfo = true;
             
      } else {
          Serial.print("Stick Values:");
          Serial.print(leftXValue);
          Serial.print(",");
          Serial.print(leftYValue); 
          Serial.print(",");
          Serial.print(rightXValue); 
          Serial.print(",");
          Serial.println(rightYValue); 
      }

    }
     
    if (isBadInfo){
      stopMotoA();
      stopMotoB();
      
    } else {

      //Serial.println(motoAForwardValue(leftYValue));
      //电机
      analogWrite(MotoAIn2, motoAForwardValue(leftYValue));
      analogWrite(MotoAIn1, motoABackwardValue(leftYValue));

      analogWrite(MotoBIn1, motoAForwardValue(rightYValue));
      analogWrite(MotoBIn2, motoABackwardValue(rightYValue));
    }

  delay(50);

}
