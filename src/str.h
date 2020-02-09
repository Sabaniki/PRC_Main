#ifndef strH
#define srtH

//通信時の動きを入れるための構造体を定義。ほんとはclass使いたいけどまだよくわかんないから使えない。
struct motion {
    int r;//右モータの出力(-255~255)
    int l;//左モータの出力(-255~255)
    char act[2];//通信終了とかのモータ出力以外の指令を格納する
};

//受け取った配列内の文字が数字かどうかを返す関数。
bool isNum(char ch);

//string型からモータの出力とかの動作を取得する用の関数。
struct motion getfromstr(String str);

#endif
