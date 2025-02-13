#include "critter.h"

Critter::Critter(std::string name, int reward, int hp, int attackPower, float speed, int level, const std::string& textureFile, sf::Vector2f pos)
	: name(name), reward(reward), hp(hp + (hp * (level / 100))), attackPower(attackPower), speed(speed), level(level), position(pos) {
	if (!texture.loadFromFile(textureFile)) {
		std::cout << "Error loading texture file" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

void Critter::render(sf::RenderWindow& window) {
	window.draw(sprite);
}

std::string Critter::getName() {
	return name;
}

int Critter::getReward() {
	return reward;
}

int Critter::getHp() {
	return hp;
}

int Critter::getAttackPower() {
	return attackPower;
}

float Critter::getSpeed() {
	return speed;
}

int Critter::getLevel() {
	return level;
}

sf::Sprite Critter::getSprite() {
	return sprite;
}

sf::Vector2f Critter::getPosition() {
	return position;
}

void Critter::setReward(int reward) {
	this->reward = reward;
}

void Critter::setHp(int hp) {
	this->hp = hp;
}

void Critter::setAttackPower(int attackPower) {
	this->attackPower = attackPower;
}

void Critter::setSpeed(float speed) {
	this->speed = speed;
}

void Critter::setLevel(int level) {
	this->level = level;
}

void Critter::setSprite(sf::Sprite sprite) {
	this->sprite = sprite;
}

void Critter::setPosition(sf::Vector2f position) {
	this->position = position;
}

Critter::~Critter() {
}

void move() {
	//enter move logic based on map
}

void takedamage() {
	//enter damage logic
}

void attack() {
	//enter attack logic
}

void critterDeath() {
	//enter death logic
}