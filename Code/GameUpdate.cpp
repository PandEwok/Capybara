#include "GameUpdate.hpp"

Player player;
vector<shared_ptr<Tile>> tileMap;
vector<shared_ptr<Money>> moneyList;
vector<shared_ptr<Npc>> npcList;
vector<shared_ptr<Sword>> swordad;
vector<shared_ptr<Axe>> axead;
vector<shared_ptr<Dagger>> daggerad;

Game::Game() {
	player = Player();
	hpBar->setTexture(hpBarTexture);
	hpBar->setTextureRect(IntRect(0, 0, hpBarTexture.getSize().y, hpBarTexture.getSize().y));
	moneyList = {};
	npcList = {};
	swordad = {};
	axead = {};
	daggerad = {};
	eKey->setTexture(eKeyTexture);
	eKey->setTextureRect(IntRect(0, 0, eKeyTexture.getSize().y, eKeyTexture.getSize().y));
	shading.setFillColor(Color(0, 0, 0, 0)); shading.setOrigin(shading.getSize() / 2.f);
}

void Game::update() {
	shading.setPosition(mainView.getCenter());

	if (eKeyClock.getElapsedTime().asSeconds() >= 0.6f) {
		eKeyClock.restart();
		continueAnimation(eKey);
	}
	float playerClockResetTime = 0.1f;
	if (player.getIsAttacking()) {
		playerClockResetTime = 0.05f;
	}
	if (player.getFramerate()->getElapsedTime().asSeconds() >= playerClockResetTime) {
		player.getFramerate()->restart();
		if (player.getIsAttacking() and player.getSprite()->getTextureRect().getPosition().x >= player.getSprite()->getTexture()->getSize().x - player.getSprite()->getTextureRect().getSize().x) {
			player.setIsAttacking(false);
		}
		else {
			continueAnimation(player.getSprite());
		}
	}
	for (shared_ptr<Money> money : moneyList) {
		if (money->animationTime.getElapsedTime().asSeconds() >= 0.2f) {
			money->animationTime.restart();
			continueAnimation(money->getSprite());
		}
	}
	for (shared_ptr<Npc> npc : npcList) {
		if (npc->animationTime.getElapsedTime().asSeconds() >= 0.3f) {
			npc->animationTime.restart();
			continueAnimation(npc->getSprite());
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
