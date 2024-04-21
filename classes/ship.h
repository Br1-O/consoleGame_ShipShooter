#if !defined(SHIP_H)
#define SHIP_H

class Ship
{
    private:
        //coordinates
        int _x = 40;
        int _y = 40;
        int _skin = 1;
        size_t sizeX = 8;
        size_t sizeY = 4;

    public:
        //generic constructor
        Ship();

        //constructor w/ member initializer list
        Ship(int x, int y, int skin);

        //destructor
        ~Ship();

        //getters
        size_t getSizeX(){
            return sizeX;
        }
        size_t getSizeY(){
            return sizeY;
        }

        //methods to handle the ship display in screen

        //function to show ship into screen
        void create();

        //function to show ship into screen
        void erase();

        //function to show ship into screen
        void move();
};

#endif
