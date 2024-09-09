#ifndef Stone_h
#define Stone_h

#include "Entity.h"

class Stone: public Entity{

    private:
    string name;

    public:

    Stone(int, int, char, const string&);

    void moveEntity(Map&, int, int) override;

    void drawEntity() override;

    ~Stone();

};


#endif