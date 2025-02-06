#include "GameUpdate.hpp"

Player player;
vector<shared_ptr<Tile>> tileMap;
vector<shared_ptr<Money>> moneyList;
vector<shared_ptr<MarketItem>> marketItemList;
vector<shared_ptr<Npc>> npcList;
vector<shared_ptr<Sword>> swordad;
vector<shared_ptr<Axe>> axead;
vector<shared_ptr<Dagger>> daggerad;
vector<shared_ptr<Hunter>> hunterList;

Game::Game() {
	player = Player();
	hpBar->setTexture(hpBarTexture);
	hpBar->setTextureRect(IntRect(0, 0, hpBarTexture.getSize().y, hpBarTexture.getSize().y));
	moneyList = {};
	marketItemList = {};
	npcList = {};
	swordad = {};
	axead = {};
	daggerad = {};
	hunterList = {};
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
	float playerClockResetTime = 0.2f;
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
	for (shared_ptr<MarketItem> item : marketItemList) {
		if (item->animationTime.getElapsedTime().asSeconds() >= 0.2f) {
			item->animationTime.restart();
			continueAnimation(item->getSprite());
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
	for (shared_ptr<Hunter> hunter : hunterList) {
		Vector2f direction = player.getPosition() - hunter->getPosition();

		if (abs(direction.x) > abs(direction.y)) {
			hunter->getSprite()->setTexture(direction.x > 0 ? hunterTextureRight : hunterTextureLeft);
		}
		else {
			hunter->getSprite()->setTexture(direction.y > 0 ? hunterTextureBot : hunterTextureTop);
		}

		if (hunter->getAnimationClock().getElapsedTime().asSeconds() >= 0.2f) {
			hunter->getAnimationClock().restart();
			continueAnimation(hunter->getSprite());
		}
	}

}
