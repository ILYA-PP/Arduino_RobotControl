const int stepMotor1 = 54;
const int enableMotor1 = 38;
const int dirMotor1 = 55;
const int stepMotor2 = 60;
const int enableMotor2 = 56;
const int dirMotor2 = 61;

int maxSpeed1 = 400;
int minSpeed1 = 1;
int speed_1 = 400;
int steps_in_one_turn_1 = 200;
int maxSpeed2 = 400;
int minSpeed2 = 1;
int speed_2 = 150;
int steps_in_one_turn_2 = 200;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

int switch_IO = 0, switch_1 = 0, switch_2 = 0;
int stepState1 = 0, x1;
int stepState2 = 0, x2;

void setup()
{
  Serial.begin(38400);
  pinMode( stepMotor1, OUTPUT); digitalWrite( stepMotor1, LOW);
  pinMode( enableMotor1, OUTPUT); digitalWrite( enableMotor1, HIGH);
  pinMode( dirMotor1, OUTPUT); digitalWrite( dirMotor1, LOW);
  pinMode( stepMotor2, OUTPUT); digitalWrite( stepMotor2, LOW);
  pinMode( enableMotor2, OUTPUT); digitalWrite( enableMotor2, HIGH);
  pinMode( dirMotor2, OUTPUT); digitalWrite( dirMotor2, LOW);
}

void loop()
{  
  char vall = Serial.read();

  if (speed_1 <= 19) {
    x1 = 1;
  }
  if (speed_1 >= 20) {
    x1 = 2;
  }
  if (speed_1 >= 50) {
    x1 = 5;
  }
  if (speed_1 >= 100) {
    x1 = 10;
  }
  if (speed_1 >= 200) {
    x1 = 20;
  }
  if (speed_2 <= 19) {
    x2 = 1;
  }
  if (speed_2 >= 20) {
    x2 = 2;
  }
  if (speed_2 >= 50) {
    x2 = 5;
  }
  if (speed_2 >= 100) {
    x2 = 10;
  }
  if (speed_2 >= 200) {
    x2 = 20;
  }
  if (vall == '1') {
    speed_1 = speed_1 + x1;
  }
  if (vall == '2') {
    speed_1 = speed_1 - x1;
  }
  if (vall == '3') {
    speed_2 = speed_2 + x2;
  }
  if (vall == '4') {
    speed_2 = speed_2 - x2;
  }
  if (speed_1 > maxSpeed1) {
    speed_1 = maxSpeed1;
  }
  if (speed_1 < minSpeed1) {
    speed_1 = minSpeed1;
  }
  if (speed_2 > maxSpeed2) {
    speed_2 = maxSpeed2;
  }
  if (speed_2 < minSpeed2) {
    speed_2 = minSpeed2;
  }
  long interval1 = 30000000 / steps_in_one_turn_1 / speed_1;
  long interval2 = 30000000 / steps_in_one_turn_2 / speed_2;
  unsigned long currentMillis1 = micros();
  if (currentMillis1 - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis1;
    if (stepState1 == LOW) {
      stepState1 = HIGH;
    } else {
      stepState1 = LOW;
    }
    digitalWrite( stepMotor1, stepState1);
  } else {
    digitalWrite( stepMotor1, LOW);
  }
  unsigned long currentMillis2 = micros();
  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;
    if (stepState2 == LOW) {
      stepState2 = HIGH;
    } else {
      stepState2 = LOW;
    }
    digitalWrite( stepMotor2, stepState2);
  } else {
    digitalWrite( stepMotor2, LOW);}
    
   if ((vall == 'a') && (digitalRead(enableMotor1) == HIGH)) {
    digitalWrite(dirMotor1,LOW);
    digitalWrite(enableMotor1,LOW);
  }
  if (vall == 'A') {
    digitalWrite(enableMotor1,HIGH);
  }
}
