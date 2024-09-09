#include "Engine.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    if(argc < 2){
        cerr << "Please provide the maze file name as an argument." << endl;
    }

    
    Engine en(argv[1]);

    en.initialize();
    en.play();

}