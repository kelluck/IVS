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
int detectValueRight= 0;

int mode = 0; // 시계 방향 = 0, 반시계 방향 = 1 

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

      else if(IrReceiver.decodedIRData.command == 0x45){ // 1
          mode = 1; // 반시계 방향 (좌회전)
      }
      else if(IrReceiver.decodedIRData.command == 0x46){ // 2
          mode = 0; // 시계 방향 (우회전)
      }
    }
    IrReceiver.resume();
  }
  if (isStartLineTracing == 0) {
    motorSpeedLeft = 0;
    motorSpeedRight = 0;
  }
  else {
    detectValueRight = analogRead(PIN_LINE_DETECT_RIGHT);
    // 직진
    if (detectValueRight >= REF_VALUE_LINE_DETECT) {
      motorSpeedLeft = 255;
      motorSpeedRight = 255;
    }
    // 좌회전
    else if (detectValueRight < REF_VALUE_LINE_DETECT && mode == 1) {
      motorSpeedLeft = -90;
      motorSpeedRight = 200;
    }
    // 우회전
    else if (detectValueRight < REF_VALUE_LINE_DETECT && mode == 0) {
      motorSpeedLeft = 200;
      motorSpeedRight = -90;
    }
  }
  processMotor();
}

 
void processMotor(void){
  if (motorSpeedLeft>= 0){
    analogWrite(PIN_MOTOR_LEFT_FORWARD, motorSpeedLeft);
    analogWrite(PIN_MOTOR_LEFT_BACKWARD, 0);
  }
  else{
    analogWrite(PIN_MOTOR_LEFT_FORWARD, 0);
    analogWrite(PIN_MOTOR_LEFT_BACKWARD, motorSpeedLeft*(-1));
  }
  if (motorSpeedRight>= 0) {
    analogWrite(PIN_MOTOR_RIGHT_FORWARD, motorSpeedRight);
    analogWrite(PIN_MOTOR_RIGHT_BACKWARD, 0);
  }
  else{
    analogWrite(PIN_MOTOR_RIGHT_FORWARD, 0);
    analogWrite(PIN_MOTOR_RIGHT_BACKWARD, motorSpeedRight*(-1));
  }
}
