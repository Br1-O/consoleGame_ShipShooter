#if !defined(PROJECTILE_H)
#define PROJECTILE_H

//includes
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "./entity.h"

class Projectile : public Entity
{
private:
    int _x;
    int _y;
    size_t _width = 1;
    size_t _height = 1;

public:
    //generic constructor
    Projectile();

    //constructor with coordinates
    Projectile(int x, int y);

    //constructor with coordinates & size
    // Projectile(int x, int y, size_t width, size_t height);

    //destructor
    ~Projectile();

    //getters

    //returns X coordinate
    int getX() const override{
        return _x;
    };
    //returns Y coordinate
    int getY() const override{
        return _y;
    };
    //returns the max size of the class along X axis
    size_t getWidth() const override{
        return _width;
    };
    //returns the max size of the class along Y axis
    size_t getHeight() const override{
        return _height;
    };

    //methods

    //show projectile
    void create() const override;

    //erase projectile
    void erase() const override;

    //move projectile
    void move() override;

    //check if reaches top limit
    bool isOut();

};

#endif