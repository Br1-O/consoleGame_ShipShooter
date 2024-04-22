#if !defined(ASTEROID_CPP)
#define ASTEROID_CPP

#include "../headers/asteroid.h"

//generic constructor
Asteroid::Asteroid(){};

//constructor w/ member initializer list
Asteroid::Asteroid(int x, int y):
_x(x), _y(y){};

//destructor
Asteroid::~Asteroid(){};

//handle the asteroids display

//shows asteroid
void Asteroid::create() const {
    
};
//erases asteroid
void Asteroid::erase() const {

};
//moves asteroid
void Asteroid::move() {

};

#endif
