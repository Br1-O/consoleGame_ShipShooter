#if !defined(SHIP_CPP)
#define SHIP_CPP

#include <stdio.h>
#include <windows.h>
#include "../functions/functions.h"

class ship
{
    private:
        //coordinates
        int _x;
        int _y;

        //ship template
        char _template;

    public:
        //constructor w/ member initializer list
        ship(int x, int y) : 
        _x(x), _y(y) {};

        //destructor
        ~ship(){};

        //methods to handle the ship display in screen

        //function to show ship into screen
        void create(){
            gotoxy(_x, _y);
            printf("%c", _template);
        };
        
        void erase(){

        };
        
        void move(){

        };
    

};

#endif