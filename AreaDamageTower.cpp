#include "AreaDamageTower.h"

AreaDamageTower::AreaDamageTower(sf::Vector2f pos) : Tower("Area Damage Tower", 150, 8, 15, 1, "area_tower.png", pos) {}

void AreaDamageTower::attack() {
    std::cout << name << " deals " << power << " damage to multiple critters in an area!\n";
}