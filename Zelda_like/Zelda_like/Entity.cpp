#include "Entity.hpp"


Entity::Entity(Vector2f textureSize) {
	sprite->setOrigin(textureSize / 2.f);
}

shared_ptr<Sprite> Entity::getSprite() {
	return sprite;
}

Player::Player() : Entity(Vector2f(playerTextureFrontIdle.getSize().y, playerTextureFrontIdle.getSize().y)) {
	sprite->setTexture(playerTextureFrontIdle);
	sprite->setTextureRect(IntRect(0, 0, playerTextureFrontIdle.getSize().y, playerTextureFrontIdle.getSize().y));
	sprite->setPosition(10, 10);
}

void Player::draw() {
	window.draw(*sprite);
}

float Player::getSpeed() {
	return speed;
}

void Player::move()
{
	sprite->move(inputMovement * timeSinceLastFrameInputs.asSeconds() * speed);
}

Clock* Player::getFramerate()
{
	return &framrate;
}

int Player::getHp() {
	return hp;
}

void Player::decreaseHp(int value) {
	continueAnimation(hpBar);
	hp -= value;
}

void Player::increaseHp(int value)
{
	if (hp < 3) {
		for (int i = 0; i < 3; i++) {
			continueAnimation(hpBar);
		}
		hp += value;
		cout << "HP is now " << hp << greenString << " (+1)" << whiteString << endl;
	}
}

int Player::getKeyState()
{
	return keyNumber;
}

void Player::setKeyState(int newValue)
{
	keyNumber = newValue;
}

FloatRect Player::getHitBox() {
	Vector2f boundsPos = sprite->getGlobalBounds().getPosition();
	Vector2f boundsSize = sprite->getGlobalBounds().getSize();
	return FloatRect(boundsPos.x + boundsSize.x / 9.f * 4.f, boundsPos.y + boundsSize.y / 7.f * 3.3f, boundsSize.x / 9.f, boundsSize.y / 7.f * 1.5f);
}

Enemy::Enemy(Vector2f textureSize, float speed, int hp) : Entity(textureSize), speed(speed), hp(hp) {}

float Enemy::getSpeed() const {
	return speed;
}

void Enemy::setSpeed(float newSpeed) {
	speed = newSpeed;
}

int Enemy::getHp() const {
	return hp;
}

void Enemy::decreaseHp(int value) {
	hp -= value;
	if (hp < 0) {
		hp = 0;
	}
}

bool Enemy::isDead() const {
	return hp <= 0;
}