#include "Mpampis.h"


Mpampis::Mpampis(int x, int y, char symbol, const string& name) : Entity(x, y, symbol), name(name) {};


void Mpampis::moveEntity(Map& map, int x, int y){

    int newX = this->getX() + x;
    int newY = this->getY() + y;


    if(map.isValidMove(newX, newY) == true){

        this->setPosition(newX, newY);
    }


}


void Mpampis::drawEntity(){

    init_pair(2, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    mvaddch(this->getY(), this->getX(), this->getSymbol());
    attroff(COLOR_PAIR(2)); 


}


Mpampis::~Mpampis(){



}