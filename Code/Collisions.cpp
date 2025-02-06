#include "Collisions.hpp"

vector<shared_ptr<Money>> toDeleteCoins;
vector<shared_ptr<Sword>> toDeleteSword;
vector<shared_ptr<Axe>> toDeleteAxe;
vector<shared_ptr<Dagger>> toDeleteDagger;

//a

void collisionsProcess() {
	vector<shared_ptr<Tile>> toDeleteTiles = {};
	while (isGameRunning) {
		if (playable) {
			// Coins
			toDeleteCoins = {};
			for (shared_ptr<Money> coin : moneyList) {
				if (coin) {
					if (coin->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
						toDeleteCoins.push_back(coin);
						coin->interact(player);
					}
				}
			}
			for (shared_ptr<Money> coin : toDeleteCoins) {
				auto pos = find(moneyList.begin(), moneyList.end(), coin);
				moneyList.erase(pos);
			}
			toDeleteMarketItem = {};
			for (shared_ptr<MarketItem> item : marketItemList) {
				if (item) {
					if (item->getSprite()->getGlobalBounds().intersects(player.getHitBox()) and item->getPrice() <= playerMoney) {
						toDeleteMarketItem.push_back(item);
						item->interact(player);
					}
				}
			}
			for (shared_ptr<MarketItem> item : toDeleteMarketItem) {
				auto pos = find(marketItemList.begin(), marketItemList.end(), item);
				marketItemList.erase(pos);
			}

			toDeleteSword = {};
			for (shared_ptr<Sword> sdword : swordad) {
				if (sdword) {
					if (sdword->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
						toDeleteSword.push_back(sdword);
						sdword->interact(player);

					}
				}
			}

			toDeleteAxe = {};
			for (shared_ptr<Axe> adxe : axead) {
				if (adxe) {
					if (adxe->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
						toDeleteAxe.push_back(adxe);
						adxe->interact(player);
					}
				}
			}

			toDeleteDagger = {};
			for (shared_ptr<Dagger> dadgger : daggerad) {
				if (dadgger) {
					if (dadgger->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
						toDeleteDagger.push_back(dadgger);
						dadgger->interact(player);
					}
				}
			}

			toDeleteTiles = {};
			unique_lock<mutex> lock(mtx);
			for (int i = 0; i < tileMap.size(); i++) {
				shared_ptr<Tile> tile = tileMap[i];
				if (tile->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
					if (tile->getType() == "Trap" and tile->getSprite()->getTextureRect().getPosition().x != 0) {
						player.decreaseHp();
					}
					if (tile->getType() == "Door" and player.getKeyState() > 0) {

						if (find(toDeleteTiles.begin(), toDeleteTiles.end(), tileMap[i]) == toDeleteTiles.end()) {
							player.setKeyState(player.getKeyState() - 1);
							toDeleteTiles.push_back(tile);
						}
						if (i > 1) {
							if (tileMap[i - 2]->getType() == "Door" and find(toDeleteTiles.begin(), toDeleteTiles.end(), tileMap[i - 2]) == toDeleteTiles.end()) {
								toDeleteTiles.push_back(tileMap[i - 2]);
							}
						}
						if (i + 2 < tileMap.size() - 1) {
							if (tileMap[i + 2]->getType() == "Door" and find(toDeleteTiles.begin(), toDeleteTiles.end(), tileMap[i + 2]) == toDeleteTiles.end()) {
								toDeleteTiles.push_back(tileMap[i + 2]);
							}
						}
						continue;
					}
				}
				if (tile->getSprite()->getGlobalBounds().intersects(player.getActionRange())) {
					if (tile->getType() == "Pot" and Mouse::isButtonPressed(Mouse::Left)) {
						toDeleteTiles.push_back(tile);
						shared_ptr<Money> newMoney = make_shared<Money>();
						newMoney->getSprite()->setPosition(tile->getSprite()->getPosition());
						moneyList.push_back(newMoney);
					}
				}
			}
			for (shared_ptr<Tile> tile : toDeleteTiles) {
				
				auto pos = find(tileMap.begin(), tileMap.end(), tile);
				tileMap.erase(pos);
			}
			toDeleteTiles.clear();
		}
	}
}
