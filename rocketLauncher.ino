#include <StateMachine.h>

const int RELAY_CONTINUITY1 = 2;
const int RELAY_CONTINUITY2 = 3;
const int RELAY_IGNITOR1 = 7;
const int RELAY_IGNITOR2 = 8;

const int INPUT_CONTINUITY = A1;
const int INPUT_CONTINUITY_SWITCH = 4;
const int INPUT_ARM_KEY = 5;
const int INPUT_LAUCH_BUTTON = 6;

StateMachine machine = StateMachine();

State* S0 = machine.addState(&state0);
State* S1 = machine.addState(&state1);
State* S2 = machine.addState(&state2);
State* S3 = machine.addState(&state3);
State* S4 = machine.addState(&state4);
State* S5 = machine.addState(&state5);
State* S6 = machine.addState(&state6);

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_CONTINUITY1, OUTPUT);
  pinMode(RELAY_IGNITOR1, OUTPUT);
  pinMode(RELAY_CONTINUITY2, OUTPUT);
  pinMode(RELAY_IGNITOR2, OUTPUT);
  pinMode(INPUT_CONTINUITY_SWITCH, INPUT_PULLUP);
  pinMode(INPUT_ARM_KEY, INPUT_PULLUP);
  pinMode(INPUT_LAUCH_BUTTON, INPUT_PULLUP);

  S0->addTransition(&t01, S1);
  S1->addTransition(&t12, S2);
  S2->addTransition(&t23, S3);
  S2->addTransition(&tTrue, S0); // go back
  S3->addTransition(&t34, S4);
  S4->addTransition(&tTrue, S5);
  S5->addTransition(&t56, S6);
  S6->addTransition(&tTrue, S0);
}

void loop() {
  machine.run();
  delay(100);
}
