#include <SFML/Graphics.hpp>
// #include "DirectDamageTower.h"
// #include "AreaDamageTower.h"
// #include "SlowDamageTower.h"
#include "Map.h"
#include <vector>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tower Defense", sf::Style::Titlebar | sf::Style::Close);
    // std::vector<Tower*> towers;
    Map map;

    // Load grass texture for the map
    map.loadGrassTexture("./assets/grass.png");

    // Update grid dimensions based on the window size
    map.updateGridDimensions(window);

    // Create some towers
    // towers.push_back(new DirectDamageTower({200, 300}));
    // towers.push_back(new AreaDamageTower({400, 300}));
    // towers.push_back(new SlowDamageTower({600, 300}));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // if (event.type == sf::Event::Resized) {
            //     sf::Vector2u newSize = window.getSize();
            //     unsigned int newSizeMin = std::min(newSize.x, newSize.y);
            //     window.setSize({newSizeMin, newSizeMin});
            //     map.updateGridDimensions(window);
            // }

            if (map.isOverlayActive()) {
                map.handleEvent(event, window);
            } else {
                map.handleMouseDrag(event, window);
                // if (event.type == sf::Event::MouseButtonPressed) {
                //     sf::Vector2f clickPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //     for (auto& tower : towers) {
                //         sf::FloatRect bounds = tower->getBounds();
                //         if (tower->isClicked(clickPos)) {
                //             tower->setIsSelected(true);
                //             tower->handleClick(clickPos);
                //         } else {
                //             tower->setIsSelected(false);
                //         }
                //     }
                // }
            }
        }

        // for (auto it = towers.begin(); it != towers.end();) {
        //     if ((*it)->isSold) {
        //         it = towers.erase(it);
        //     } else {
        //         ++it;
        //     }
        // }

        window.clear();
        map.draw(window);
        // if (!map.isOverlayActive()) {
        //     for (auto& tower : towers) {
        //         tower->draw(window);
        //     }
        // }
        window.display();
    }

    // for (auto& tower : towers) {
    //     delete tower;
    // }

    return 0;
}
