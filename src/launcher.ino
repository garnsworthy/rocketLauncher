#include <StateMachine.h>

const int relayContinuity = 2;
const int relayLaunch = 3;
const int inputContinuityTest = A1;
const int inputContinuitySwitch = 4;

StateMachine machine = StateMachine();

State* S0 = machine.addState(&state0);
State* S1 = machine.addState(&state1);
State* S2 = machine.addState(&state2);
State* S3 = machine.addState(&state3);
State* S4 = machine.addState(&state4);

void setup() {
  pinMode(relayContinuity, OUTPUT);
  pinMode(relayLaunch, OUTPUT);

  S0->addTransition(&t0-1, S1);
  S1->addTransition(&t1-2, S2);
  S2->addTransition(&t2-3, S3);
  S2->addTransition(&t2-0, S0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  machine.run();
  delay(100);
}

// initial
void state0() {
  Serial.println("state 0");
  digitalWrite(relayContinuity, LOW);
}

// wait for con switch low
void state1() {
  Serial.println("state 1");
}

// con switch went high, test continuity
void state2() {
  Serial.println("state 2");
  digitalWrite(relayContinuity, HIGH);
  delay(100);
  
}

// good continuity, no longer need to test.
void state3() {
  Serial.println("state 3");
  digitalWrite(relayContinuity, LOW);
  delay(100);
}

void state4() {
  Serial.println("state 4");
}

// state 1 if continuty switch is off
bool t0-1() {
  return digitalRead(inputContinuitySwitch) == LOW);
}

// state 2 once switch is turned on.
bool t1-2() {
  return digitialRead(inputContinuitySwitch) == HIGH);
}

// state 3 once we verify continuity
bool t2-3() {
  int reading = analogRead(inputContinuityTest)
  Serial.print("Continuity Reading: ");
  Serial.println(reading);
  return  reading > 100 && reading < 500;
}

// if 2-3 fails then we want to go back to 0
bool t2-0() {
  return true;
}