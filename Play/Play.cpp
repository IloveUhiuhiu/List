#include <iostream>
#include <Windows.h>
#include "mmsystem.h"
using namespace std;
int main() {
    PlaySound(TEXT("Roi-Toi-Luon-Nal.mp3"), NULL, SND_FILENAME | SND_ASYNC);
    system("pause");
    return 0;
}