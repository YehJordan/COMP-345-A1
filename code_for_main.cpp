#include <SFML/Graphics.hpp>
#include "DirectDamageTower.h"
#include "AreaDamageTower.h"
#include "SlowDamageTower.h"
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tower Defense");
    std::vector<Tower*> towers;

    // Create some towers
    towers.push_back(new DirectDamageTower({200, 300}));
    towers.push_back(new AreaDamageTower({400, 300}));
    towers.push_back(new SlowDamageTower({600, 300}));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // std::cout<< event.type << std::endl;

            if (event.type == sf::Event::MouseButtonPressed) {

                sf::Vector2f clickPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                for (auto& tower : towers) {
                    sf::FloatRect bounds = tower->getBounds(); // Add this method in Tower class
                    std::cout << "Tower bounds: (" << bounds.left << ", " << bounds.top << ", " 
                              << bounds.width << ", " << bounds.height << ")\n";
            
                    if (tower->isClicked(clickPos)) {
                        tower->setIsSelected(true);
                        tower->handleClick(clickPos);
                        std::cout << "Tower Clicked!\n";
                    } else {
                        tower->setIsSelected(false);
                    }
                }
            }
        }

        for (auto it = towers.begin(); it != towers.end();) {
            if ((*it)->isSold) {
                it = towers.erase(it);  // Erase and get new iterator
            } else {
                ++it;  // Move to the next element
            }
        }

        window.clear();
        for (auto& tower : towers) {
            tower->draw(window);
        }
        window.display();
    }

    for (auto& tower : towers) {
        delete tower;
    }

    return 0;
}
