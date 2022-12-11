#ifndef PLATFORM
#define PLATFORM

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Platform
{
    private:
        Vector2f m_position;
        Sprite platform;
        Texture texture;
        
    public:
        Platform();
        Sprite returnPlat();
        FloatRect getBounds(); 
        Vector2f getPosition();
        vector<Sprite> generator(double width, double height); 
};

#endif