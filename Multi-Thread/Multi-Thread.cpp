// Colton Swartwoudt, Multi-Thread
// Repeatedly prints an ever-increasing int alongside an alphabetical loop.
// On any keypress, the alphabetical loop ceases.
// On pressing the 'a' key, the numerical counter ceases.
// Pressing 'a' before any key results in the termination of both.

#include <iostream>
#include <thread>
#include <conio.h>
#include <Windows.h>

using namespace std;

bool shouldEndThread = false;
int threadVar = 0;
char mainChar = 'a';

void theOtherSide() {
    Sleep(50);
    cout << "Hello from the other side!" << endl;
    Sleep(100);
    while (!shouldEndThread) {
        threadVar++;
        cout << threadVar << " ";
        if (_kbhit() && _getch() == 'a') return;
        Sleep(100);
    }
    return;
}

int main()
{
    thread alternate(theOtherSide);
    Sleep(100);
    cout << "I must have called a thousand times!" << endl;
    while(!_kbhit()) {
        cout << mainChar << " ";
        mainChar++;
        if (mainChar > 'z') mainChar = 'a';
        Sleep(100);
    }
    alternate.join();
    return 0;
}
