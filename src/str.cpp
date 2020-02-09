#include<Arduino.h>
#include"str.h"

/*
string型から数値を取得する用の関数
*/

bool isNum(char ch) {
    if ((0 <= ch) && (ch <= 9)) {
        return true;
    }
    return false;
}

struct motion getfromstr(String str) {
    int num = 0;
    bool isMinas = false;
    struct motion answer;

    num = str.indexOf("L:") + 2;
    if ((str[num] - 48) == '-') {
        isMinas = true;
        num++;
    }//L:-〇〇のときに出てきた値に-をかける。
    answer.l = (str[num] - 48) * 100 + (str[num + 1] - 48) * 10 + (str[num + 2] - 48);
    if (isMinas == true) {
        answer.l = answer.l * -1;
        isMinas = false;
    }

    num = str.indexOf("R:") + 2;
    if ((str[num] - 48) == '-') {
        isMinas = true;
        num++;
    }//R:-〇〇のときに出てきた値に-をかける。
    answer.r = (str[num] - 48) * 100 + (str[num + 1] - 48) * 10 + (str[num + 2] - 48);
    if (isMinas == true) {
        answer.l = answer.l * -1;
        isMinas = false;
    }

    num = str.indexOf("E:") + 2;
    answer.act[0] = str[num];
    answer.act[1] = str[num + 1];

    return answer;
}
