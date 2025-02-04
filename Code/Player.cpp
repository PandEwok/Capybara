#include "Player.hpp"

Player::Player() : Entity(Vector2f(playerTextureFrontIdle.getSize().y, playerTextureFrontIdle.getSize().y)) {
	sprite->setTexture(playerTextureFrontIdle);
	sprite->setTextureRect(IntRect(0, 0, playerTextureFrontIdle.getSize().y, playerTextureFrontIdle.getSize().y));
	sprite->setPosition(10, 10);
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
	for (int i = 0; i < value; i++) {
		if (hp <= 0) {
			break;
		}
		continueAnimation(hpBar);
	}
	hp -= value;
	cout << "HP is now " << hp << redString << " (-" << value << ")" << whiteString << endl;
}

void Player::increaseHp(int value)
{
	for (int i = 0; i < value; i++) {
		if (hp < 3) {
			for (int i = 0; i < 3; i++) {
				continueAnimation(hpBar);
			}
			hp ++;
		}
	}
	cout << "HP is now " << hp << greenString << " (+" << value << ")" << whiteString << endl;
}

bool Player::getIsAttacking() {
	return isAttacking;
}

void Player::setIsAttacking(bool value) {
	isAttacking = value;
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

FloatRect Player::getActionRange()
{
	if (facing == FRONT) {
		return FloatRect(getHitBox().getPosition().x - 12, getHitBox().getPosition().y + 15, getHitBox().width +12*2, 10);
	}
	if (facing == BACK) {
		return FloatRect(getHitBox().getPosition().x - 12, getHitBox().getPosition().y - 15, getHitBox().width +12*2, 10);
	}
	if (facing == RIGHT) {
		return FloatRect(getHitBox().getPosition().x + getHitBox().width+3, getHitBox().getPosition().y - 5, 10, getHitBox().height +5*2);
	}
	if (facing == LEFT) {
		return FloatRect(getHitBox().getPosition().x - 10 - 3, getHitBox().getPosition().y - 5, 10, getHitBox().height +5*2);
	}
}