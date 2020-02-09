#ifndef sensH
#define sensH

//多分要らない子
//void ValueUpdate(int *SenL3,int *SenL2,int *SenL1,int *SenR1,int *SenR2,int *SenR3);

//そのピンに対応したセンサが黒を読んでいるかどうかを返す関数
bool isBlack(int pin);

//黒の総数を数える関数
int someBlack();

#endif
