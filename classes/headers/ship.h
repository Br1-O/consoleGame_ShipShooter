#if !defined(SHIP_H)
#define SHIP_H

#include "./entity.h"

class Ship : public Entity
{
    private:
        //coordinates
        int _x = 40;
        int _y = 40;
        int _skin = 1;
        size_t width = 8;
        size_t height = 4;

    public:
        //generic constructor
        Ship();

        //constructor w/ member initializer list
        Ship(int x, int y, int skin);

        //destructor
        ~Ship();

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

        //methods to handle the ship display in screen

        //function to show ship into screen
        void create() const override;

        //function to show ship into screen
        void erase() const override;

        //function to show ship into screen
        void move() override;
};

#endif
