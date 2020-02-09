#include"sensor.h"
#include"pin.h"
#include<Arduino.h>


//この関数要らない気が滅茶苦茶する。何で作ったんだろう。
/*
void ValueUpdate(int *SenL3,int *SenL2,int *SenL1,int *SenR1,int *SenR2,int *SenR3){
  *SenR3 = digitalRead(pin_SensorR3);
  *SenR2 = digitalRead(pin_SensorR2);
  *SenR1 = digitalRead(pin_SensorR1);
  *SenL1 = digitalRead(pin_SensorL1);
  *SenL2 = digitalRead(pin_SensorL2);
  *SenL3 = digitalRead(pin_SensorL3);
}*/

//
bool isBlack(int pin) {
    return digitalRead(pin) == 1;
}

int someBlack() {
    int sum = 0;

    for (int i : sensor) {
        if (digitalRead(i) == 1) {
            sum++;
        }
    }

    return sum;
}
