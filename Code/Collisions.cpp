#include "Collisions.hpp"

vector<shared_ptr<Money>> toDeleteCoins;

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
		}
	}
}
