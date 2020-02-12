#include"flag.h"
#include"Pline.h"
#include"event.h"
#include"motor.h"
#include"sensor.h"
#include"pin.h"
#include<Arduino.h>
#include"str.h"

int FlagEvent(int flag, DigitalPin *timerSignalIn, DigitalPin *timerSignalOut) {
    if ((someBlack() >= 6) && (flag == 0)) {//スタート地点通過
        MOVE(0, 0);
        delay(500);
        delay(50);
        timerSignalOut->write(HIGH);
        delay(50);
        return 1;
    }
    else if ((someBlack() >= 6) && (flag == 1)) {//A地点
        MOVE(0, 0);
        //A地点検知をラズパイに送る
        digitalWrite(pin_signalForA, HIGH);
        // digitalWrite(pin_signalForB, HIGH);
        delay(500);
        struct motion order{};
        String str;
        // int L, R;
        // if(!Serial){
        Serial.begin(9600);
        // }
        auto led = DigitalPin(2, OUTPUT);
        bool flag = false;
        while (true) {
            //通信
            if (Serial.available() > 0) {
                str = Serial.readStringUntil('\n');
                order = getFromStr(str);

                MOVE(order.l, order.r);
                if (someBlack() >= 1) {
                    digitalWrite(LED[6], HIGH);
                }
                else if (someBlack() == 0) {
                    digitalWrite(LED[6], LOW);
                }

                if ((order.act[0] == 'd') && (order.act[1] == 'c')) {
                    Serial.end();
                    break;
                }
                else if ((order.act[0] == 'l') && (order.act[1] == 'e')) {
                    event1(&led, flag); // LED点灯
                    flag =! flag;
                }

            }
        }
        MOVE(0, 0);
        delay(500);
        return 2;
    }
    else if ((someBlack() >= 6) && (flag == 2)) {//B地点
        event2();
        MOVE(0, 0);
        delay(500);
        digitalWrite(pin_signalForB, HIGH);
        delay(50);
        delay(12500);
        return 3;
    }
    else if ((someBlack() >= 3) && isBlack(sensor[0]) && !isBlack(sensor[8]) &&
             (flag == 3)) {//C地点
        GO(s);
        delay(500);
        GO(f);
        delay(200); // 適当に増やす
        MOVE(-150, 150);
        while (someBlack() >= 1) {}
        delay(100);
        while (!isBlack(sensor[4]) && !isBlack(sensor[3])) {}
        MOVE(0, 0);
        delay(500);
        return 4;
    }
    else if ((someBlack() >= 4) && (isBlack(sensor[3]) || isBlack(sensor[5])) && (flag == 4)) {//T字路
        event3();
        MOVE(0, 0);
        delay(12000);
        delay(500);
        MOVE(-255, -255);
        delay(1000);
        MOVE(-250, 250);
        while (someBlack() >= 1) {}
        while (someBlack() <= 0) {}
        MOVE(0, 0);
        delay(100);
        return 5;
    }
    else if ((someBlack() >= 6) && (flag == 5)) {//C'地点
        GO(s);
        delay(500);
        GO(f);
        delay(200);
        MOVE(-250, 250);
        while (someBlack() >= 1) {}
        while (someBlack() <= 0) {}
        return 6;
    }
    else if ((someBlack() >= 6) && (flag == 6)) {//A'地点
        while (!timerSignalIn->read()) {    // 信号が来るまで時間を潰す
            MOVE(0, 0);
        }
        delay(200);
        event4();
        return 7;
    }

    return flag;
}

int partytime = 0;

void FlagLight(int flag) {
    for (int i = 0; i < 7; i++) {
        if (i == flag) {
            digitalWrite(LED[i], HIGH);
        }
        else {
            digitalWrite(LED[i], LOW);
        }
    }
    if (flag == 7) {
        if (partytime > 1400) {
            partytime = 0;
        }
        int fase = partytime / 200;
        for (int i = 0; i < 7; i++) {
            if (i == fase) {
                digitalWrite(LED[i], HIGH);
            }
            else {
                digitalWrite(LED[i], LOW);
            }
        }
        partytime++;
    }
}
