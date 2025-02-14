#include "DirectDamageTower.h"

DirectDamageTower::DirectDamageTower(sf::Vector2f position) : Tower("Direct Damage Tower", 100, 10, 20, 2, "./assets/direct_tower.png", position) {}

void DirectDamageTower::attack() {
    std::cout << name << " deals " << power << " direct damage to a single critter!\n";
}