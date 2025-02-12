#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Tower {
protected:
    std::string name;
    int level;
    int cost;
    int refundValue;
    int range;
    int power;
    int rateOfFire;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;

public:
    Tower(std::string n, int c, int r, int p, int rof, const std::string& textureFile, sf::Vector2f pos);
    virtual ~Tower();
    virtual void attack() = 0;
    void upgrade();
    void sell();
    void draw(sf::RenderWindow &window);
};

#endif