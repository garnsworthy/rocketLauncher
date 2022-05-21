#include <Arduino.h>

// initial
void state0() {
  Serial.println("state 0");
  digitalWrite(RELAY_CONTINUITY, LOW);
  digitalWrite(RELAY_IGNITOR, LOW);
  setColor(RED);
}

// wait for con switch low
void state1() {
  Serial.println("state 1");
}

// con switch went high, test continuity
void state2() {
  Serial.println("state 2");
  digitalWrite(RELAY_CONTINUITY, HIGH);
  
}

// good continuity, no longer need to test.
void state3() {
  Serial.println("state 3");
  digitalWrite(RELAY_CONTINUITY, LOW);
}

void state4() {
  Serial.println("state 4");
  for(int i=0; i<5; i++) {
    setColor(YELLOW);
    delay(500);
    setColor(BLACK);
    delay(500);
  }
}

void state5() {
  Serial.println("state 5");
  setColor(GREEN);
}

void state6() {
  Serial.println("state 6");
  digitalWrite(RELAY_IGNITOR, HIGH);
  delay(200);
  // will go to low in 0
}

// TRANSITIONS
bool tTrue() {
  return true;
}

// state 1 if continuty switch is off
bool t01() {
  return digitalRead(INPUT_CONTINUITY_SWITCH) == HIGH &&
         digitalRead(INPUT_ARM_KEY) == HIGH;
}

// state 2 once switch is turned on.
bool t12() {
  return digitalRead(INPUT_CONTINUITY_SWITCH) == LOW;
}

// state 3 once we verify continuity
bool t23() {
  int reading = analogRead(INPUT_CONTINUITY);
  Serial.print("Continuity Reading: ");
  Serial.println(reading);
  return  reading > 100 && reading < 500;
}

// if arm switch on
bool t34() {
  return digitalRead(INPUT_ARM_KEY) == LOW;
}

bool t56() {
  return digitalRead(INPUT_LAUCH_BUTTON) == LOW;
}