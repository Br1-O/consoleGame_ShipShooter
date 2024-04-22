//includes
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "./functions/functions.h"
#include "./classes/headers/frame.h"
#include "./classes/headers/ship.h"
#include "./classes/headers/asteroid.h"

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    //game title
    setTitle("Battle Ships v1.0");

    //game over flag
    bool gameOver = false;

    //initial coord variables
    int x=20, y=20;

    //initial ship instance
    Ship* ship = new Ship(x, y, 2, &gameOver);
    ship->create();

    //asteroid instance
    Asteroid* ast1 = new Asteroid(10, 3);
    Asteroid* ast2 = new Asteroid(5, 5);
    Asteroid* ast3 = new Asteroid(105, 4);
    
    //game frame
    Frame* frame = new Frame(getWindowSize().first,getWindowSize().second);
    frame->drawScreenFrame();

    //main loop for game
    while (!gameOver)
    {
        //hide cursor
        hideCursor();

        //asteroids falling
        ast1->move(); ast1->impact(ship);
        ast2->move(); ast2->impact(ship);
        ast3->move(); ast3->impact(ship);

        //check ship movement
        ship->move();

        //draw frame data
        frame->drawInfo(ship->getX(), ship->getY());
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
