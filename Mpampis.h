#ifndef Mpampis_h
#define Mpampis_h

#include "Entity.h"


class Mpampis : public Entity{

    private:

    string name;

    public:

    Mpampis(int, int, char, const string&);

    void moveEntity(Map&, int, int) override;

    void drawEntity() override;

    ~Mpampis();


};



#endif