#include "SlowDamageTower.h"

SlowDamageTower::SlowDamageTower(sf::Vector2f pos) : Tower("Slow Damage Tower", 120, 12, 10, 1, "slow_tower.png", pos) {}

void SlowDamageTower::attack() {
    std::cout << name << " slows down critters and deals " << power << " damage!\n";
}
