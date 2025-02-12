#ifndef SLOW_DAMAGE_TOWER_H
#define SLOW_DAMAGE_TOWER_H

#include "Tower.h"

class SlowDamageTower : public Tower {
public:
    SlowDamageTower(sf::Vector2f pos);
    void attack() override;
};

#endif