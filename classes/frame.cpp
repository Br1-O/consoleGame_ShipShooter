#if !defined(FRAME_CPP)
#define FRAME_CPP

    //includes
    #include <stdio.h>
    #include <windows.h>
    #include "../functions/functions.h"
    #include "../classes/frame.h"
    #include <iostream>

    //constructor
    Frame::Frame(int sizeScreenX, int sizeScreenY): 
    _sizeScreenX(sizeScreenX), 
    _sizeScreenY(sizeScreenY){};

    //destructor
    Frame::~Frame(){};

    //function to draw screen limits
    void Frame::drawScreenFrame(){
        for (size_t x = 2; x < getSizeScreenX(); x++)
        {
            //top screen line
            gotoxy(x, 0);
            printf("%c", 205);
            //top game limit line
            gotoxy(x, 2);
            printf("%c", 205);
            //bottom limit line
            gotoxy(x, getSizeScreenY()-1);
            printf("%c", 205);
        }

        for (size_t y = 1; y < getSizeScreenY(); y++)
        {
            //left limit line
            gotoxy(1, y);
            printf("%c", 186);
            //right limit line
            gotoxy(getSizeScreenX()-1, y);
            printf("%c", 186);
        }

        //left top corner
        gotoxy(1,0); printf("%c", 201);
        //left bottom corner
        gotoxy(1,getSizeScreenY()-1); printf("%c", 200);
        //right top corner
        gotoxy(getSizeScreenX()-1,0); printf("%c", 187);
        //right bottom corner
        gotoxy(getSizeScreenX()-1, getSizeScreenY()-1); printf("%c", 188);
    };

    //function to display current hearts
    void Frame::drawHearts(){

        gotoxy(getSizeScreenX()-20, 1);

        printf("%c Salud: ", 254);

        for (size_t i = 0; i < getHearts(); i++)
        {
            printf(" %c", 206);
        }

    };

#endif

