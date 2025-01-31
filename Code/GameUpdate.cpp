#include "GameUpdate.hpp"

Player player;
vector<shared_ptr<Tile>> tileMap;
vector<shared_ptr<Money>> moneyList;
vector<shared_ptr<Sword>> swordad;
vector<shared_ptr<Axe>> axead;
vector<shared_ptr<Dagger>> daggerad;

Game::Game() {
	player = Player();
	hpBar->setTexture(hpBarTexture);
	hpBar->setTextureRect(IntRect(0, 0, hpBarTexture.getSize().y, hpBarTexture.getSize().y));
	moneyList = {};
	swordad = {};
	axead = {};
	daggerad = {};
}

void Game::update() {
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
			if (tile->getType() != "Gate") {
				continueAnimation(tile->getSprite());
			}
		}
	}
}
