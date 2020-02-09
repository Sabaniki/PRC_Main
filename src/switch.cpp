#include<Arduino.h>
#include"switch.h"
#include"pin.h"

int SWtoFL() {
    int flag = -1;
    for (int i = 0; i < 7; i++) {
        if (digitalRead(SW[i]) == LOW) {
            flag = i;
            if (digitalRead(SW[0]) == LOW) {
                while (digitalRead(SW[0]) == LOW) {
                    if (digitalRead(SW[6]) == LOW) {
                        return 7;
                    }
                }
            }
            break;
        }
    }

    return flag;
}
