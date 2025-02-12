#include "Tower.h"

Tower::Tower(std::string n, int c, int r, int p, int rof, const std::string& textureFile, sf::Vector2f pos)
    : name(n), level(1), cost(c), refundValue(c / 2), range(r), power(p), rateOfFire(rof), position(pos) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Failed to load texture: " << textureFile << "\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Tower::~Tower() {}

void Tower::upgrade() {
    level++;
    cost += 50;
    refundValue = cost / 2;
    range += 2;
    power += 5;
    rateOfFire += 1;
    std::cout << name << " upgraded to level " << level << "!\n";
}

void Tower::sell() {
    std::cout << name << " sold for " << refundValue << " coins.\n";
}

void Tower::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}