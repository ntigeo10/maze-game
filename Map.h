#ifndef Map_h
#define Map_h


#include <fstream>
#include <vector>
#include <string>
#include <curses.h>

using namespace std;


class Map{


    public:

    vector<string> layout;
    int height;
    int width;
    string filename;


    Map(const string&);

    void readMap(const string&);
    void drawMap();

    int getX();
    int getY();

    bool isValidMove(int, int);
    bool isWall(int, int);

};


#endif