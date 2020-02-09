#include<Arduino.h>
#include"Pline.h"
#include"pin.h"
#include"motor.h"
#include"sensor.h"

#define MS1 120
#define MS2 100
#define MS3 80
#define MS4 60

void GO(int way) {
    if (way == r) {
        MOVE(120, 0);
    }
    else if (way == l) {
        MOVE(0, 120);
    }
    else if (way == f) {
        MOVE(120, 120);
    }
    else if (way == s) {
        MOVE(0, 0);
    }
}

void Pline(const int (&Sensors)[9]) {
    bool lineResult[9];
    int linePower[9];
    int blackSum = 0;
    for (int i = 0; i < 9; i++) {
        lineResult[i] = digitalRead(Sensors[i]);
        linePower[i] = lineResult[i] * powerArray[i];
        blackSum += lineResult[i];
    }
    int LPowerSum = 0;
    int RPowerSum = 0;
    for (int i = 0; i < 4; i++) {
        LPowerSum += linePower[i];
    }
    int LPowerAverage = LPowerSum / (!blackSum ? 1 : blackSum);
    for (int i = 5; i < 9; i++) {
        RPowerSum += linePower[i];
    }
    int RPowerAverage = RPowerSum / (!blackSum ? 1 : blackSum);
    int LSpeed = standardValue - LPowerAverage;
    int RSpeed = standardValue - RPowerAverage;
    MOVE(LSpeed, RSpeed);
}
