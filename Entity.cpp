#include "Entity.h"


using namespace std;

Entity::Entity(int x, int y, char symbol){

    this->posX = x;
    this->posY = y;
    this->symbol = symbol;

}

void Entity::setPosition(int x, int y){

    this->posX = x;
    this->posY = y;

}

int Entity::getX()
{
    return posX;
}


int Entity::getY(){

    return posY;
}

char Entity::getSymbol(){

    return symbol;
}

Entity::~Entity(){


}

