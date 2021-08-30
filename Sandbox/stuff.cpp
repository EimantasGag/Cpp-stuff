#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>


using namespace std;

int main(){
    timespec dur1, dur2;
    dur1.tv_sec = 0;
    dur1.tv_nsec = 20000000L;
    int i = 0;
    RECT r;
    GetWindowRect(GetConsoleWindow(), &r);
    MoveWindow(GetConsoleWindow(), r.left, r.top, 800, 800, TRUE);
    //SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    //width: 
    //height: 47

    for(int i = 0;i<47;i++){
        cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
    }
    
    //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAAAAAA"; //40
    
    while(1){
        //cout << i << endl;
        if(GetKeyState('A'))
        {
            cout << "Pressed A" << endl;
        }
        if(GetKeyState('C'))
        {
            cout << "Pressed C" << endl;
        }
        i++;
        nanosleep(&dur1, &dur2);
        //system("CLS");
    }
}