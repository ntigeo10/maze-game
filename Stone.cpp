#include "Stone.h"

Stone::Stone(int x, int y, char symbol, const string& name) : Entity(x, y, symbol), name(name) {};

void Stone::moveEntity(Map& map, int x, int y){

    int height = map.getY();
    int width = map.getX();
    int tmpX, tmpY;
    do{
        tmpX = rand() % width;
        tmpY = rand() % height;
    }while (map.isValidMove(tmpX, tmpY) == false && map.isWall(tmpX, tmpY) == true);

    this->setPosition(tmpX, tmpY);

}


void Stone::drawEntity(){

    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    mvaddch(this->getY(), this->getX(), this->getSymbol());
    attroff(COLOR_PAIR(3)); 

}

Stone::~Stone(){


    
}