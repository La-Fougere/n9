// Modifiez ce chemin pour donner le votre
#include "C:\Users\VotreUtilisateur\Documents\Arduino\fuck-peggy\peggy\arduinolib\Peggy2\Peggy2.h"
#include "C:\Users\VotreUtilisateur\Documents\Arduino\fuck-peggy\peggy\arduinolib\Peggy2\Peggy2.cpp"

Peggy2 frame1;
Peggy2 frame2;
Peggy2 frame3;
Peggy2 frame4;
Peggy2 frame5;
Peggy2 frame6;
Peggy2 emptyframe;

struct Pixel {
    byte x;
    byte y;
};

// Les varibales de chaque frame de l'écran LED

Pixel frameData1[] = {
  {5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{6,10},{6,17},{6,18},{6,19},{7,10},{7,19},{7,20},{8,9},{8,10},{8,11},{8,20},{9,9},{9,21},{10,3},{10,4},{10,5},{10,6},{10,7},{10,8},{10,9},{10,10},{10,21},{11,2},{11,21},{12,3},{12,4},{12,5},{12,6},{12,7},{12,8},{12,9},{12,10},{12,21},{13,9},{13,21},{14,9},{14,20},{15,10},{15,11},{15,12},{15,13},{15,19},{15,20},{16,13},{16,18},{17,12},{17,16},{17,17},{18,11},{18,14},{18,15},{19,11},{19,13},{19,14},{20,11},{20,12}
};

Pixel frameData2[] = {
  {5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{6,10},{6,17},{6,18},{6,19},{7,10},{7,19},{7,20},{8,9},{8,10},{8,11},{8,20},{9,9},{9,21},{10,5},{10,6},{10,7},{10,8},{10,9},{10,10},{10,21},{11,4},{11,21},{12,5},{12,6},{12,7},{12,8},{12,9},{12,10},{12,21},{13,9},{13,21},{14,9},{14,20},{15,10},{15,11},{15,12},{15,13},{15,19},{15,20},{16,13},{16,18},{17,11},{17,12},{17,16},{17,17},{18,11},{18,14},{18,15},{19,11},{19,12},{19,13},{19,14}
};

Pixel frameData3[] = {
  {5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{6,10},{6,17},{6,18},{6,19},{7,10},{7,19},{7,20},{8,9},{8,10},{8,11},{8,20},{9,9},{9,21},{10,6},{10,7},{10,8},{10,9},{10,10},{10,21},{11,5},{11,21},{12,6},{12,7},{12,8},{12,9},{12,10},{12,21},{13,9},{13,21},{14,9},{14,20},{15,10},{15,11},{15,12},{15,13},{15,19},{15,20},{16,11},{16,12},{16,13},{16,18},{17,11},{17,16},{17,17},{18,11},{18,14},{18,15},{19,12},{19,13},{19,14}
};

Pixel frameData4[] = {
  {5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{6,10},{6,17},{6,18},{6,19},{7,10},{7,19},{7,20},{8,9},{8,10},{8,11},{8,20},{9,9},{9,21},{10,7},{10,8},{10,9},{10,10},{10,21},{11,6},{11,21},{12,7},{12,8},{12,9},{12,10},{12,21},{13,9},{13,21},{14,9},{14,20},{15,10},{15,11},{15,12},{15,13},{15,19},{15,20},{16,11},{16,13},{16,18},{17,11},{17,16},{17,17},{18,12},{18,13},{18,14},{18,15}
};

Pixel frameData5[] = {
  {5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{6,10},{6,17},{6,18},{6,19},{7,10},{7,19},{7,20},{8,9},{8,10},{8,11},{8,20},{9,9},{9,21},{10,8},{10,9},{10,10},{10,21},{11,7},{11,21},{12,8},{12,9},{12,10},{12,21},{13,9},{13,21},{14,9},{14,20},{15,10},{15,11},{15,12},{15,13},{15,19},{15,20},{16,11},{16,18},{17,12},{17,13},{17,16},{17,17},{18,14},{18,15}
};

Pixel frameData6[] = {
  {5,11},{5,12},{5,13},{5,14},{5,15},{5,16},{6,10},{6,17},{6,18},{6,19},{7,10},{7,19},{7,20},{8,9},{8,10},{8,11},{8,20},{9,9},{9,21},{10,9},{10,10},{10,21},{11,8},{11,21},{12,9},{12,10},{12,21},{13,9},{13,21},{14,9},{14,20},{15,10},{15,11},{15,12},{15,13},{15,19},{15,20},{16,11},{16,18},{17,12},{17,13},{17,16},{17,17},{18,14},{18,15}
};

const int numFrameData1 = sizeof(frameData1) / sizeof(frameData1[0]);
const int numFrameData2 = sizeof(frameData2) / sizeof(frameData2[0]);
const int numFrameData3 = sizeof(frameData3) / sizeof(frameData3[0]);
const int numFrameData4 = sizeof(frameData4) / sizeof(frameData4[0]);
const int numFrameData5 = sizeof(frameData5) / sizeof(frameData5[0]);
const int numFrameData6 = sizeof(frameData6) / sizeof(frameData6[0]);

void setup() {
    frame1.HardwareInit();

    frame1.Clear();
    frame2.Clear();
    frame3.Clear();
    frame4.Clear();
    frame5.Clear();
    frame6.Clear();
    emptyframe.Clear();

    for (int i = 0; i < numFrameData1; i++) {frame1.SetPoint(frameData1[i].x, frameData1[i].y);}
    for (int i = 0; i < numFrameData2; i++) {frame2.SetPoint(frameData2[i].x, frameData2[i].y);}
    for (int i = 0; i < numFrameData3; i++) {frame3.SetPoint(frameData3[i].x, frameData3[i].y);}
    for (int i = 0; i < numFrameData4; i++) {frame4.SetPoint(frameData4[i].x, frameData4[i].y);}
    for (int i = 0; i < numFrameData5; i++) {frame5.SetPoint(frameData5[i].x, frameData5[i].y);}
    for (int i = 0; i < numFrameData6; i++) {frame6.SetPoint(frameData6[i].x, frameData6[i].y);}
}

void loop() {
    frame6.RefreshAll(1000);
    frame5.RefreshAll(100);
    frame4.RefreshAll(100);
    frame3.RefreshAll(100);
    frame2.RefreshAll(100);
    frame1.RefreshAll(3000);
    frame2.RefreshAll(100);
    frame3.RefreshAll(100);
    frame4.RefreshAll(100);
    frame5.RefreshAll(100);
    frame6.RefreshAll(200);
    emptyframe.RefreshAll(3000);
}
