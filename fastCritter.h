#ifndef FASTCRITTER_H
#define FASTCRITTER_H

#include "critter.h"

// A FastCritter is a type of Critter that moves faster than the other Critters

class FastCritter : public Critter {
public:
    // Constructor for FastCritter with default speed and name
    FastCritter(int reward, int hp, int attackPower, int level, const std::string& textureFile, sf::Vector2f pos)
        : Critter("fast_critter", reward, hp, attackPower, 50.0f/* Change depending on map implementation*/, level, textureFile, pos) {
    }

    // Override the abstract methods if needed (move, takedamage, etc.)
    void move() override;

    void takedamage() override;

    void attack() override;

};

#endif // FASTCRITTER_H
