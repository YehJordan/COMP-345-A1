#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map();
    void handleEvent(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isOverlayActive() const;
    void loadGrassTexture(const std::string& filePath);
    void loadPathTexture(const std::string& filePath);
    void handleMouseDrag(sf::Event& event, sf::RenderWindow& window);
    void updateGridDimensions(sf::RenderWindow& window);

private:
    void createGrid();
    void drawOverlay(sf::RenderWindow& window);
    void drawGrid(sf::RenderWindow& window);

    int width;
    int height;
    bool overlayActive;
    sf::RectangleShape overlay;
    sf::RectangleShape enterButton;
    sf::Text enterButtonText;
    sf::Font font;
    std::vector<std::vector<sf::RectangleShape>> grid;

    // Input fields for dimensions
    sf::RectangleShape widthInputBox;
    sf::RectangleShape heightInputBox;
    sf::Text widthInputText;
    sf::Text heightInputText;
    std::string widthInput;
    std::string heightInput;

    // Start and end tiles
    sf::RectangleShape startTile;
    sf::RectangleShape endTile;

    sf::Texture grassTexture;
    sf::Texture pathTexture;
    sf::Text enterSizeLabel;

    bool isDragging;
    sf::Vector2i startDragPos;
    std::vector<sf::Vector2i> pathPositions; // Store the path positions
};