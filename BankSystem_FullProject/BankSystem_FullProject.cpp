// BankSystem_FullProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

#include <iomanip>


using namespace std;


// new to learn : new to learn 
// build + preparing the flow and Skelton  of the main screen like  

int main()
{
   // clsMainScreen::ShowMainMenueScreen();
    while(true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        };

    }
    return 0;
}

