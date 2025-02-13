#ifndef HEAVYCRITTER_H
#define HEAVYCRITTER_H

#include "critter.h"

class HeavyCritter : public Critter {
public:
    // Constructor: Sets default name to "Heavy_Critter", doubles HP, and has speed of 10
    HeavyCritter(int reward, int hp, int attackPower, int level, const std::string& textureFile, sf::Vector2f pos);

    // Override necessary abstract methods
    void move() override;
    void takedamage() override;
    void attack() override;
};

#endif // HEAVYCRITTER_H
