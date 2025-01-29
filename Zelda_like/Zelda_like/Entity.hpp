#pragma once

#include "Global.hpp"

class Entity {
protected:
	shared_ptr<Sprite> sprite = make_shared<Sprite>();
public:
	Entity(Vector2f textureSize);
	virtual void draw() = 0;
	shared_ptr<Sprite> getSprite();
};

class Player : public Entity {
protected:
	float speed = 250.f;
	int hp = 3;
	Clock framrate;
	int keyNumber = 0;
public:
	enum direction {
		FRONT = 0,
		BACK = 1,
		RIGHT = 2,
		LEFT = 3
	};
	int facing = FRONT;
	Player();
	void draw() override;
	float getSpeed();
	void move();
	Clock* getFramerate();
	int getHp();
	void decreaseHp(int value = 1);
	void increaseHp(int value = 1);
	int getKeyState();
	void setKeyState(int newValue);
	FloatRect getHitBox();


};

class Enemy : public Entity {
protected:
	float speed;
	int hp;
public:
	Enemy(Vector2f textureSize, float speed, int hp);

	virtual void update(float deltaTime) = 0; 

	float getSpeed() const;
	void setSpeed(float newSpeed);

	int getHp() const;
	void decreaseHp(int value = 1);
	bool isDead() const;
};