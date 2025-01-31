// Zelda_like.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Global.hpp"
#include "Entity.hpp"
#include "Tile.hpp"
#include "GameUpdate.hpp"
#include "UserInput.hpp"
#include "MainScreen.hpp"
#include "Map.hpp"
#include "Collisions.hpp"

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
    
    MainScreen mainscreen;
    map1.loadExterior(tileMap, player);

    thread uInputThread(userInput);
    uInputThread.detach();
    thread collisionThread(collisionsProcess);
    collisionThread.detach();


    mainscreen.MainScreenInit();
    while (isGameRunning) {
        
        if (isInMenu) {

            mainscreen.MainScreenUpdate();
            window.clear();
            mainscreen.MainScreenDraw();



            while (window.pollEvent(event)) {
                if (event.type == Event::KeyPressed and Keyboard::isKeyPressed(Keyboard::Escape)) {
                    cout << "close\n";
                    /*isPauseMenu = true;*/
                    isGameRunning = false;
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (hoverButtonExit)
                        window.close();

                    if (hoverButtonPlay)
                        isInMenu = false;
                }
                    else if (event.type == Event::Closed) { isGameRunning = false; }
                
            }
        }
        //Game Start
        else if (!isInMenu) {

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

        if (!playable) {
            if (map1.getCurrentMap() == map1.EXTERIOR) {
                map1.loadDungeon(tileMap, player);
                map1.setCurrentMap(map1.DUNGEON);
            }
            else if (map1.getCurrentMap() == map1.DUNGEON) {
                map1.loadExterior(tileMap, player);
                map1.setCurrentMap(map1.EXTERIOR);
            }
            moneyList.clear();
            playable = true;
        }

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
                if (tile->getLayer() == 1) {
                    window.draw(*tile->getSprite());
                }
            }
        }
        for (shared_ptr<Tile> tile : tileMap) {
            if (tile) {
                if (tile->getLayer() == 2 and tile->getSprite()->getPosition().y <= player.getSprite()->getPosition().y) {
                    window.draw(*tile->getSprite());
                }
            }
        }
        for (shared_ptr<Money> money : moneyList) {
            if (money) {
                window.draw(*money->getSprite());
            }
        }

            window.draw(*player.getSprite());

        for (shared_ptr<Tile> tile : tileMap) {
            if (tile) {
                if (tile->getLayer() == 2 and tile->getSprite()->getPosition().y > player.getSprite()->getPosition().y) {
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

            RectangleShape attRange(player.getActionRange().getSize());
            attRange.setPosition(player.getActionRange().getPosition());
            attRange.setFillColor(Color(220, 80, 255, 150));
            window.draw(attRange);
        }

            window.draw(*hpBar);
        }
            window.display();
        
    }
}