#include<Arduino.h>
#include"pin.h"

void pinsetup() {

    pinMode(pin_motorR1, OUTPUT);
    pinMode(pin_motorR2, OUTPUT);
    pinMode(pin_motorL1, OUTPUT);
    pinMode(pin_motorL2, OUTPUT);

    pinMode(pin_signalForA, OUTPUT);
    pinMode(pin_signalForB, OUTPUT);
    digitalWrite(pin_signalForA, LOW);
    digitalWrite(pin_signalForB, LOW);

    digitalWrite(pin_crackerMotor1, LOW);
    digitalWrite(pin_crackerMotor2, LOW);
    for (int i = 0; i < 7; i++) {
        pinMode(LED[i], OUTPUT);
        pinMode(SW[i], INPUT_PULLUP);
    }
    for (int i : sensor) {
        pinMode(i, INPUT);
    }

}
