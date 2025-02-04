#include "Collisions.hpp"

vector<shared_ptr<Money>> toDeleteCoins;
vector<shared_ptr<Sword>> toDeleteSword;
vector<shared_ptr<Axe>> toDeleteAxe;
vector<shared_ptr<Dagger>> toDeleteDagger;

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
		}
	}
}
