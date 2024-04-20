//includes
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "./functions/functions.h"

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    //function to hide cursor
    hideCursor();

    //game over flag
    bool gameOver = false;

    //initial coord variables
    int x=10, y=10;

    //initial screen drawing
    gotoxy(x, y);
    printf("*");

    //main loop for game
    while (!gameOver)
    {
        //activate if a key is pressed
        if (kbhit())
        {
            //input for key pressed by user
            char key = getch();

            //erase character in old position
            gotoxy(x, y);
            printf(" ");
            
            ctrlMovement(x, y, key);

            //drawing in new position
            gotoxy(x, y);
            printf("*");
        }
        
        //sleep to avoid system overload
        Sleep(30);
    }
    
    return 0;
}

/* COMMAND TO COMPILE FILE WITH PROPER FUNCTIONS FILE:

    g++ main.cpp functions/functions.cpp -o main.exe 

*/
