//prophylactic measure to avoid multiple includes
#if !defined(FUNCTIONS_H)
#define FUNCTIONS_H

    //includes
    #include <stdio.h>
    #include <windows.h>
    #include <utility>
    #include <string>
    #include <iostream>


    //definition of cursor handle
    HANDLE getHandle();

    //hide cursor
    void hideCursor();

    //Set console title
    void setTitle(std::string title);

    //Set font color
    void setColor(int color);

    //Get console size (return: .firts = X , .second = Y)
    std::pair<int, int> getWindowSize();

    //Move cursor to desired coord
    void gotoxy(int x, int y);

    //Control movement via key input
    void ctrlMovement(int* x, int* y, size_t sizeX, size_t sizeY, char key);

    //include sound
    void addSound(const std::string& str);

#endif  

