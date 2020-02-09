//
// Created by 澤田開杜 on 2020/02/09.
//

#include"pin.h"
#include"motor.h"
#include"sensor.h"
#include"Pline.h"
#include"event.h"
#include"str.h"
#include"pid.h"
#include"flag.h"
#include"switch.h"
#include "DigitalPin.h"

#define kp 10
#define ki 0
#define kd 0
#define MotorSpeed 150

int flag = -1;

void setup() {
    //Serial.begin(9600);
    pinsetup();
    FlagLight(0);
    //while(digitalRead(pin_SW0) == HIGH){delay(1);}
    //Serial.print(flag);
    //Serial.println("into while");
    digitalWrite(pin_RX, LOW);
    digitalWrite(pin_TX, LOW);
    while (flag == -1) {
        flag = SWtoFL();
        //Serial.println(flag);
    }
    //Serial.print(flag);
    //Serial.println("exit while");

}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void loop() {
    // for(int i = 0;i < 9;i++){
    //   Serial.print(isBlack(sensor[i]));
    //   Serial.print(" ");
    // }
    // Serial.println(" ");
    // Serial.println("左折");
    // MOVE(-255,255);
    // delay(1000);
    // Serial.println("停止");
    // MOVE(0,0);
    // delay(500);
    // Serial.println("右折");
    // MOVE(255,-255);
    // delay(1000);
    // Serial.println("停止");
    // MOVE(0,0);
    // delay(500);
    auto timerSignalOut = DigitalPin(pin_timerSignalOut, OUTPUT);
    auto timerSignalIn = DigitalPin(pin_timerSignalIn, INPUT);
    delay(50);
    timerSignalOut.write(HIGH);
    delay(50);
    while (true) {
        //flagの更新とflagごとのイベント
        flag = FlagEvent(flag, &timerSignalIn);

        //flagの値によって光らせるLEDを変える
        FlagLight(flag);

        //ON/OFFライントレース
        Pline(sensor);//*/
    }
}
#pragma clang diagnostic pop
