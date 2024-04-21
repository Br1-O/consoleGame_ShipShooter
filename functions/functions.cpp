//prophylactic measure to avoid multiple includes
#if !defined(FUNCTIONS_CPP)
#define FUNCTIONS_CPP

    //includes
    #include <stdio.h>
    #include <windows.h>
    #include <cmath>
    #include <utility>

    //definitions
    #define ARRIBA 72
    #define IZQUIERDA 75
    #define DERECHA 77
    #define ABAJO 80

    //Handle definition to manipulate cursor
    HANDLE getHandle(){
        HANDLE hCon;
        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        return hCon;
    }

    //function to hide cursor
    void hideCursor(){

        //set visibility of cursor to false
        CONSOLE_CURSOR_INFO cci;
        cci.bVisible = FALSE;

        //setting cursor info
        SetConsoleCursorInfo(getHandle(), &cci);
    };

    //function to get size of screen (returns X value, Y value)
    std::pair<int, int> getWindowSize() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(getHandle(), &csbi);
        return std::make_pair(csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
    }

    //function to move cursor to desired coord
    void gotoxy(int x, int y){

        //assignation of coordinates for cursor into COORD struct of windows
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;

        //setting coordinates into cursor's position
        SetConsoleCursorPosition(getHandle(), dwPos);
    }

    //function to control movement via key input
    void ctrlMovement(int* x, int* y, size_t sizeX, size_t sizeY, char key){
        //control flow for movement of cursor via keys w/ control for size element, to limit element into screen frame 
        //(the +2, +3 are to consider frame value)
        if ((key == 'a'|| key == IZQUIERDA) && (*x) > ceil(sizeX/2+2) )
        {
            (*x)--;
        }
        if ((key == 'd' || key == DERECHA) && ( getWindowSize().first - (*x)) > ceil(sizeX/2+2))
        {
            (*x)++;
        }
        if ((key == 'w' || key == ARRIBA) && (*y) > ceil(sizeY/2)+1)
        {
            (*y)--;
        }
        if ((key == 's' || key == ABAJO) && ( getWindowSize().second - (*y)) > ceil(sizeY/2+3))
        {
            (*y)++;
        }
    }

#endif


