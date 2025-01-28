// Zelda_like.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Global.hpp"
#include "Entity.hpp"
#include "Tile.hpp"
#include "GameUpdate.hpp"
#include "UserInput.hpp"

using namespace std;

int main()
{
    srand(time(0));
    /*Image icon; icon.loadFromFile("icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());*/

    loadTextures();

    Event event;
    Clock mainClock;
    Game game;

    fstream map("Images/map.txt");
    string line;
    Vector2f tilePosition = Vector2f(0, 0);
    while (true) {
        getline(map, line);
        if (line == ";") {
            break;
        }
        for (char tileChar : line) {
            if (tileChar == '0' or tileChar == '8' or tileChar == '9' or tileChar == 'o' or tileChar == '6' or tileChar == '7' or tileChar == 'u'
                or tileChar == 'q' or tileChar == 'p' or tileChar == 'f' or tileChar == 'g' or tileChar == 'c' or tileChar == 'e' or tileChar == 'a' or tileChar == 'F') {
                shared_ptr<Wall> newTile = make_shared<Wall>(tilePosition);
                if (tileChar == '9') {
                    newTile->getSprite()->setTexture(grassWallSideTexture);
                }
                else if (tileChar == '8') {
                    newTile->getSprite()->setTexture(grassWallSideTexture);
                    newTile->getSprite()->setScale(-1, 1);
                    newTile->getSprite()->move(Vector2f(16, 0));
                }
                else if (tileChar == 'o') {
                    newTile->getSprite()->setTexture(grassWallDownTexture);
                }
                /*else if (tileChar == '6') {
                    newTile->getSprite()->setTexture(wallTileMiddleTexture);
                }*/
                /*else if (tileChar == 'u') {
                    newTile->getSprite()->setTexture(wallTileMiddleEndTexture);
                }*/
                /*else if (tileChar == '7') {
                    newTile->getSprite()->setTexture(wallTileIntersectionTexture);
                }*/
                /*else if (tileChar == 'q') {
                    newTile->getSprite()->setTexture(wallTileIntersectionSideTexture);
                }*/
                /*else if (tileChar == 'p') {
                    newTile->getSprite()->setTexture(wallTileIntersectionSideTexture);
                    newTile->getSprite()->setScale(-1, 1);
                    newTile->getSprite()->move(Vector2f(16, 0));
                }*/
                /*else if (tileChar == 'f') {
                    newTile->getSprite()->setTexture(wallTileBackIntersectionTexture);
                }*/
                /*else if (tileChar == 'g') {
                    newTile->getSprite()->setTexture(wallTileBackIntersectionTexture);
                    newTile->getSprite()->setScale(-1, 1);
                    newTile->getSprite()->move(Vector2f(16, 0));
                }*/
                else if (tileChar == 'a') {
                    newTile->getSprite()->setTexture(grassWallDownEndTexture);
                }
                else if (tileChar == 'e') {
                    newTile->getSprite()->setTexture(grassWallDownEndTexture);
                    newTile->getSprite()->setScale(-1, 1);
                    newTile->getSprite()->move(Vector2f(16, 0));
                }
                else if (tileChar == 'g') {
                    newTile->getSprite()->setTexture(grassWallTopEndTexture);
                }
                else if (tileChar == 'c') {
                    newTile->getSprite()->setTexture(grassWallTopEndTexture);
                    newTile->getSprite()->setScale(-1, 1);
                    newTile->getSprite()->move(Vector2f(16, 0));
                }
                /*tileMap.push_back(newTile);
                if (tileChar == 'F') {
                    shared_ptr<Flag> newFlag = make_shared<Flag>(tilePosition);
                    tileMap.push_back(newFlag);
                }*/
                tileMap.push_back(newTile);
            }
            else if (tileChar == '1') {
                shared_ptr<Floor> newTile = make_shared<Floor>(tilePosition);
                int randTile = rand() % 100;
                if (randTile < 30) {
                    newTile->getSprite()->setTexture(grassTile2Texture);
                }
                tileMap.push_back(newTile);
            }
            else if (tileChar == '$') {
                shared_ptr<Floor> newTile = make_shared<Floor>(tilePosition);
                tileMap.push_back(newTile);
                player.getSprite()->setPosition(tilePosition + Vector2f(8, 8));
            }
            else if (tileChar == '~') {
                shared_ptr<Floor> newTile = make_shared<Floor>(tilePosition);
                newTile->getSprite()->setTexture(waterTileTexture);
                tileMap.push_back(newTile);
            }
            else if (tileChar == 'B') {
                shared_ptr<Floor> newTile = make_shared<Floor>(tilePosition);
                newTile->getSprite()->setTexture(waterTileTexture);
                tileMap.push_back(newTile);
                shared_ptr<Bridge> newBridge = make_shared<Bridge>(tilePosition);
                tileMap.push_back(newBridge);
            }
            else if (tileChar == 'T') {
                shared_ptr<Floor> newTile = make_shared<Floor>(tilePosition);
                tileMap.push_back(newTile);
                shared_ptr<Tree> newTree = make_shared<Tree>(tilePosition);
                tileMap.push_back(newTree);
            }
            /*else if (tileChar == '4' or tileChar == '5') {
                shared_ptr<Floor> newFloor = make_shared<Floor>(tilePosition);
                tileMap.push_back(newFloor);
                shared_ptr<Door> newTile = make_shared<Door>(tilePosition);
                if (tileChar == '5') {
                    newTile->getSprite()->setTexture(doorTileRightTexture);
                }
                tileMap.push_back(newTile);
            }*/
            tilePosition.x += 16;
        }
        tilePosition.y += 16;
        tilePosition.x = 0;
    }

    thread uInputThread(userInput);
    uInputThread.detach();

    while (isGameRunning) {
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed and Keyboard::isKeyPressed(Keyboard::Escape)) {
                cout << "close\n";
                /*isPauseMenu = true;*/
                isGameRunning = false;
            }
            else if (event.type == Event::Closed) { isGameRunning = false; }
            else if (event.type == Event::KeyPressed and Keyboard::isKeyPressed(Keyboard::Scancode::H)) {
                showHitbox = showHitbox == false;
            }
        }
        mainView.setCenter(player.getSprite()->getPosition());
        window.setView(mainView);

        timeSinceLastFrame = mainClock.restart();
        game.update();

        window.clear();

        for (shared_ptr<Tile> tile : tileMap) {
            if (tile) {
                if (tile->getLayer() == 0) {
                    window.draw(*tile->getSprite());
                }
            }
        }
        for (shared_ptr<Tile> tile : tileMap) {
            if (tile) {
                if (tile->getLayer() == 1 and tile->getSprite()->getPosition().y <= player.getSprite()->getPosition().y) {
                    window.draw(*tile->getSprite());
                }
            }
        }

        window.draw(*player.getSprite());

        for (shared_ptr<Tile> tile : tileMap) {
            if (tile) {
                if (tile->getLayer() == 1 and tile->getSprite()->getPosition().y > player.getSprite()->getPosition().y) {
                    window.draw(*tile->getSprite());
                }
            }
        }

        // hitbox display
        if (showHitbox) {
            RectangleShape hb(player.getHitBox().getSize());
            hb.setPosition(player.getHitBox().getPosition());
            hb.setFillColor(Color(0, 180, 255, 150));
            window.draw(hb);
            RectangleShape point(Vector2f(1, 1));
            point.setFillColor(Color(255, 0, 0));
            point.setPosition(player.getSprite()->getPosition() + Vector2f(0, 14));
            window.draw(point);
            point.setPosition(player.getSprite()->getPosition() + Vector2f(0, 8));
            window.draw(point);
            point.setPosition(player.getSprite()->getPosition() + Vector2f(8, 11));
            window.draw(point);
            point.setPosition(player.getSprite()->getPosition() + Vector2f(-8, 11));
            window.draw(point);
        }

        window.draw(*hpBar);

        window.display();
    }
}