
#define STEP_PIN 18
#define DIR_PIN 19
#define EN_PIN 5

#define STEPS_PER_REV 200

// ความเร็วในการหมุน
#define STEP_DELAY 1000

void setup() {
  Serial.begin(115200);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

  digitalWrite(STEP_PIN, LOW);
  digitalWrite(DIR_PIN, LOW);

  // เปิดใช้งาน DRV8825 (EN Active LOW)
  digitalWrite(EN_PIN, LOW);

  Serial.println("ESP32 DRV8825 Test Start");
}

void rotateMotor(bool direction, int steps) {

  digitalWrite(DIR_PIN, direction);

  delayMicroseconds(10);

  for (int i = 0; i < steps; i++) {

    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(5);

    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_DELAY);
  }
}

void loop() {

  Serial.println("Clockwise");

  // หมุนตามเข็ม 1 รอบ
  rotateMotor(HIGH, STEPS_PER_REV);

  delay(1000);

  Serial.println("Counter Clockwise");

  // หมุนทวนเข็ม 1 รอบ
  rotateMotor(LOW, STEPS_PER_REV);

  delay(1000);
}
