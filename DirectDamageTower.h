#ifndef DIRECT_DAMAGE_TOWER_H
#define DIRECT_DAMAGE_TOWER_H

#include "Tower.h"

class DirectDamageTower : public Tower {
public:
    DirectDamageTower(sf::Vector2f pos);
    void attack() override;
};

#endif