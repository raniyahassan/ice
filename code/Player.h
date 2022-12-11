#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Player
{
private:
    Texture texture; 
    Sprite player; 
     
public:
    Player();
    Sprite returnPlayer();
};


#endif 