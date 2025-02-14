#include "Tower.h"

Tower::Tower(std::string n, int c, int r, int p, int rof, const std::string& textureFile, sf::Vector2f pos)
    : name(n), level(1), cost(c), refundValue(c / 2), range(r), power(p), rateOfFire(rof), position(pos) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Failed to load texture: " << textureFile << "\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);

    // Load font
    if (!font.loadFromFile("./assets/Arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    // Setup buttons
    upgradeButton.setSize({60, 30});
    upgradeButton.setFillColor(sf::Color::Green);
    upgradeButton.setPosition(position.x, position.y + 40);

    sellButton.setSize({60, 30});
    sellButton.setFillColor(sf::Color::Red);
    sellButton.setPosition(position.x + 70, position.y + 40);

    // Setup text
    upgradeText.setFont(font);
    upgradeText.setCharacterSize(14);
    upgradeText.setFillColor(sf::Color::White);
    upgradeText.setString("UPG " + std::to_string(cost / 2));
    upgradeText.setPosition(position.x + 5, position.y + 45);

    sellText.setFont(font);
    sellText.setCharacterSize(14);
    sellText.setFillColor(sf::Color::White);
    sellText.setString("SELL " + std::to_string(refundValue));
    sellText.setPosition(position.x + 75, position.y + 45);
}

Tower::~Tower() {}

void Tower::upgrade() {
    level++;
    cost += 50;
    refundValue = cost / 2;
    range += 2;
    power += 5;
    rateOfFire += 1;
    upgradeText.setString("UPG " + std::to_string(cost / 2));
    sellText.setString("SELL " + std::to_string(refundValue));
    std::cout << name << " upgraded to level " << level << "!\n";
}

void Tower::sell() {
    std::cout << name << " sold for " << refundValue << " coins.\n";
}

void Tower::draw(sf::RenderWindow &window) {
    
    window.draw(sprite);
    if (getIsSelected()) {
        window.draw(upgradeButton);
        window.draw(upgradeText);
        window.draw(sellButton);
        window.draw(sellText);
    }
}

bool Tower::isClicked(sf::Vector2f clickPos) {
    return sprite.getGlobalBounds().contains(clickPos);
}

sf::FloatRect Tower::getBounds() const {
    return sprite.getGlobalBounds();
}

void Tower::handleClick(sf::Vector2f clickPos) {
    // If upgrade button is clicked
    if (isSelected && upgradeButton.getGlobalBounds().contains(clickPos)) {
        upgrade();
        isSelected = false;
        return;
    }

    // If sell button is clicked
    if (isSelected && sellButton.getGlobalBounds().contains(clickPos)) {
        sell();
        isSold = true;
        isSelected = false; // Hide buttons after selling
        
        return;
    }
}

void Tower::drawUI(sf::RenderWindow &window) {
    if (isSelected) {
        window.draw(upgradeButton);
        window.draw(sellButton);
        window.draw(upgradeText);
        window.draw(sellText);
    }
}


// Getters
int Tower::getLevel() const { 
    return level; 
}

int Tower::getCost() const { 
    return cost; 
}

int Tower::getRefundValue() const { 
    return refundValue; 
}

int Tower::getRange() const { 
    return range; 
}

int Tower::getPower() const { 
    return power; 
}

int Tower::getRateOfFire() const { 
    return rateOfFire; 
}

sf::Vector2f Tower::getPosition() const { 
    return position; 
}

bool Tower::getIsSelected() const {
    return isSelected;
}

sf::Sprite Tower::getSprite() const {
    return sprite;
}

// Setters
void Tower::setRange(int range) { 
    this->range = range; 
}

void Tower::setPower(int power) { 
    this->power = power; 
}

void Tower::setRateOfFire(int rateOfFire) { 
    this->rateOfFire = rateOfFire; 
}

void Tower::setPosition(sf::Vector2f position) { 
    this->position = position; 
    sprite.setPosition(this->position);  // Update sprite position too
}

void Tower::setIsSelected(bool selected){
    this->isSelected = selected;
}