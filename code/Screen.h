#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Screen 
{
    private:
        Texture texture; 
    public:
        Screen(); 
        Sprite square(); 
};

#endif