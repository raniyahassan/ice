#include "Platform.h"
#include "time.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Platform::Platform()
{
    
}

Sprite Platform::returnPlat()
{
    return platform; 
}

FloatRect Platform::getBounds()
{
    return platform.getGlobalBounds();
}

Vector2f Platform::getPosition()
{
    return platform.getPosition(); 
}

vector<Sprite> Platform::generator()
{
    Texture *texture = new Texture;  
    srand(time(0));
    texture->loadFromFile("images/ice.png");
    vector<Sprite> x(20); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setPosition(400 + (rand() % 1910), 70 + (rand() % 1070));
        x[i].setScale(0.05, 0.05);
    }

    return x; 
}