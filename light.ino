#include <Arduino.h>

const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

// red, green, blue
const byte RED[] = {255,0,0};
const byte YELLOW[] = {255,255,0};
const byte GREEN[] = {0,255,0};
const byte BLACK[] = {0,0,0};

void lightSetup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void setColor(const byte c[]) {
  analogWrite(RED_PIN, c[0]);
  analogWrite(GREEN_PIN, c[1]);
  analogWrite(BLUE_PIN, c[2]);
}