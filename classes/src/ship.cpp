#if !defined(SHIP_CPP)
#define SHIP_CPP

//includes
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../../functions/functions.h"
#include "../headers/ship.h"
#include "../headers/frame.h"

//definitions
#include "../headers/colors.h"
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

//generic constructor
Ship::Ship(){};

//constructor w/ member initializer list
Ship::Ship(int x, int y, int skin, bool* gameOver) : 
_x(x), _y(y), _skin(skin), _gameOver(gameOver) {};

//destructor
Ship::~Ship(){};

//methods to handle the ship display in screen

//show ship
void Ship::create() const{

    setColor(GREEN);

    if (_skin == 1)
    {
        gotoxy(_x, _y); printf("   %c%c  ", 220, 220);
        gotoxy(_x, _y+1); printf("  %c%c%c  ", 219, 219, 219);
        gotoxy(_x, _y+2); printf("%c%c%c%c%c%c%c%c", 204, 219, 219, 219, 219, 219, 219, 185);
        gotoxy(_x, _y+3); printf("  %c  %c  ", 223, 223);
    }
    else if(_skin == 2)
    {
        gotoxy(_x, _y); printf("   %c%c   ", 220, 220);
        gotoxy(_x, _y+1); printf("  %c%c%c%c  ", 201, 202, 202, 187);
        gotoxy(_x, _y+2); printf("%c%c%c%c%c%c%c%c", 204, 205, 206, 205, 205, 206, 205, 185);
        gotoxy(_x, _y+3); printf("  %c  %c  ", 223, 223);
    }

};

//erase ship
void Ship::erase() const{
    gotoxy(_x, _y); printf("        ");
    gotoxy(_x, _y+1); printf("        ");
    gotoxy(_x, _y+2); printf("        ");
    gotoxy(_x, _y+3); printf("        ");
};

//move ship
void Ship::move() {
         // Activate if a key is pressed
    if (_kbhit()) {
        // Input for key pressed by user
        char key = _getch();

        // Erase ship in old position
        erase();

        //control movement via key input
        ctrlMovement(&(_x), &(_y), getWidth(), getHeight(), key);

        if(key == 'p'){
            _skin == 1 ? _skin = 2 : _skin = 1;
        }
        if (key == 'k')
        {
            explode();
        }
        
        // Drawing ship in new position
        create();
    }
};

//show explosion
void Ship::explode(){
    //erase ship
    erase();
    //draw explosion frame 1
    gotoxy(_x,_y);   printf("   **   ");
    gotoxy(_x,_y+1); printf("  ****  ");
    gotoxy(_x,_y+2); printf("  ****  ");
    gotoxy(_x,_y+3); printf("   **   ");
    //sleep to be able to see the animation
    Sleep(200);
    //erase ship
    erase();
    //draw explosion frame 2
    gotoxy(_x,_y);   printf(" * ** * ");
    gotoxy(_x,_y+1); printf("  *  *  ");
    gotoxy(_x,_y+2); printf("  *  *  ");
    gotoxy(_x,_y+3); printf(" * ** * ");
    //sleep to be able to see the animation
    Sleep(200);
    //erase ship
    erase();

    //health&lives
    _health--;

    if (_health == 0)
    {
        _hearts--;
        _health = 10;
    }

    if(_hearts == 0){
        // GenerateConsoleCtrlEvent(CTRL_C_EVENT, 0);
        (*_gameOver) = true;
    }

    //drawing ship
    create();
}

#endif