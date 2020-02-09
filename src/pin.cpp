#include<Arduino.h>
#include"pin.h"

void pinsetup() {

    pinMode(pin_motorR1, OUTPUT);
    pinMode(pin_motorR2, OUTPUT);
    pinMode(pin_motorL1, OUTPUT);
    pinMode(pin_motorL2, OUTPUT);

    pinMode(pin_RX, OUTPUT);
    pinMode(pin_TX, OUTPUT);

    for (int i = 0; i < 7; i++) {
        pinMode(LED[i], OUTPUT);
        pinMode(SW[i], INPUT_PULLUP);
    }
    for (int i = 0; i < 9; i++) {
        pinMode(sensor[i], INPUT);
    }

}
