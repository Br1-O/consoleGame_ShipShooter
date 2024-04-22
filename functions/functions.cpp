//prophylactic measure to avoid multiple includes
#if !defined(FUNCTIONS_CPP)
#define FUNCTIONS_CPP

    //includes
    #include <stdio.h>
    #include <windows.h>
    #include <cmath>
    #include <utility>
    #include <string>
    #include <iostream>

    //definitions
    #define UP 72
    #define LEFT 75
    #define RIGHT 77
    #define DOWN 80

    //Handle definition to manipulate cursor
    HANDLE getHandle(){
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        return hCon;
    }

    //hide cursor
    void hideCursor(){

        //set visibility of cursor to false
        CONSOLE_CURSOR_INFO cci;
        cci.bVisible = FALSE;

        //setting cursor info
        SetConsoleCursorInfo(getHandle(), &cci);
    };

    //set console title
    void setTitle(std::string title){
        SetConsoleTitleA(title.c_str());
    };

    //Set font color
    void setColor(int color){
        SetConsoleTextAttribute(getHandle(), color);
    };

    //get size of screen (returns X value, Y value)
    std::pair<int, int> getWindowSize() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(getHandle(), &csbi);
        return std::make_pair(csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
    }

    //move cursor to desired coord
    void gotoxy(int x, int y){

        //assignation of coordinates for cursor into COORD struct of windows
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;

        //setting coordinates into cursor's position
        SetConsoleCursorPosition(getHandle(), dwPos);
    }

    //control movement via key input
    void ctrlMovement(int* x, int* y, size_t sizeX, size_t sizeY, char key){
        //control flow for movement of cursor via keys w/ control for size element, to limit element into screen frame 
        //(the +X are to consider frame value & object size)
        switch (key) {
            case 'a':
            case LEFT:
                if ((*x) > ceil(sizeX/2)) // Adjusted condition to prevent going beyond frame
                    (*x)--;  // Move left
                break;
            case 'd':
            case RIGHT:
                if (( getWindowSize().first - (*x)) > ceil(sizeX/2+5)) // Adjusted condition for right movement
                    (*x)++;  // Move right
                break;
            case 'w':
            case UP:
                if ((*y) > (ceil(sizeY/2)+1)) // Adjusted condition to prevent going beyond frame
                    (*y)--;  // Move up
                break;
            case 's':
            case DOWN:
                if (( getWindowSize().second - (*y)) > ceil(sizeY/2+3)) // Adjusted condition for down movement
                    (*y)++;  // Move down
            default:
                break;
        }
    }

#endif


