#include "Loukas.h"

Loukas::Loukas(int x, int y, char symbol, const string& name) : Entity(x, y, symbol), name(name) {};


void Loukas::moveEntity(Map& map, int x, int y){

    int newX = this->getX() + x;
    int newY = this->getY() + y;


    if(map.isValidMove(newX, newY) == true){

        this->setPosition(newX, newY);
    }


}

void Loukas::drawEntity(){

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvaddch(this->getY(), this->getX(), this->getSymbol());
    attroff(COLOR_PAIR(1)); 

}

Loukas::~Loukas(){

    
}