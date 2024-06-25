#include <Servo.h>
#define PIN_MOTOR_CTRL_0 3
#define PIN_MOTOR_CTRL_1 11
#define PIN_SWITCH_GREEN 8
#define PIN_SWITCH_YELLOW 7
#define PIN_SWITCH_RED 6
#define PIN_SWITCH_BLACK 5
#define PIN_SWITCH_BLUE 4
#define PIN_SERVO_CTRL 13
int prevSwitchGreen = HIGH;
int prevSwitchYellow = HIGH;
int prevSwitchRed = HIGH;
int prevSwitchBlack = HIGH;
int prevSwitchBlue = HIGH;
byte motorCtrlValue0; // 모터 속도 조절 변수
byte servoPosition = 90; // Servo 각도 조절 변수 serverPosition (byte타입) - 전방 초기화
int rotateFlag = 0;
Servo servoRotate; // Servo 라이브러리 추가

void setup() {
  servoRotate.attach(PIN_SERVO_CTRL); // 멤버함수인 attach : 핀 설정(13번)
  servoRotate.write(servoPosition); // 13번 핀으로 통신 (아두이노가 알아서)
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
  int currentSwitchBlack = digitalRead(PIN_SWITCH_BLACK);
  int currentSwitchBlue = digitalRead(PIN_SWITCH_BLUE);

  // Black 버튼 : Fan 목의 회전을 멈추고 정면
  if ((prevSwitchBlack == LOW) && (currentSwitchBlack == HIGH)) {
    rotateFlag = 0;
    servoRotate.write(90);
  }
  // Blue 버튼 : Fan 목이 30~150도 사이에서 연속적으로 회전
  if ((prevSwitchBlue == LOW) && (currentSwitchBlue == HIGH)) {
    rotateFlag = 1;
  }
  if ((servoRotate.read() < 30 || servoRotate.read() > 150)) {
    rotateFlag = rotateFlag * (-1);
  }
  if (rotateFlag != 0) {
    servoRotate.write(servoRotate.read() + rotateFlag);
  }
  prevSwitchBlack = currentSwitchBlack;
  prevSwitchBlue = currentSwitchBlue;
  delay(100);
}
