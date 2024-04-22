#if !defined(ASTEROID_H)
#define ASTEROID_H

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../../functions/functions.h"
#include "./entity.h"

class Asteroid : public Entity
{
private:
    int _x;
    int _y;
    size_t width;
    size_t height;

public:

    //generic constructor
    Asteroid();

    //constructor w/ member initializer list
    Asteroid(int x, int y);

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
        return width;
    }
    size_t getHeight() const override{
        return height;
    }

    //handle the asteroids display

    //shows asteroid
    virtual void create() const override;
    //erases asteroid
    virtual void erase() const override;
    //moves asteroid
    virtual void move() override;

};

#endif
