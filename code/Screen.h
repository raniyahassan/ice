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
        Texture texture2; 
        Texture texture3;
        Sprite beginningbackground; 
        Sprite button; 
    public:
        Screen(); 
        Sprite square(); 
        void start(RenderWindow& window); 
        void move(); 
        //void wipeScreen(RenderWindow& window); 
};

#endif