#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Player.h"
#include "Screen.h"

using namespace std;
using namespace sf;

float dt; 
Clock dtClock; 


int main()
{
    double width = VideoMode::getDesktopMode().width;
    double height = VideoMode::getDesktopMode().height; 
    cout << "(" << width << ", " << height << ")\n"; 

    const float speed = 100.f; 
    Vector2f velocity;
    enum STATE {START, PLAYING, END}; 
    STATE state = START; 
    VideoMode VideoWindow(width, 2*height); 
    RenderWindow window(VideoWindow, "JumpGame");
    Event event; 
    Platform ice; 
    vector<Sprite> platforms = ice.generator(width, height);
    vector<Sprite> platforms2 = ice.generator2(width, height);
    Player player; 
    Sprite E = player.returnPlayer(); 

    Screen screen(width, height); 
    Sprite background = screen.square(); 

    FloatRect nextPos; 

    while (window.isOpen())
    {
        dt = dtClock.restart().asSeconds(); 
        velocity.y = 4; 
        E.move(velocity); 
        screen.start(window); 

        while (window.pollEvent(event))
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {window.close();}
            if (event.type == Event::MouseButtonPressed) 
            {
                Vector2i click = Mouse::getPosition(); 
                FloatRect bound = screen.getBounds(); 
                if(click.x >= bound.left && click.x <= (bound.left + bound.width) && click.y <= bound.left && click.y >= (bound.left - bound.width/2)) 
                    state = PLAYING;            
            }
            if (event.type == Event::Closed) {window.close();}

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
        if (state == START) {screen.start(window);}
        if (state == PLAYING)
        {
            screen.move(); 
            window.draw(background); 
            for (int i = 0; i < platforms.size(); i++) { window.draw(platforms[i]); }
            window.draw(E); 
        }
        window.display(); 
    }

    return 0; 
}