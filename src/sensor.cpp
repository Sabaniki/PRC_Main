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
    if (digitalRead(pin) == 1) {
        //センサは黒で1を返す(確認済み)
        return true;
    }
    return false;
}

int someBlack() {
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        if (digitalRead(sensor[i]) == 1) {
            sum++;
        }
    }

    return sum;
}
