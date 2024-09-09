#ifndef Engine_h
#define Engine_h

#include "Entity.h"
#include "Stone.h"
#include "Mpampis.h"
#include "Loukas.h"


using namespace std;


class Engine{

    private:
    Map maze;
    Loukas* loukas;
    Mpampis* mpampis;
    Stone* stone;


    public:

    Engine(const string& filename);


    void initialize();

    void handlePlayerInput();

    void play();

    void draw();

    void moveMpampis();

    ~Engine();


};




#endif