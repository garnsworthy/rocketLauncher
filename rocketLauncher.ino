#include <StateMachine.h>

const int RELAY_CONTINUITY = 2;
const int RELAY_IGNITOR = 3;
const int INPUT_CONTINUITY = A1;
const int INPUT_CONTINUITY_SWITCH = 4;

StateMachine machine = StateMachine();

State* S0 = machine.addState(&state0);
State* S1 = machine.addState(&state1);
State* S2 = machine.addState(&state2);
State* S3 = machine.addState(&state3);
State* S4 = machine.addState(&state4);
State* S5 = machine.addState(&state4);
State* S6 = machine.addState(&state4);
State* S7 = machine.addState(&state4);

void setup() {
  pinMode(RELAY_CONTINUITY, OUTPUT);
  pinMode(RELAY_IGNITOR, OUTPUT);

  S0->addTransition(&t01, S1);
  S1->addTransition(&t12, S2);
  S2->addTransition(&t23, S3);
  S2->addTransition(&t20, S0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  machine.run();
  delay(100);
}
