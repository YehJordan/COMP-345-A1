#include "fastCritter.h"

// Constructor - Calls base class constructor with fixed name and speed
FastCritter::FastCritter(int reward, int hp, int attackPower, int level, const std::string& textureFile, sf::Vector2f pos)
    : Critter("Fast_Critter", reward, hp, attackPower, 50.0f, level, textureFile, pos) {
}

// Move method override 
void FastCritter::move() {
    
}

// Attack method override 
void FastCritter::attack() {
    std::cout << "FastCritter attacks swiftly!" << std::endl;
}

// Take damage method override (example behavior)
void FastCritter::takedamage() {
    hp -= 10;  // Example: Takes 10 damage per hit
    if (hp <= 0) {
        critterDeath();
    }
}
