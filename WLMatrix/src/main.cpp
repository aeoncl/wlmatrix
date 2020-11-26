#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "MainController.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#pragma comment(lib, "Ws2_32.lib")
int main()
{
        MainController();
        while(true){
                Sleep(20000);
        }
}