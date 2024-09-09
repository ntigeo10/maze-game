#ifndef Entity_h
#define Entity_h

#include <string>

#include "Map.h"


using namespace std;

class Entity{

    protected:

    int posX;
    int posY;
    char symbol;

    public:

    Entity(int, int, char);

    void setPosition(int, int);
    virtual void moveEntity(Map&, int, int) = 0;
    virtual void drawEntity() = 0;

    int getX();
    int getY();
    char getSymbol();

    virtual ~Entity();



};


#endif