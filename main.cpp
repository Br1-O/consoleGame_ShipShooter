//includes
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "./functions/functions.h"
#include "./classes/frame.h"
#include "./classes/ship.h"

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    //game over flag
    bool gameOver = false;

    //initial coord variables
    int x=10, y=10;

    //game frame
    Frame* frame = new Frame(getWindowSize().first,getWindowSize().second);
    frame->drawScreenFrame();

    //initial ship instance
    Ship* ship = new Ship(x, y, 2);
    ship->create();

    //main loop for game
    while (!gameOver)
    {
        //function to hide cursor
        hideCursor();

        ship->move();

        frame->drawHearts();

        //sleep to avoid system overload
        Sleep(30);
    }
    
    return 0;
}

/* COMMAND TO COMPILE FILE WITH PROPER CPP FILES FOR LINKER:

    g++ main.cpp functions/functions.cpp classes/ship.cpp classes/frame.cpp -o main.exe 

*/
