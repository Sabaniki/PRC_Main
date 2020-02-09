#include"pid.h"
#include"sensor.h"
#include"motor.h"
#include"pin.h"
#include<Arduino.h>
/*
void PID(int kp, int ki, int kd,int MotorSpeed){
  //変数定義
  int P,I,D;
  static int SenR3,SenR2,SenR1,SenC,SenL1,SenL2,SenL3;
  static int now,old,dif;
  int nt,ot,dt;

  int x;

  //nowの中身が空だとoldに代入しようがないので飛ばす。
  if(now != NULL){
    old = now;
    ot = nt;
  }

  ValueUpdate( &SenR3, &SenR2, &SenR1, &SenL1, &SenL2, &SenL3 );
  //左半分のセンサの値をマイナスとしてすべてのセンサの値を足す。
  //now 及び old は線が右にある度を示す。
  now = - ( SenL3 + SenL2 + SenL1 ) + ( SenR1 + SenR2 + SenR3 );

  nt = millis();

  if(ot == NULL){
    return;
  }

  dt = nt - ot;
  dif = now - old;

  P = now * kp;//比例
  I = dif * dt * ki;//積分
  D = ( dif * kd ) / dt;//微分

  x = P+I+D;

  MOVE( MotorSpeed - x , MotorSpeed + x );
}
*/
