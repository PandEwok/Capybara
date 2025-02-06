#include "Collisions.hpp"

vector<shared_ptr<Money>> toDeleteCoins;
vector<shared_ptr<MarketItem>> toDeleteMarketItem;
vector<shared_ptr<Sword>> toDeleteSword;
vector<shared_ptr<Axe>> toDeleteAxe;
vector<shared_ptr<Dagger>> toDeleteDagger;

//a

void collisionsProcess()
{
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

			for (int i = 0; i < tileMap.size(); i++) {
				if (tileMap[i]); {
					shared_ptr<Tile> tile = tileMap[i];
					if (tile->getSprite() and tile->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
						if (tile->getType() == "Trap" and tile->getSprite()->getTextureRect().getPosition().x != 0) {
							player.decreaseHp();
						}
					}
				}
			}
		}
	}
}
