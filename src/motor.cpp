#include"motor.h"
#include"pin.h"
#include<Arduino.h>

void MOVE(int MspL, int MspR) {
/*
  bool isMinL = false;
  bool isMinR = false;

  if((MspR == 0) && (MspL == 0)){
    analogWrite(pin_motorR1,LOW);
    analogWrite(pin_motorR2,LOW);
    analogWrite(pin_motorL1,LOW);
    analogWrite(pin_motorL2,LOW);
  }
  if(MspL <= 0){
    MspL *= -1;
    isMinL = true;
  }
  if(MspR <= 0){
    MspR *= -1;
    isMinR = true;
  }*/

    if (MspL < 0) {
        MspL *= -1;
        analogWrite(pin_motorL1, LOW);
        analogWrite(pin_motorL2, MspL);
        digitalWrite(pin_trainMotor, LOW);

    }
    else if (MspL > 0) {
        analogWrite(pin_motorL1, MspL);
        analogWrite(pin_motorL2, LOW);
        digitalWrite(pin_trainMotor, HIGH);

    }
    else if (MspL == 0) {
        analogWrite(pin_motorL1, LOW);
        analogWrite(pin_motorL2, LOW);
        digitalWrite(pin_trainMotor, LOW);
    }

    if (MspR < 0) {
        MspR *= -1;
        analogWrite(pin_motorR1, LOW);
        analogWrite(pin_motorR2, MspR);
        digitalWrite(pin_trainMotor, LOW);
    }
    else if (MspR > 0) {
        analogWrite(pin_motorR1, MspR);
        analogWrite(pin_motorR2, LOW);
        digitalWrite(pin_trainMotor, HIGH);

    }
    else if (MspR == 0) {
        analogWrite(pin_motorR1, LOW);
        analogWrite(pin_motorR2, LOW);
        digitalWrite(pin_trainMotor, LOW);
    }

}
