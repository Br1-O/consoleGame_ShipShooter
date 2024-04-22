#if !defined(FRAME_CPP)
#define FRAME_CPP

    //includes
    #include <stdio.h>
    #include <windows.h>
    #include "../../functions/functions.h"
    #include "../headers/frame.h"
    #include <iostream>

    //definitions
    #include "../headers/colors.h"

    //constructor
    Frame::Frame(int sizeScreenX, int sizeScreenY): 
    _sizeScreenX(sizeScreenX), 
    _sizeScreenY(sizeScreenY){};

    //destructor
    Frame::~Frame(){};

    //Draw screen limits
    void Frame::drawScreenFrame(){

        setColor(PURPLE);

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

    //Display current health
    void Frame::drawHealth(){

        setColor(PURPLE);

        gotoxy(getSizeScreenX()-50, 1);

        printf("%c Health: ", 175);

        setColor(RED);
        for (size_t i = 0; i < getHealth(); i++)
        {
            printf(" %c", 254);
        }

    };

    //Display current hearts
    void Frame::drawHearts(){

        setColor(PURPLE);

        gotoxy(getSizeScreenX()-20, 1);

        printf("%c Lives: ", 175);

        setColor(RED);
        for (size_t i = 0; i < getHearts(); i++)
        {
            printf(" %c", 206);
        }

    };

#endif

