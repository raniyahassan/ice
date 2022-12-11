#include "Player.h"

Player::Player() {}

Sprite Player::returnPlayer()
{
    Texture *texture = new Texture;  
    texture->loadFromFile("images/guy.png");
    Sprite x; 
    x.setTexture(*texture);
    x.setPosition(1410,1100);
    x.setScale(0.1,0.1);
    return x;

}