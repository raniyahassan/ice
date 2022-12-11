#include "Screen.h"

Screen::Screen() {}; 

Sprite Screen::square()
{ 
    Texture *texture = new Texture; 
    texture->loadFromFile("images/bg.jpg"); 
    Sprite bg;
    bg.setTexture(*texture); 
    bg.setScale(2.4,2.3);

    return bg; 
}