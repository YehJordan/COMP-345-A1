#include "AreaDamageTower.h"

AreaDamageTower::AreaDamageTower(sf::Vector2f position) : Tower("Area Damage Tower", 150, 8, 15, 1, "./assets/area_tower.png", position) {}

void AreaDamageTower::attack() {
    std::cout << name << " deals " << power << " damage to multiple critters in an area!\n";
}