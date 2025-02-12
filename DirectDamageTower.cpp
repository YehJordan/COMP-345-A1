#include "DirectDamageTower.h"

DirectDamageTower::DirectDamageTower(sf::Vector2f pos) : Tower("Direct Damage Tower", 100, 10, 20, 2, "direct_tower.png", pos) {}

void DirectDamageTower::attack() {
    std::cout << name << " deals " << power << " direct damage to a single critter!\n";
}