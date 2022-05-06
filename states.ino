#include <Arduino.h>

// initial
void state0() {
  Serial.println("state 0");
  digitalWrite(RELAY_CONTINUITY, LOW);
  digitalWrite(RELAY_IGNITOR, LOW);
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
  delay(100);
}

void state4() {
  Serial.println("state 4");
  digitalWrite(RELAY_CONTINUITY, LOW);
  setColor(YELLOW);
}

void state5() {
  Serial.println("state 5");
  delay(5000);
}

void state6() {
  Serial.println("state 6");

}

void state7() {
  Serial.println("state 4");
}

// TRANSITIONS

// state 1 if continuty switch is off
bool t01() {
  return digitalRead(INPUT_CONTINUITY_SWITCH) == LOW;
}

// state 2 once switch is turned on.
bool t12() {
  return digitalRead(INPUT_CONTINUITY_SWITCH) == HIGH;
}

// state 3 once we verify continuity
bool t23() {
  int reading = analogRead(INPUT_CONTINUITY);
  Serial.print("Continuity Reading: ");
  Serial.println(reading);
  return  reading > 100 && reading < 500;
}

// if 2-3 fails then we want to go back to 0
bool t20() {
  return true;
}