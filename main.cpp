//includes
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "./functions/functions.h"
#include "./classes/headers/frame.h"
#include "./classes/headers/ship.h"

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    //game title
    setTitle("Battle Ships v1.0");

    //game over flag
    bool gameOver = false;

    //initial coord variables
    int x=10, y=10;

    //game frame
    Frame* frame = new Frame(getWindowSize().first,getWindowSize().second);
    frame->drawScreenFrame();

    //initial ship instance
    Ship* ship = new Ship(x, y, 2, &gameOver);
    ship->create();

    //main loop for game
    while (!gameOver)
    {
        //hide cursor
        hideCursor();

        //check ship movement
        ship->move();

        //draw frame data
        frame->drawHealth(ship->getHealth());
        frame->drawHearts(ship->getHearts());

        //sleep to avoid system overload
        Sleep(30);
    }

    
    return 0;
}

/* COMMAND TO COMPILE FILE WITH PROPER CPP FILES FOR LINKER:

    g++ main.cpp functions/functions.cpp classes/src/ship.cpp classes/src/frame.cpp classes/src/asteroid.cpp -o main.exe 

*/
