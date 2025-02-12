#ifndef AREA_DAMAGE_TOWER_H
#define AREA_DAMAGE_TOWER_H

#include "Tower.h"

class AreaDamageTower : public Tower {
public:
    AreaDamageTower(sf::Vector2f pos);
    void attack() override;
};

#endif