#include "UserInput.hpp"
#include "Map.hpp"




void userInput() {
    Event event;
    Clock mainClock;
    vector<shared_ptr<Tile>> toDeleteTiles = {};
    while (isGameRunning) {
        timeSinceLastFrameInputs = mainClock.restart();

        for (shared_ptr<Tile> tile : toDeleteTiles) {
            auto pos = find(tileMap.begin(), tileMap.end(), tile);
            tileMap.erase(pos);
        }
        toDeleteTiles.clear();

        if (Mouse::isButtonPressed(Mouse::Left) and !player.getIsAttacking()) {
            player.setIsAttacking(true);
        }

        inputMovement = Vector2f(0, 0.f);
        if (!player.getIsAttacking()) {

            if (Keyboard::isKeyPressed(Keyboard::Scancode::A)) {
                inputMovement += Vector2f(-1.f, 0.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Scancode::W)) {
                inputMovement += Vector2f(0, -1.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Scancode::S)) {
                inputMovement += Vector2f(0, 1.f);
            }
            if (Keyboard::isKeyPressed(Keyboard::Scancode::D)) {
                inputMovement += Vector2f(1, 0.f);
            }

            if (inputMovement.y > 0) {
                player.facing = player.FRONT;
            }
            else if (inputMovement.y < 0) {
                player.facing = player.BACK;
            }
            if (inputMovement.x > 0) {
                player.facing = player.RIGHT;
            }
            else if (inputMovement.x < 0) {
                player.facing = player.LEFT;
            }


            if (player.facing == player.FRONT) {
                if (player.getSprite()->getTexture() != &playerTextureFrontIdle and inputMovement == Vector2f(0, 0)) {
                    player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                    player.getSprite()->setTexture(playerTextureFrontIdle);
                }
                else if (player.getSprite()->getTexture() != &playerTextureFrontWalk and inputMovement != Vector2f(0, 0)) {
                    player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                    player.getSprite()->setTexture(playerTextureFrontWalk);
                }
                if (player.getSprite()->getScale().x < 0) {
                    player.getSprite()->setScale(player.getSprite()->getScale().x * (-1.f), player.getSprite()->getScale().y);
                }
            }
            else if (player.facing == player.BACK) {
                if (player.getSprite()->getTexture() != &playerTextureBackIdle and inputMovement == Vector2f(0, 0)) {
                    player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                    player.getSprite()->setTexture(playerTextureBackIdle);
                }
                else if (player.getSprite()->getTexture() != &playerTextureBackWalk and inputMovement != Vector2f(0, 0)) {
                    player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                    player.getSprite()->setTexture(playerTextureBackWalk);
                }
                if (player.getSprite()->getScale().x < 0) {
                    player.getSprite()->setScale(player.getSprite()->getScale().x * (-1.f), player.getSprite()->getScale().y);
                }
            }
            else if (player.facing == player.RIGHT or player.facing == player.LEFT) {
                if (player.getSprite()->getTexture() != &playerTextureSideIdle and inputMovement == Vector2f(0, 0)) {
                    player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                    player.getSprite()->setTexture(playerTextureSideIdle);
                }
                else if (player.getSprite()->getTexture() != &playerTextureSideWalk and inputMovement != Vector2f(0, 0)) {
                    player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                    player.getSprite()->setTexture(playerTextureSideWalk);
                }
            }
            if ((player.facing == player.LEFT and player.getSprite()->getScale().x > 0) or (player.facing == player.RIGHT and player.getSprite()->getScale().x < 0)) {
                player.getSprite()->setScale(player.getSprite()->getScale().x * (-1.f), player.getSprite()->getScale().y);
            }
        }
        else {
            if (player.facing == player.FRONT and player.getSprite()->getTexture() != &playerTextureFrontAttack) {
                player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                player.getSprite()->setTexture(playerTextureFrontAttack);
            }
            else if (player.facing == player.BACK and player.getSprite()->getTexture() != &playerTextureBackAttack) {
                player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                player.getSprite()->setTexture(playerTextureBackAttack);
            }
            else if (player.facing == player.RIGHT and player.getSprite()->getTexture() != &playerTextureSideAttack) {
                player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                player.getSprite()->setTexture(playerTextureSideAttack);
            }
            else if (player.facing == player.LEFT and player.getSprite()->getTexture() != &playerTextureSideAttack) {
                player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                player.getSprite()->setTexture(playerTextureSideAttack);
            }
        }

        for (int i = 0; i < marketItemList.size(); i++) {
            shared_ptr<MarketItem> item = marketItemList[i];
            if (item->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
                if (inputMovement.y > 0 and item->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(0, 14))) {
                    inputMovement = Vector2f(inputMovement.x, 0);
                }
                else if (inputMovement.y < 0 and item->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(0, 8))) {
                    inputMovement = Vector2f(inputMovement.x, 0);
                }
                else if (inputMovement.x > 0 and item->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(8, 11))) {
                    inputMovement = Vector2f(0, inputMovement.y);
                }
                else if (inputMovement.x < 0 and item->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(-8, 11))) {
                    inputMovement = Vector2f(0, inputMovement.y);
                }
            }
        }
        
        for (int i = 0; i < tileMap.size(); i++) {
            shared_ptr<Tile> tile = tileMap[i];
            if (tile->getSprite()->getGlobalBounds().intersects(player.getHitBox())) {
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
                if (tile->getType() == "Wall" or tile->getType() == "Door" or tile->getType() == "Pot") {
                    if (inputMovement.y > 0 and tile->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(0, 14))) {
                        inputMovement = Vector2f(inputMovement.x, 0);
                    }
                    else if (inputMovement.y < 0 and tile->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(0, 8))) {
                        inputMovement = Vector2f(inputMovement.x, 0);
                    }
                    else if (inputMovement.x > 0 and tile->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(8, 11))) {
                        inputMovement = Vector2f(0, inputMovement.y);
                    }
                    else if (inputMovement.x < 0 and tile->getSprite()->getGlobalBounds().contains(player.getSprite()->getPosition() + Vector2f(-8, 11))) {
                        inputMovement = Vector2f(0, inputMovement.y);
                    }
                }
                if ((tile->getType() == "Gate" and isGateOpen) or tile->getType() == "HouseDoor" or tile->getType() == "ShopDoor") {
                    Vector2f boundsPos = tile->getSprite()->getGlobalBounds().getPosition();
                    Vector2f boundsSize = tile->getSprite()->getGlobalBounds().getSize();
                    FloatRect gateHitBox = FloatRect(boundsPos.x, boundsPos.y + boundsSize.y / 3.f, boundsSize.x, boundsSize.y / 3.f * 2.f);
                    if (gateHitBox.intersects(player.getHitBox())) {
                        playable = false;
                        goingThrough = tile->getType();
                        isShadeIncreasing = true;
                        player.getSprite()->setTextureRect(IntRect(0, 0, player.getSprite()->getTextureRect().width, player.getSprite()->getTextureRect().height));
                        if (player.facing == player.FRONT) {
                            player.getSprite()->setTexture(playerTextureFrontIdle);
                        }
                        else if (player.facing == player.BACK) {
                            player.getSprite()->setTexture(playerTextureBackIdle);
                        }
                        else if (player.facing == player.RIGHT) {
                            player.getSprite()->setTexture(playerTextureSideIdle);
                        }
                        else if (player.facing == player.LEFT) {
                            player.getSprite()->setTexture(playerTextureSideIdle);
                        }
                        thread shadeThread(shadeScreen);
                        shadeThread.detach();
                        while (!playable) {}
                        mainClock.restart();
                        break;
                    }
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
        player.move();
    }
}