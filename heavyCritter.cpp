#include "heavyCritter.h"

// Constructor - Calls base class, doubled HP, and slow speed
HeavyCritter::HeavyCritter(int reward, int hp, int attackPower, int level, const std::string& textureFile, sf::Vector2f pos)
    : Critter("Heavy_Critter", reward, hp * 2, attackPower, 10.0f /*speed subject to change*/, level, textureFile, pos) {
}

// Move method override - Moves much slower than a normal critter
void HeavyCritter::move() {
}

// Attack method override - Example attack behavior
void HeavyCritter::attack() {
    std::cout << "HeavyCritter smashes with brute force!" << std::endl;
}

// Take damage method override - Takes damage but has a high HP pool
void HeavyCritter::takedamage() {
    hp -= 10;  // Example: Takes 10 damage per hit
    if (hp <= 0) {
        critterDeath();
    }
}
