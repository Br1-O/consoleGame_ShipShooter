#if !defined(ASTEROID_CPP)
#define ASTEROID_CPP

//includes
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <cstddef>
#include "../headers/asteroid.h"
#include "../headers/ship.h"
#include "../../functions/functions.h"

//definitions
#include "../headers/colors.h"

//generic constructor
Asteroid::Asteroid(){};

//constructor w/ member initializer list
Asteroid::Asteroid(int x, int y):
_x(x), _y(y){};

//constructor w/ member initializer list
Asteroid::Asteroid(int x, int y, size_t width, size_t height):
_x(x), _y(y), _width(width), _height(height){};

//destructor
Asteroid::~Asteroid(){};

//handle the asteroids display

//shows asteroid
void Asteroid::create() const {
    //set color
    setColor(RED);
    //initial drawing
    gotoxy(_x, _y); printf("%C", 79);
};

//erases asteroid
void Asteroid::erase() const {
    gotoxy(_x, _y); printf(" ");
};

//moves asteroid
void Asteroid::move() {
    //erase at current position
    erase();
    //falling effect
    _y++;

    //once it reaches limit, send it to top at _X random
    if (_y > getWindowSize().second -3)
    {
        erase();
        //random between (max size - frame borders) + left X frame size
        _x = (rand()%(getWindowSize().first - 4))+2;
        _y = 3;
    } 

    //display at new position
    create();
};

//collision
void Asteroid::impact(Ship* ship){
    //compare coordinates with ship object coordinates + size

    if((_x >= ship->getX() && _x <= ship->getX()+ship->getWidth()) && (_y >= ship->getY() && _y <= ship->getY()+ship->getHeight())){
        ship->explode();
        erase();
        //random between (max size - frame borders) + left X frame size
        _x = (rand()%(getWindowSize().first - 4))+2;
        _y = 3;
    }
};

#endif
