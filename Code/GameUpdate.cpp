#include "GameUpdate.hpp"

Player player;
vector<shared_ptr<Tile>> tileMap;
vector<shared_ptr<Money>> moneyList;

Game::Game() {
	player = Player();
	hpBar->setTexture(hpBarTexture);
	hpBar->setTextureRect(IntRect(0, 0, hpBarTexture.getSize().y, hpBarTexture.getSize().y));
	moneyList = {};
}

void Game::update() {
	hpBar->setPosition(mainView.getCenter() + Vector2f(mainView.getSize().x / -2.f, mainView.getSize().y / 2.f) - Vector2f(0, hpBarTexture.getSize().y/1.5f));
	if (player.getFramerate()->getElapsedTime().asSeconds() >= 0.1f) {
		player.getFramerate()->restart();
		continueAnimation(player.getSprite());
	}
	for (shared_ptr<Money> money : moneyList) {
		if (money->animationTime.getElapsedTime().asSeconds() >= 0.2f) {
			money->animationTime.restart();
			continueAnimation(money->getSprite());
		}
	}
	if (itemClock.getElapsedTime().asSeconds() >= 0.1f) {
		itemClock.restart();
		
		for (shared_ptr<Tile> tile : tileMap) {
			continueAnimation(tile->getSprite());
		}
	}
}