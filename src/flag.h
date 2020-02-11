#ifndef flagH
#define flagH

#include "DigitalPin.h"

//flagH関連の動作をする関数。交差点とかの動作はこれの中身をいじる。
int FlagEvent(int flag, DigitalPin* timerSignalIn, DigitalPin *timerSignalOut);

//flagの値をもとにスイッチのライトを光らせる。
void FlagLight(int flag);

#endif
