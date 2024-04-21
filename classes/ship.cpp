#if !defined(SHIP_CPP)
#define SHIP_CPP

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../functions/functions.h"
#include "../classes/ship.h"
#include "ship.h"

//generic constructor
Ship::Ship(){};

//constructor w/ member initializer list
Ship::Ship(int x, int y, int skin) : 
_x(x), _y(y), _skin(skin) {};

//destructor
Ship::~Ship(){};

//methods to handle the ship display in screen

//function to show ship into screen
void Ship::create(){

    if (_skin == 1)
    {
        gotoxy(_x, _y); printf("%c", 220);
        gotoxy(_x-1, _y+1); printf("%c%c%c", 219, 219, 219);
        gotoxy(_x-4, _y+2); printf(" %c%c%c%c%c%c%c", 204, 219, 219, 219, 219, 219, 185);
        gotoxy(_x-1, _y+3); printf("%c %c", 223, 223);
    }
    else if(_skin == 2)
    {
        gotoxy(_x, _y); printf("%c", 220);
        gotoxy(_x-1, _y+1); printf("%c%c%c", 201, 202, 187);
        gotoxy(_x-4, _y+2); printf(" %c%c%c%c%c%c%c", 204, 205, 206, 205, 206, 205, 185);
        gotoxy(_x-1, _y+3); printf("%c %c", 223, 223);
    }

};

void Ship::erase(){
    gotoxy(_x, _y); printf(" ");
    gotoxy(_x-1, _y+1); printf("   ");
    gotoxy(_x-4, _y+2); printf("        ");
    gotoxy(_x-1, _y+3); printf("   ");
};

void Ship::move(){
        //activate if a key is pressed
        if (kbhit())
        {
            //input for key pressed by user
            char key = getch();

            //erase ship in old position
            erase();
            
            ctrlMovement(&_x, &_y, getSizeX(), getSizeY(), key);

            //drawing ship in new position
            create();
        }
};

#endif