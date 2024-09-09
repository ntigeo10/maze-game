#include "Engine.h"


Engine::Engine(const string& filename): maze(filename), loukas(nullptr), mpampis(nullptr), stone(nullptr) {};

Engine::~Engine(){

    delete loukas;
    delete mpampis;
    delete stone;

}


void Engine::draw(){

    maze.drawMap();
    loukas->drawEntity();
    mpampis->drawEntity();
    stone->drawEntity();

}

void Engine::moveMpampis(){

        if(mpampis->getX() == stone->getX() && mpampis->getY() < stone->getY()){
            mpampis->moveEntity(maze, 0, 1);
        }
        else if(mpampis->getX() == stone->getX() && mpampis->getY() > stone->getY()){
            mpampis->moveEntity(maze, 0, -1);
        }
        else if(mpampis->getX() < stone->getX() && mpampis->getY() == stone->getY()){
            mpampis->moveEntity(maze, 1, 0);
        }
        else if(mpampis->getX() > stone->getX() && mpampis->getY() == stone->getY()){
            mpampis->moveEntity(maze, -1, 0);
        }
        else if(mpampis->getX() < stone->getX() && mpampis->getY() < stone->getY() || mpampis->getX() < stone->getX() && mpampis->getY() > stone->getY()){
            mpampis->moveEntity(maze, 1, 0);
        }
        else if(mpampis->getX() > stone->getX() && mpampis->getY() < stone->getY() || mpampis->getX() > stone->getX() && mpampis->getY() > stone->getY()){
            mpampis->moveEntity(maze, -1, 0);
        }

}



void Engine::handlePlayerInput(){

    int ch = getch();

    switch(ch){

        case KEY_UP:
            loukas->moveEntity(maze, 0, -1);
            moveMpampis();
            break;
        case KEY_DOWN:
            loukas->moveEntity(maze, 0, 1);
            moveMpampis();
            break;
        case KEY_RIGHT:
            loukas->moveEntity(maze, 1, 0);
            moveMpampis();
            break;
        case KEY_LEFT:
            loukas->moveEntity(maze, -1, 0);
            moveMpampis();
            break;
        case ' ':
            moveMpampis();
            break;
        case 27:
            endwin();
            exit(0);
        default:
            break;                        

    }

}


void Engine::initialize(){
    srand(time(nullptr));


    int width = maze.getX();
    int height = maze.getY();

    int loukasX, loukasY, mpampisX, mpampisY, stoneX, stoneY;

    do{
        loukasX = rand() % width;
        loukasY = rand() % height;
    }while (maze.isValidMove(loukasX, loukasY) == false && maze.isWall(loukasX, loukasY) == true);

    do{
        mpampisX = rand() % width;
        mpampisY = rand() % height;
    }while (maze.isValidMove(mpampisX, mpampisY) == false && maze.isWall(mpampisX, mpampisY) == true);

    do{
        stoneX = rand() % width;
        stoneY = rand() % height;
    }while (maze.isValidMove(stoneX, stoneY) == false && maze.isWall(stoneX, stoneY) == true);
    loukas = new Loukas(loukasX, loukasY, 'L', "Loukas Malfoy");
    mpampis = new Mpampis(mpampisX, mpampisY, 'M', "Mpampis Poteridis");
    stone = new Stone(stoneX, stoneY, '#', "Magic Stone");

}

void Engine::play(){

    initscr();
    keypad(stdscr, 1);
    curs_set(0);
    srand(time(nullptr));
    start_color();
    int tmptimer;
    while(true){
        clear();
        draw();

        handlePlayerInput();
        tmptimer = rand() % 20;
        if(tmptimer == 10){

            stone->moveEntity(maze, 0, 0);

        }

        if(loukas->getX() == mpampis->getX() && loukas->getY() == mpampis->getY()){
            clear();
            printw("Loukas hit Mpampis! Press any button to close the game.");
            refresh();
            getch();
            endwin();
            break;

        }
        if(loukas->getX() == stone->getX() && loukas->getY() == stone->getY()){
            clear();
            printw("Loukas has found the gem and he is the winner of the game! Press any button to close the game.");
            refresh();
            getch();
            endwin();
            break;

        }
        if(mpampis->getX() == stone->getX() && mpampis->getY() == stone->getY()){

            clear();
            printw("Mpampis has found the gem and he is the winner of the game! Press any button to close the game.");
            refresh();
            getch();
            endwin();
            break;

        }

        refresh();
    }

}



