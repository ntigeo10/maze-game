#include "Map.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <curses.h>


using namespace std;


Map::Map(const string& filename){


    ifstream file(filename);
    if (file.is_open()){
        string line;
        while(getline(file, line)){

            layout.push_back(line);
        }
        file.close();
    }

    height = layout.size();
    width = layout[0].size();

}

void Map::readMap(const string &filename)
{
    ifstream file(filename);
    if (file.is_open()){
        string line;
        while(getline(file, line)){

            layout.push_back(line);
        }
        file.close();
    }

}

void Map::drawMap()
{

    for(vector<string>::const_iterator it = layout.begin(); it != layout.end(); it++)
    {
        string tmp =*it;
        printw("%s \n", tmp.c_str());
    }
}


int Map::getX() {

    return width;

}

int Map::getY(){

    return height;
}

bool Map::isValidMove(int x, int y)
{
    if( x >= 0 && x < width && y >= 0 && y < height){
        return layout[y][x] == '.';
    }
    return false;
}

bool Map::isWall(int x, int y)
{

        if (x >= 0 && x < layout[0].size() && y >= 0 && y < layout.size()) {
            return layout[y][x] == '*'; // '*' represents a wall
        }
        return true; // Consider out-of-bounds as wall

}



