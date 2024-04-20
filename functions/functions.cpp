//prophylactic measure to avoid multiple includes
#if !defined(FUNCTIONS_CPP)
#define FUNCTIONS_CPP

    //includes
    #include <stdio.h>
    #include <windows.h>

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
    void ctrlMovement(int x, int y, char key){
            //control flow for movement of cursor via keys
            if (key == 'a' || key == IZQUIERDA)
            {
                x--;
            }
            if (key == 'd' || key == DERECHA)
            {
                x++;
            }
            if (key == 'w' || key == ARRIBA)
            {
                y--;
            }
            if (key == 's' || key == ABAJO)
            {
                y++;
            }
    }


#endif


