#if !defined(ASTEROID_H)
#define ASTEROID_H

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../../functions/functions.h"
#include "./entity.h"
#include "./ship.h"

class Asteroid : public Entity
{
private:
    int _x = 0;
    int _y = 0;
    size_t _width = 1;
    size_t _height = 1;

public:

    //generic constructor
    Asteroid();

    //constructor w/ member initializer list
    Asteroid(int x, int y);

    //constructor w/ member initializer list
    Asteroid(int x, int y, size_t width, size_t height);

    //destructor
    ~Asteroid();

    //getters
    int getX() const override{
        return _x;
    };
    int getY() const override{
        return _x;
    };
    size_t getWidth() const override{
        return _width;
    }
    size_t getHeight() const override{
        return _height;
    }

    //handle the asteroids display

    //shows asteroid
    virtual void create() const override;
    //erases asteroid
    virtual void erase() const override;
    //moves asteroid
    virtual void move() override;

    //handle asteroid behavior
    
    //collision
    void impact(Ship* ship);

};

#endif
