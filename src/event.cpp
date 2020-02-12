#include<Arduino.h>
#include"event.h"
#include"pin.h"
#include"motor.h"
#include"sensor.h"

void event1(DigitalPin *led, bool flag) {
    led->write(flag);
}

void event2() {

}

void event3() {

}

void event4() {
    digitalWrite(pin_crackerMotor1, HIGH);
    digitalWrite(pin_crackerMotor2, LOW);
    delay(5000);
    digitalWrite(pin_crackerMotor1, LOW);
    digitalWrite(pin_crackerMotor2, LOW);
}
