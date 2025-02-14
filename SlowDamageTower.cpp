#include "SlowDamageTower.h"

SlowDamageTower::SlowDamageTower(sf::Vector2f position) : Tower("Slow Damage Tower", 120, 12, 10, 1, "./assets/slow_tower.png", position) {}

void SlowDamageTower::attack() {
    std::cout << name << " slows down critters and deals " << power << " damage!\n";
}
