#if !defined(SHIP_H)
#define SHIP_H

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "./entity.h"
#include "../headers/projectile.h"
#include <list>

class Ship : public Entity
{
    private:
        //coordinates
        int _x = 40;
        int _y = 40;
        //size&skin
        int _skin = 1;
        size_t _width = 8;
        size_t _height = 4;
        //health&lives
        size_t _health = 10;
        size_t _hearts = 3;
        //game over flag
        bool* _gameOver;

    public:

        //list to group projectiles
        std::list <Projectile*> shots;
        //iterator to iterate through all projectiles
        std::list <Projectile*>::iterator it;
        
        //generic constructor
        Ship();

        //constructor w/ member initializer list
        Ship(int x, int y, int skin, bool* gameOver);

        //destructor
        ~Ship();

        //getters
        int getX() const override{
            return _x;
        };
        int getY() const override{
            return _y;
        };
        size_t getWidth() const override{
            return _width;
        }
        size_t getHeight() const override{
            return _height;
        }
        size_t getHealth(){
            return _health;
        }
        size_t getHearts(){
            return _hearts;
        }

        //handle the ship display in screen

        //show ship
        void create() const override;

        //erase ship
        void erase() const override;

        //move ship
        void move() override;

        //show explosion
        void explode();

        //shoot projectile
        void shoot();
};

#endif
