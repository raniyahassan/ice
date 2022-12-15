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

vector<Sprite> Platform::generator(double width, double height)
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/ice.png");

    srand(time(0));
    vector<Sprite> x(50); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setPosition(400 + (rand() % 1910), 70 + (rand() % 1070));
        x[i].setScale(0.05, 0.05);
    }

    Sprite y;
    y.setTexture(*texture);
    y.setPosition(1400, 1240);
    y.setScale(0.05,0.05); 
    x.push_back(y);

    return x; 
}

vector<Sprite> Platform::generator2(double width, double height)
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/ice.png");

    srand(time(0));
    vector<Sprite> x(50); 
    for (int i = 0; i < x.size(); i++)
    {
        x[i].setTexture(*texture);
        x[i].setPosition(400 + (rand() % 1910), 1070 + (rand() % 2140));
        x[i].setScale(0.05, 0.05);
    }

    Sprite y;
    y.setTexture(*texture);
    y.setPosition(1400, 1240);
    y.setScale(0.05,0.05); 
    x.push_back(y);

    return x; 
}

