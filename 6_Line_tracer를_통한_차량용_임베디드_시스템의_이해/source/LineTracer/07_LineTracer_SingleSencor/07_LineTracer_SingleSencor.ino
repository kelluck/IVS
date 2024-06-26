#include<IRremote.h>//IR 리모컨라이브러리.

#define PIN_IR_RECEIVE 2
#define PIN_MOTOR_LEFT_FORWARD 10
#define PIN_MOTOR_LEFT_BACKWARD 9
#define PIN_MOTOR_RIGHT_FORWARD 6
#define PIN_MOTOR_RIGHT_BACKWARD 5
#define PIN_LINE_DETECT_RIGHT A0
//#define PIN_LINE_DETECT_LEFT A1
#define REF_VALUE_LINE_DETECT 250

int motorSpeedLeft= 0; // -255~255
int motorSpeedRight= 0; // -255~255
int isStartLineTracing= 0;
//int detectValueLeft= 0;
int detectValueRight= 0;

void processMotor(void);

void setup() {
  IrReceiver.begin(PIN_IR_RECEIVE, ENABLE_LED_FEEDBACK);
  
  pinMode(PIN_MOTOR_LEFT_FORWARD, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_BACKWARD, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_FORWARD, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_BACKWARD, OUTPUT);
  
  analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
  analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
  analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
  analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
}

void loop() {
  if (IrReceiver.decode() == true) {
    if (IrReceiver.decodedIRData.protocol == NEC) {
      if (IrReceiver.decodedIRData.command == 0x16) { // *
        isStartLineTracing = 1;
      }
      else if (IrReceiver.decodedIRData.command == 0x0D) { // #
        isStartLineTracing = 0;
      }
    }
    IrReceiver.resume();
  }
  if (isStartLineTracing == 0) {
    motorSpeedLeft = 0;
    motorSpeedRight = 0;
  }
  else {
//    detectValueLeft = analogRead(PIN_LINE_DETECT_LEFT);
    detectValueRight = analogRead(PIN_LINE_DETECT_RIGHT);
    // 직진
    if (detectValueRight >= REF_VALUE_LINE_DETECT) {
      motorSpeedLeft = 255;
      motorSpeedRight = 255;
    }
    // 좌회전
    else if (detectValueRight < REF_VALUE_LINE_DETECT) {
      motorSpeedLeft = -90;
      motorSpeedRight = 200;
    }
  }
  processMotor();
}

 
void processMotor(void){
  if (motorSpeedLeft>= 0){
    analogWrite(PIN_MOTOR_LEFT_FORWARD, motorSpeedLeft);
    analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
    //delay(5);
  }
  else{
    analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
    analogWrite(PIN_MOTOR_LEFT_BACKWARD, motorSpeedLeft*(-1));
  }
  if (motorSpeedRight>= 0) {
    analogWrite(PIN_MOTOR_RIGHT_FORWARD, motorSpeedRight);
    analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
    //delay(5);
  }
  else{
    analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
    analogWrite(PIN_MOTOR_RIGHT_BACKWARD, motorSpeedRight*(-1));
  }
}
