#include "Screen.h"

Screen::Screen() 
{
    Texture *texture2 = new Texture; 
    texture2->loadFromFile("images/bg.jpg"); 
    beginningbackground.setTexture(*texture2); 
    beginningbackground.setScale(2.4, 2.3); 

    Texture *texture3 = new Texture;
    texture3->loadFromFile("images/start.png"); 
    button.setTexture(*texture3);    
    button.setPosition(1270,841);  
    button.setScale(0.5,0.5); 
}; 

Sprite Screen::square()
{ 
    Texture *texture = new Texture; 
    texture->loadFromFile("images/bg.jpg"); 
    Sprite bg;
    bg.setTexture(*texture); 
    bg.setScale(2.4,2.3);

    return bg; 
}

void Screen::start(RenderWindow& window)
{
	window.draw(beginningbackground); 
    window.draw(button); 
}

bool Screen::begin(Vector2i click)
{
    FloatRect buttonArea = button.getGlobalBounds(); 
    float x = click.x; 
    float y = click.y;
    if (buttonArea.contains(x, y))
    {
        return true;
    }
    return false; 
}

void Screen::move()
{
    beginningbackground.setScale(0.000001, 0.000001); 
    button.move(-1000,-1000); 
}
