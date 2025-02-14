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

    bool isSelected;
    sf::RectangleShape upgradeButton, sellButton;
    sf::Font font;
    sf::Text upgradeText, sellText;

public:
    Tower(std::string name, int cost, int refund, int power, int rateOfFire, const std::string& textureFile, sf::Vector2f position);

    bool isSold = false;
    virtual ~Tower();
    virtual void attack() = 0;

    void upgrade();
    void sell();
    void draw(sf::RenderWindow &window);
    bool isClicked(sf::Vector2f clickPos);
    void handleClick(sf::Vector2f clickPos);
    void drawUI(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;
    void removeButtons();
    

    // Getters
    int getLevel() const;
    int getCost() const;
    int getRefundValue() const;
    int getRange() const;
    int getPower() const;
    int getRateOfFire() const;
    sf::Vector2f getPosition() const;
    bool getIsSelected() const;
    sf::Sprite getSprite() const;

    // Setters
    void setRange(int range);
    void setPower(int power);
    void setRateOfFire(int rateOfFire);
    void setPosition(sf::Vector2f position);
    void setIsSelected(bool selected);

};

#endif