#ifndef plineH
#define plineH

const int r = 0;
const int l = 1;
const int f = 2;
const int s = 3;

//const int powerArray[9] = {400, 300, 250, 150, 0, 150, 250, 300, 450};
const int powerArray[9] = {400, 300, 250, 150, 0, 150, 250, 300, 450};
const int standardValue = 250;

//MOVE関数の中で直進とかいちいちMOVE(255,255)って書くのめんどいので。
void GO(int way);

//暴力的なP
void Pline(int Sensors[9]);

#endif
