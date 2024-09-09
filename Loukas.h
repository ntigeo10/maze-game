#ifndef Loukas_h
#define Loukas_h

#include "Entity.h"


class Loukas : public Entity{

    private:

    string name;

    public:

    Loukas(int, int, char, const string&);

    void moveEntity(Map&, int, int) override;

    void drawEntity() override;

    ~Loukas();


};



#endif
