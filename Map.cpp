#include "Map.h"
#include <iostream>

Map::Map() : width(10), height(10), overlayActive(true), widthInput("10"), heightInput("10"), isDragging(false) {
    // Load font
    if (!font.loadFromFile("./assets/Arial.ttf")) {
        std::cerr << "Failed to load font\n";
    }

    // Setup overlay
    overlay.setSize({800, 800});
    overlay.setFillColor(sf::Color(0, 0, 0, 128)); // Alpha 0.5

    // Setup enter button
    enterButton.setSize({100, 50});
    enterButton.setFillColor(sf::Color::Green);
    enterButton.setPosition(350, 700);

    // Setup enter button text
    enterButtonText.setFont(font);
    enterButtonText.setCharacterSize(20);
    enterButtonText.setFillColor(sf::Color::White);
    enterButtonText.setString("Enter");
    enterButtonText.setPosition(370, 715);

    // Setup input boxes
    widthInputBox.setSize({100, 50});
    widthInputBox.setFillColor(sf::Color::White);
    widthInputBox.setPosition(200, 200);

    heightInputBox.setSize({100, 50});
    heightInputBox.setFillColor(sf::Color::White);
    heightInputBox.setPosition(500, 200);

    // Setup input texts
    widthInputText.setFont(font);
    widthInputText.setCharacterSize(20);
    widthInputText.setFillColor(sf::Color::Black);
    widthInputText.setString(widthInput);
    widthInputText.setPosition(220, 215);

    heightInputText.setFont(font);
    heightInputText.setCharacterSize(20);
    heightInputText.setFillColor(sf::Color::Black);
    heightInputText.setString(heightInput);
    heightInputText.setPosition(520, 215);

    // Setup enter size label
    enterSizeLabel.setFont(font);
    enterSizeLabel.setCharacterSize(20);
    enterSizeLabel.setFillColor(sf::Color::White);
    enterSizeLabel.setString("Enter Size");
    enterSizeLabel.setPosition(350, 150);

    // Load grass texture
    loadGrassTexture("./assets/grass.png");

    // Load path texture
    loadPathTexture("./assets/path.png");

    // Initialize grid with default size
    createGrid();
}

void Map::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (overlayActive) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f clickPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (enterButton.getGlobalBounds().contains(clickPos)) {
                width = std::stoi(widthInput);
                height = std::stoi(heightInput);
                createGrid();
                overlayActive = false;
            } else if (widthInputBox.getGlobalBounds().contains(clickPos)) {
                widthInput.clear();
                widthInputText.setString(widthInput);
            } else if (heightInputBox.getGlobalBounds().contains(clickPos)) {
                heightInput.clear();
                heightInputText.setString(heightInput);
            }
        } else if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                if (widthInputBox.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    widthInput += static_cast<char>(event.text.unicode);
                    widthInputText.setString(widthInput);
                } else if (heightInputBox.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    heightInput += static_cast<char>(event.text.unicode);
                    heightInputText.setString(heightInput);
                }
            } else if (event.text.unicode == 8) { // Handle backspace
                if (widthInputBox.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (!widthInput.empty()) {
                        widthInput.pop_back();
                        widthInputText.setString(widthInput);
                    }
                } else if (heightInputBox.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    if (!heightInput.empty()) {
                        heightInput.pop_back();
                        heightInputText.setString(heightInput);
                    }
                }
            }
        }
    } else {
        handleMouseDrag(event, window);
    }
}

void Map::draw(sf::RenderWindow& window) {
    drawGrid(window); // Draw the grid first
    if (overlayActive) {
        drawOverlay(window);
    }
}

bool Map::isOverlayActive() const {
    return overlayActive;
}

void Map::createGrid() {
    std::cout << "Creating grid with dimensions: " << width << "x" << height << std::endl;
    grid.clear();
    grid.resize(height, std::vector<sf::RectangleShape>(width));
    sf::Vector2f overlaySize = overlay.getSize();
    sf::Vector2u windowSize(static_cast<unsigned int>(overlaySize.x), static_cast<unsigned int>(overlaySize.y));
    float tileSize = std::min(static_cast<float>(windowSize.x) / width, static_cast<float>(windowSize.y) / height);
    sf::Vector2u grassTextureSize = grassTexture.getSize();
    sf::Vector2u pathTextureSize = pathTexture.getSize();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j].setSize({tileSize, tileSize});
            grid[i][j].setTexture(&grassTexture);
            grid[i][j].setTextureRect(sf::IntRect(0, 0, grassTextureSize.x, grassTextureSize.y));
            grid[i][j].setOutlineColor(sf::Color::Black);
            grid[i][j].setOutlineThickness(1);
            grid[i][j].setPosition(j * tileSize, i * tileSize);
        }
    }

    // Setup start and end tiles
    startTile.setSize({tileSize, tileSize});
    startTile.setFillColor(sf::Color::Green);
    startTile.setPosition(0, (height / 2 - 1) * tileSize); // Start tile in the middle row

    endTile.setSize({tileSize, tileSize});
    endTile.setFillColor(sf::Color::Red);
    endTile.setPosition((width - 1) * tileSize, (height / 2) * tileSize); // End tile in the adjoining row
}

void Map::drawOverlay(sf::RenderWindow& window) {
    window.draw(overlay);
    window.draw(enterButton);
    window.draw(enterButtonText);
    window.draw(widthInputBox);
    window.draw(heightInputBox);
    window.draw(widthInputText);
    window.draw(heightInputText);
    window.draw(enterSizeLabel);
}

void Map::drawGrid(sf::RenderWindow& window) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            window.draw(cell);
        }
    }
    window.draw(startTile);
    window.draw(endTile);
}

void Map::loadGrassTexture(const std::string& filePath) {
    if (!grassTexture.loadFromFile(filePath)) {
        std::cerr << "Failed to load grass texture\n";
    }
}

void Map::loadPathTexture(const std::string& filePath) {
    if (!pathTexture.loadFromFile(filePath)) {
        std::cerr << "Failed to load path texture\n";
    }
}

void Map::handleMouseDrag(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Vector2i endTilePos(endTile.getPosition().x / grid[0][0].getSize().x, endTile.getPosition().y / grid[0][0].getSize().y);
        if (startTile.getGlobalBounds().contains(mousePos) || 
            (!pathPositions.empty() && grid[pathPositions.back().y][pathPositions.back().x].getGlobalBounds().contains(mousePos) && pathPositions.back() != endTilePos)) {
            isDragging = true;
            startDragPos = sf::Vector2i(mousePos.x / grid[0][0].getSize().x, mousePos.y / grid[0][0].getSize().y);
            if (pathPositions.empty()) {
                pathPositions.push_back(startDragPos); // Add start position to path
            }
        }
    } else if (event.type == sf::Event::MouseMoved && isDragging && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Vector2i currentPos(mousePos.x / grid[0][0].getSize().x, mousePos.y / grid[0][0].getSize().y);

        if (currentPos.x >= 0 && currentPos.x < width && currentPos.y >= 0 && currentPos.y < height) {
            if (currentPos != pathPositions.back()) {
                // Ensure the path is placed only in horizontal and vertical directions relative to the latest path segment
                if ((currentPos.x == pathPositions.back().x && std::abs(currentPos.y - pathPositions.back().y) == 1) ||
                    (currentPos.y == pathPositions.back().y && std::abs(currentPos.x - pathPositions.back().x) == 1)) {
                    // Draw vertical path
                    if (currentPos.x == pathPositions.back().x) {
                        int minY = std::min(pathPositions.back().y, currentPos.y);
                        int maxY = std::max(pathPositions.back().y, currentPos.y);
                        for (int y = minY; y <= maxY; ++y) {
                            grid[y][currentPos.x].setTexture(&pathTexture);
                            grid[y][currentPos.x].setTextureRect(sf::IntRect(0, 0, pathTexture.getSize().x, pathTexture.getSize().y));
                            pathPositions.push_back(sf::Vector2i(currentPos.x, y)); // Add position to path
                        }
                        pathPositions.push_back(currentPos); // Update the last position
                    }
                    // Draw horizontal path
                    else if (currentPos.y == pathPositions.back().y) {
                        int minX = std::min(pathPositions.back().x, currentPos.x);
                        int maxX = std::max(pathPositions.back().x, currentPos.x);
                        for (int x = minX; x <= maxX; ++x) {
                            grid[currentPos.y][x].setTexture(&pathTexture);
                            grid[currentPos.y][x].setTextureRect(sf::IntRect(0, 0, pathTexture.getSize().x, pathTexture.getSize().y));
                            pathPositions.push_back(sf::Vector2i(x, currentPos.y)); // Add position to path
                        }
                        pathPositions.push_back(currentPos); // Update the last position
                    }
                }
            }
        }
    } else if (event.type == sf::Event::MouseButtonReleased && isDragging) {
        isDragging = false;
        std::cout << "Path completed!" << std::endl;
        std::cout << "Path positions: ";
        for (const auto& pos : pathPositions) {
            std::cout << "(" << pos.x << ", " << pos.y << ") ";
        }
        std::cout << std::endl;
        // Log the final tile and its coordinates
        if (!pathPositions.empty()) {
            const auto& finalTile = pathPositions.back();
            std::cout << "Final tile: (" << finalTile.x << ", " << finalTile.y << ")" << std::endl;
        }
        // Stop path-making if the final tile is the end tile
        if (!pathPositions.empty() && pathPositions.back() == sf::Vector2i(endTile.getPosition().x / grid[0][0].getSize().x, endTile.getPosition().y / grid[0][0].getSize().y)) {
            std::cout << "Reached the end tile. Path-making stopped." << std::endl;
            isDragging = false;
        }
    }
}

void Map::updateGridDimensions(sf::RenderWindow& window) {
    createGrid();
}