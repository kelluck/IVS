#define PIN_MOTOR_CTRL_0 3
#define PIN_MOTOR_CTRL_1 11
#define PIN_SWITCH_GREEN 8
#define PIN_SWITCH_YELLOW 7

int prevSwitchGreen = HIGH; //Pull-up 저항이라 초기값은 HIGH
int prevSwitchYellow = HIGH; //엣지 트리거를 위한 변수

byte motorCtrlValue0 = 0; //motor 힘 저장 변수

void setup() {
    pinMode(PIN_SWITCH_GREEN, INPUT);
    pinMode(PIN_SWITCH_YELLOW, INPUT);
    pinMode(PIN_MOTOR_CTRL_0, OUTPUT);
    pinMode(PIN_MOTOR_CTRL_1, OUTPUT);
    analogWrite(PIN_MOTOR_CTRL_0, 0);
    analogWrite(PIN_MOTOR_CTRL_1, 0);
    Serial.begin(115200);
}
void loop() {
    int currentSwitchGreen = digitalRead(PIN_SWITCH_GREEN);
    int currentSwitchYellow = digitalRead(PIN_SWITCH_YELLOW);
    
    if ((prevSwitchGreen == LOW) && (currentSwitchGreen == HIGH)) {
        motorCtrlValue0 = (motorCtrlValue0 < 245) ? (motorCtrlValue0 + 10) : 255; //오버플로우 방지
        analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
        analogWrite(PIN_MOTOR_CTRL_1, 0);
        Serial.println(motorCtrlValue0); //디버깅 코드 (버튼 눌렀을때의 제어량 확인)
    }
    
    if ((prevSwitchYellow == LOW) && (currentSwitchYellow == HIGH)) {
        motorCtrlValue0 = (motorCtrlValue0 > 10) ? (motorCtrlValue0 - 10) : 0; //오버플로우 방지
        analogWrite(PIN_MOTOR_CTRL_0, motorCtrlValue0);
        analogWrite(PIN_MOTOR_CTRL_1, 0);
        Serial.println(motorCtrlValue0); //디버깅 코드 (버튼 눌렀을때의 제어량 확인)
    }
    
    prevSwitchGreen = currentSwitchGreen;
    prevSwitchYellow = currentSwitchYellow;
    
    delay(100);
}
