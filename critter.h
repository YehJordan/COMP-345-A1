#ifndef CRITTER_H
#define CRITTER_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Critter{
protected:
	std::string name;
	int reward;
	int hp;
	int attackPower;
	float speed;
	int level;
	sf::Sprite sprite;         // Sprite for rendering
	sf::Vector2f position;     // Position on the screen

public:
	//Constructor
	Critter(std::string name, int reward, int hp, int attackPower, float speed, int level, const std::string& textureFile, sf::Vector2f pos);
	void render(sf::RenderWindow& window);

	//getters
	std::string getName();
	int getReward();
	int getHp();
	int getAttackPower();
	float getSpeed();
	int getLevel();
	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	//setters
	void setReward(int reward);
	void setHp(int hp);
	void setAttackPower(int attackPower);
	void setSpeed(float speed);
	void setLevel(int level);
	void setSprite(sf::Sprite sprite);
	void setPosition(sf::Vector2f position);

	//abstract methods
	virtual ~Critter();
	virtual void move() = 0;
	virtual void takedamage() = 0;
	virtual void attack() = 0;
	virtual void critterDeath() = 0;



#endif // !CRITTER_H
