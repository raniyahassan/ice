#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.h"

using namespace std;
using namespace sf;

void moveViewUp(View&); 

int main()
{
    double width = VideoMode::getDesktopMode().width;
    double height = VideoMode::getDesktopMode().height; 

    VideoMode VideoWindow(width, height); 
    RenderWindow window(VideoWindow, "JumpGame");
    Event event; 
    Platform ice; 
    vector<Sprite> platforms = ice.generator();
    View view; 
    view.zoom(0.99f); 
    window.setView(view); 

    Texture backgroundTexture; 
    backgroundTexture.loadFromFile("images/bg.jpg"); 
    Sprite background(backgroundTexture); 
    background.setScale(2.4,2.3); 
    


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}
            if (event.type == Event::Closed) {window.close();}

            if (event.type == Event::MouseButtonPressed)
            {
                moveViewUp(view); 
            }

        }
        window.clear(); 
        window.draw(background); 
        for (int i = 0; i < platforms.size(); i++) { window.draw(platforms[i]); }
        window.display(); 
    }


    return 0; 
}

void moveViewUp(View& view)
{
    Vector2f curr = view.getCenter(); 
    curr.y +=200; 
    view.setCenter(curr);
}