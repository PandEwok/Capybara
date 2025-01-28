#include "GameUpdate.hpp"

Player player;
vector<shared_ptr<Tile>> tileMap;

Game::Game() {
	player = Player();
	hpBar->setTexture(hpBarTexture);
	hpBar->setTextureRect(IntRect(0, 0, hpBarTexture.getSize().y, hpBarTexture.getSize().y));
}

void Game::update() {
	hpBar->setPosition(mainView.getCenter() + Vector2f(-100, 50));
	if (player.getFramerate()->getElapsedTime().asSeconds() >= 0.1f) {
		player.getFramerate()->restart();
		continueAnimation(player.getSprite());
	}

	if (itemClock.getElapsedTime().asSeconds() >= 0.18f) {
		itemClock.restart();
		for (shared_ptr<Tile> tile : tileMap) {
			continueAnimation(tile->getSprite());
		}
	}
}