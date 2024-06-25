#include <Servo.h>
#include <EEPROM.h> //EEPROM
#define PIN_MOTOR_CTRL_0 3
#define PIN_MOTOR_CTRL_1 11
#define PIN_SWITCH_GREEN 8
#define PIN_SWITCH_YELLOW 7
#define PIN_SWITCH_RED 6
#define PIN_SWITCH_BLACK 2 
#define PIN_SWITCH_BLUE 4
#define PIN_SERVO_CTRL 13
int prevSwitchGreen = HIGH;
int prevSwitchYellow = HIGH;
int prevSwitchRed = HIGH;
int prevSwitchBlack = HIGH;
int prevSwitchBlue = HIGH;
byte motorCtrlValue0; 
byte servoPosition = 90; 
int rotateFlag = 0;
Servo servoRotate;

/////////////선언///////////
uint32_t totalRotateMicros;
uint32_t rotateStartMicros;
////////////////////////////

void setup() {
  attachInterrupt(digitalPinToInterrupt(PIN_SWITCH_BLACK), isrSwitchBlack, RISING); 
  servoRotate.attach(PIN_SERVO_CTRL); 
  servoRotate.write(servoPosition); 
  // 디지털 핀 초기화(pinMode) (핀번호, 입0/출력1)
  pinMode(PIN_SWITCH_GREEN, INPUT);
  pinMode(PIN_SWITCH_YELLOW, INPUT);
  pinMode(PIN_SWITCH_RED, INPUT);
  pinMode(PIN_SWITCH_BLACK, INPUT);
  pinMode(PIN_SWITCH_BLUE, INPUT);
  pinMode(PIN_MOTOR_CTRL_0, OUTPUT);
  pinMode(PIN_MOTOR_CTRL_1, OUTPUT);
  pinMode(PIN_SERVO_CTRL, OUTPUT);
  // 아날로그 출력 핀의 전압 설정(0~5V) (핀번호, 전압) - 모터 제어량 0으로 초기화
  analogWrite(PIN_MOTOR_CTRL_0, 0); // 3번 핀
  analogWrite(PIN_MOTOR_CTRL_1, 0); // 11번 핀
  Serial.begin(115200);

  /////////////////////reset했을때/////////////////////////
  totalRotateMicros = (unsigned long)EEPROM.read(0) << 24;
  totalRotateMicros += (unsigned long)EEPROM.read(1) << 16;
  totalRotateMicros += (unsigned long)EEPROM.read(2) << 8;
  totalRotateMicros += (unsigned long)EEPROM.read(3) << 0;
  Serial.print("totalRotateMicros: ");
  Serial.println(totalRotateMicros);
  ////////////////////////////////////////////////////////
}

void isrSwitchBlack() 
{
  rotateFlag = 0;
  servoRotate.write(90);  
}

void loop() {
  // Fan Control
  int currentSwitchGreen = digitalRead(PIN_SWITCH_GREEN);
  int currentSwitchYellow = digitalRead(PIN_SWITCH_YELLOW);
  int currentSwitchRed = digitalRead(PIN_SWITCH_RED);
  // Green 버튼 : 최대 속도의 50%로 Fan 회전
  if ((prevSwitchGreen == LOW) && (currentSwitchGreen == HIGH)) {
    analogWrite(PIN_MOTOR_CTRL_0, 127);
    Serial.println(127);
  }
  // Yellow 버튼 : 최대 속도로 Fan 회전
  if ((prevSwitchYellow == LOW) && (currentSwitchYellow == HIGH)) {
    analogWrite(PIN_MOTOR_CTRL_0, 255);
    Serial.println(255);
  }
  // Red 버튼 : Fan 회전 정지
  if ((prevSwitchRed == LOW) && (currentSwitchRed == HIGH)) {
    analogWrite(PIN_MOTOR_CTRL_0, 0);
    Serial.println(0);
  }
  prevSwitchGreen = currentSwitchGreen;
  prevSwitchYellow = currentSwitchYellow;
  prevSwitchRed = currentSwitchRed;

  // Rotate Control
  int currentSwitchBlue = digitalRead(PIN_SWITCH_BLUE);

  // Blue 버튼 : Fan 목이 30~150도 사이에서 연속적으로 회전
  if ((prevSwitchBlue == LOW) && (currentSwitchBlue == HIGH)) {   
    rotateFlag = 1;
    ////////////////??////////////////////    
    if(rotateStartMicros == 0){
        rotateStartMicros = micros();
    }
    if(totalRotateMicros >= 1000000){
      rotateFlag = 0;  
    }
    ////////////////////////////////////////
  }
  
  if ((servoRotate.read() < 30 || servoRotate.read() > 150)) {
    rotateFlag = rotateFlag * (-1);
  }
  if (rotateFlag != 0) {
    servoRotate.write(servoRotate.read() + rotateFlag);
    //////////////////////???/////////////////
    if((micros() - rotateStartMicros) >= 1000000){
      rotateStartMicros = micros();
      totalRotateMicros += 1000000;
      uint8_t buffer[4];
      memcpy(buffer, &totalRotateMicros, 4);
      EEPROM.write(0, buffer[3]);
      EEPROM.write(1, buffer[2]);
      EEPROM.write(2, buffer[1]);
      EEPROM.write(3, buffer[0]);  
    }
   /////////////////////////////////////////
  }

  
  //////////////////?????????????/////////////////////
  if((currentSwitchGreen == LOW) && (currentSwitchYellow == LOW) && (currentSwitchRed == LOW)){
    if(totalRotateMicros != 0){
      totalRotateMicros = 0;
      Serial.println(totalRotateMicros);
      uint8_t buffer[4];
      memcpy(buffer, &totalRotateMicros, 4);
      EEPROM.write(0, buffer[3]);
      EEPROM.write(1, buffer[2]);
      EEPROM.write(2, buffer[1]);
      EEPROM.write(3, buffer[0]);
    } 
  }
  ////////////////////////////////////////////////////
  prevSwitchBlue = currentSwitchBlue;
  delay(100);
}
