//prophylactic measure to avoid multiple includes
#if !defined(FUNCTIONS_H)
#define FUNCTIONS_H

    //includes
    #include <stdio.h>
    #include <windows.h>
    #include <utility>

    //definition of cursor handle
    HANDLE getHandle();

    //function to hide cursor
    void hideCursor();

    //function to get console size
    std::pair<int, int> getWindowSize();

    //function to move cursor to desired coord
    void gotoxy(int x, int y);

    //function to control movement via key input
    void ctrlMovement(int* x, int* y, size_t sizeX, size_t sizeY, char key);

#endif  

