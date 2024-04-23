#if !defined(PROJECTILE_CPP)
#define PROJECTILE_CPP

//includes
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../headers/projectile.h"
// #include "../headers/asteroid.h"
#include "../../functions/functions.h"

//definitions
#include "../headers/colors.h"

//generic constructor
Projectile::Projectile(){};

//constructor with coordinates
Projectile::Projectile(int x, int y) :
_x(x), _y(y) {};

//constructor with coordinates & size
// Projectile::Projectile(int x, int y, size_t width, size_t height) :
// _x(x), _y(y), _width(width), _height(height) {};

//destructor
Projectile::~Projectile(){};

//methods

//show projectile
void Projectile::create() const {
    //set color
    setColor(BLUE);
    //initial drawing
    gotoxy(_x, _y); printf("%C", 42);
};

//erase projectile
void Projectile::erase() const {
    gotoxy(_x, _y); printf(" ");
};

//move projectile
void Projectile::move() {
    //erase at current position
    erase();
    //movement effect
    _y--;
    //display at new position
    create();
};

//check if it reaches top limit
    bool Projectile::isOut(){
        return (_y < 5) ? true : false;
    };

#endif
