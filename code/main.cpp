#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Player.h"
#include "Screen.h"

using namespace std;
using namespace sf;

void moveViewUp(View&); 

float dt; 
Clock dtClock; 

int main()
{
    double width = VideoMode::getDesktopMode().width;
    double height = VideoMode::getDesktopMode().height; 
    cout << "(" << width << ", " << height << ")\n"; 

    const float speed = 100.f; 
    Vector2f velocity;

    VideoMode VideoWindow(width, height); 
    RenderWindow window(VideoWindow, "JumpGame");
    Event event; 
    Platform ice; 
    vector<Sprite> platforms = ice.generator(width, height);
    Player player; 
    Sprite E = player.returnPlayer(); 
    /*View view; 
    view.zoom(0.99f); 
    window.setView(view); */

    Screen screen; 
    Sprite background = screen.square(); 

    FloatRect nextPos; 

    while (window.isOpen())
    {
        dt = dtClock.restart().asSeconds(); 
        velocity.y = 4; 
        E.move(velocity); 

        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}
            if (event.type == Event::Closed) {window.close();}
            if (event.type == Event::MouseButtonPressed)
            {
                Vector2i point = Mouse::getPosition(window);
                cout << "(" << point.x << ", " << point.y << ")\n"; 
            }

            velocity.x = 0; 
            if (Keyboard::isKeyPressed(Keyboard::Left)) {velocity.x += -speed * dt;}
            if (Keyboard::isKeyPressed(Keyboard::Right)) {velocity.x += speed * dt;}
  

            E.move(velocity); 

        }
        for (int i = 0; i < platforms.size(); i++) 
            {
                FloatRect playerBounds = E.getGlobalBounds();
                FloatRect wallBounds = platforms[i].getGlobalBounds();

                nextPos = playerBounds;
                nextPos.top += (velocity.y - 10);

                if (wallBounds.intersects(nextPos))
                {
                    E.move(0, -100);                   
                }
            }
        window.clear(); 
        window.draw(background); 
        for (int i = 0; i < platforms.size(); i++) { window.draw(platforms[i]); }
        window.draw(E); 
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