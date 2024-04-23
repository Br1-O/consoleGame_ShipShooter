//includes
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "./functions/functions.h"
#include "./classes/headers/frame.h"
#include "./classes/headers/ship.h"
#include "./classes/headers/asteroid.h"
#include "./classes/headers/projectile.h"
#include <list>


//list to group asteroids
std::list <Asteroid*> AST;
//iterator of asteroids list
std::list <Asteroid*>::iterator it;

//spawn asteroid instances
void spawnAst(std::list <Asteroid*>* AST){
    int x = (rand()%(getWindowSize().first - 4))+2;
    int y = 3;

    //push new instance of asteroid to list
    (*AST).push_back(new Asteroid(x, y));
};

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main(int argc, char const *argv[])
{
    //game title
    setTitle("Battle Ships v1.0");
    //game over flag
    bool gameOver = false;
    //game frame
    Frame* frame = new Frame(getWindowSize().first,getWindowSize().second);
    frame->drawScreenFrame();
    //initial coord variables
    int x=55, y=20;
    //spawner flag
    int spawnTimer = 5;
    //point variable
    int points = 0;

    //initial ship instance
    Ship* ship = new Ship(x, y, 2, &gameOver);
    ship->create();

    //main loop for game
    while (!gameOver)
    {
        //hide cursor
        hideCursor();
        
        //spawn of asteroids
        spawnTimer++;
        if (spawnTimer%50==0)
        {
            //spawn new asteroid
            spawnAst(&AST);
            points+=50;
        }
        
        //Drawing asteroids
        for (it = AST.begin(); it != AST.end(); it++)
        {
            (*(it))->move();
            (*(it))->impact(ship);

            for (ship->it = ship->shots.begin(); ship->it != ship->shots.end(); ship->it++)
            {

                //check if projectile hits an asteroid
                //check collision
                 if (((*ship->it)->getX() == (*it)->getX()) && 
                    ((*ship->it)->getY() == (*it)->getY() || (*ship->it)->getY() == (*it)->getY() + 1))
                {
                    //erase projectile from screen
                    (*(ship->it))->erase();
                    //free heap memory from projectile instance
                    delete (*(ship->it));
                    //erase projectile from list
                    ship->it = ship->shots.erase(ship->it);

                    //erase asteroid from screen
                    (*it)->erase();
                    //free heap memory from asteroid instance
                    delete ((*it));
                    //erase asteroid from list
                    it = AST.erase(it);

                    points+=500;
                }
            }
        };

        //Drawing projectiles shot by ship
        for (ship->it = ship->shots.begin(); ship->it != ship->shots.end(); ship->it++)
        {
            (*(ship->it))->move();

            //check if projectile is at the top limit
            if ((*(ship->it))->isOut())
            {
                //once it reaches top limit, erase it
                (*(ship->it))->erase();
                //free heap memory from projectile instance
                delete (*(ship->it));
                //erase projectile from list
                ship->it = ship->shots.erase(ship->it);
            }
        };

        //check ship movement
        ship->move();

        //draw frame data
        frame->drawInfo(points, spawnTimer);
        frame->drawHealth(ship->getHealth());
        frame->drawHearts(ship->getHearts());

        //sleep to avoid system overload
        Sleep(100);
    }

    
    return 0;
}

/* COMMAND TO COMPILE FILE WITH PROPER CPP FILES FOR LINKER:

    g++ main.cpp functions/functions.cpp classes/src/ship.cpp classes/src/frame.cpp classes/src/asteroid.cpp classes/src/projectile.cpp -o main.exe 

*/
