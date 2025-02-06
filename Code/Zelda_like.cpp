// Zelda_like.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Global.hpp"
#include "Entity.hpp"
#include "Tile.hpp"
#include "GameUpdate.hpp"
#include "UserInput.hpp"
#include "MainScreen.hpp"
#include "Map.hpp"
#include  "Collisions.hpp"
#include "GUI.hpp"

using namespace std;

void pauseSongs() {
    overworldTheme.setVolume(overworldTheme.getVolume()-1);
    dungeonTheme.setVolume(dungeonTheme.getVolume()-1);
}

void unpauseSongs() {
    overworldTheme.setVolume(45.f);
    dungeonTheme.setVolume(45.f);
}

int main()
{
    srand(time(0));
    Image icon; icon.loadFromFile("icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    loadTextures();
    loadSound();

    Event event;
    Clock mainClock;
    Game game;
    MainScreen mainscreen;
    
    map1.loadHouse(tileMap, player);

    thread uInputThread(userInput);
    uInputThread.detach();
    thread collisionThread(collisionsProcess);
    collisionThread.detach();


    mainscreen.MainScreenInit();
    initGUI();

    //Music Settings
    titleTheme.setVolume(60.f);
    titleTheme.setLoop(true);
    titleTheme.play();
    

    overworldTheme.setVolume(55.f);
    overworldTheme.setLoop(true);

    dungeonTheme.setVolume(45.f);
    dungeonTheme.setLoop(true);

    //Sound Settings
    slashSFX.setVolume(250.f);
    potBreakSFX.setVolume(50.f);


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
                if (event.type == Event::MouseButtonPressed) {
                    if (hoverButtonExit)
                        window.close();

                    if (hoverButtonPlay) {
                        isInMenu = false;
                        titleTheme.stop();
                    }
                }
                else if (event.type == Event::Closed) { isGameRunning = false; }

            }
        }
        //Game Start
        else if (!isInMenu) {

            if (isInPauseMenu) {
                updateGUI();
                pauseSongs();
            }
            else {
                unpauseSongs();
            }
            while (window.pollEvent(event)) {
                if (event.type == Event::KeyPressed and Keyboard::isKeyPressed(Keyboard::Escape)) {
                    isInPauseMenu = true;
                }
                else if (event.type == Event::Closed) { isGameRunning = false; }
                else if (event.type == Event::KeyPressed and Keyboard::isKeyPressed(Keyboard::Scancode::H)) {
                    showHitbox = showHitbox == false;
                }
                if (event.type == Event::MouseButtonPressed) {
                    if (hoverButtonExit)
                        window.close();

                    if (hoverButtonPlay)
                        isInMenu = false;
                    if (isInPauseMenu) {
                        if (hoverButtonResume)
                            isInPauseMenu = false;
                        if (hoverButtonQuit)
                            isGameRunning = false;
                    }
                }
            }

            if (!isInPauseMenu) {
                mainView.setCenter(player.getSprite()->getPosition());
                window.setView(mainView);

                timeSinceLastFrame = mainClock.restart();
                game.update();
            }

            if (!playable) {
                if (shading.getFillColor().a >= 255) {
                    isShadeIncreasing = false;
                    npcList.clear();
                    if (goingThrough == "Gate") {
                        if (map1.getCurrentMap() == map1.EXTERIOR) {
                            map1.loadDungeon(tileMap, player);
                            map1.setCurrentMap(map1.DUNGEON);
                        }
                        else if (map1.getCurrentMap() == map1.DUNGEON) {
                            map1.loadExterior(tileMap, player);
                            map1.setCurrentMap(map1.EXTERIOR);
                        }
                    }
                    else if (goingThrough == "HouseDoor") {
                        if (map1.getCurrentMap() == map1.EXTERIOR) {
                            map1.loadHouse(tileMap, player);
                            map1.setCurrentMap(map1.HOUSE);
                        }
                        else if (map1.getCurrentMap() == map1.HOUSE) {
                            map1.loadExterior(tileMap, player);
                            map1.setCurrentMap(map1.EXTERIOR);
                        }
                    }
                    else if (goingThrough == "ShopDoor") {
                        if (map1.getCurrentMap() == map1.EXTERIOR) {
                            map1.loadShop(tileMap, player);
                            map1.setCurrentMap(map1.SHOP);
                        }
                        else if (map1.getCurrentMap() == map1.SHOP) {
                            map1.loadExterior(tileMap, player);
                            map1.setCurrentMap(map1.EXTERIOR);
                        }
                    }
                    moneyList.clear();
                }

                if (!isShadeIncreasing and shading.getFillColor().a <= 0) {
                    playable = true;
                }
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
            for (shared_ptr<Npc> npc : npcList) {
                if (npc->getSprite()->getPosition().y <= player.getSprite()->getPosition().y) {
                    window.draw(*npc->getSprite());
                    npc->displayName();
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
            for (shared_ptr<Npc> npc : npcList) {
                if (npc->getSprite()->getPosition().y > player.getSprite()->getPosition().y) {
                    window.draw(*npc->getSprite());
                    npc->displayName();
                }
            }

            for (int i = 0; i < tileMap.size(); i++) {
                shared_ptr<Tile> tile = tileMap[i];
                if (tile->getSprite()->getGlobalBounds().intersects(player.getSprite()->getGlobalBounds())) {
                    if (tile->getType() == "Gate" and !isGateOpen and hasGateKey) {
                        eKey->setPosition(tile->getSprite()->getPosition() + Vector2f(24, 4));
                        window.draw(*eKey);
                        if (Keyboard::isKeyPressed(Keyboard::Scancode::E)) {
                            hasGateKey = false;
                            isGateOpen = true;
                            continueAnimation(tile->getSprite());
                        }
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


            drawGUI();
            window.draw(shading);
        }
        window.display();

        if (!isInMenu) {
            if (map1.getCurrentMap() == map1.EXTERIOR) {
                if (overworldTheme.getStatus() != overworldTheme.Playing) {
                    overworldTheme.play();
                    dungeonTheme.pause();
                    houseTheme.pause();
                    shopTheme.pause();
                }
            }
            if (map1.getCurrentMap() == map1.DUNGEON) {
                if (dungeonTheme.getStatus() != dungeonTheme.Playing) {
                    dungeonTheme.play();
                    overworldTheme.pause();
                }
            }
            if (map1.getCurrentMap() == map1.HOUSE) {
                if (houseTheme.getStatus() != houseTheme.Playing) {
                    houseTheme.play();
                    overworldTheme.pause();
                }
            }
            if (map1.getCurrentMap() == map1.SHOP) {
                if (shopTheme.getStatus() != shopTheme.Playing) {
                    shopTheme.play();
                    overworldTheme.pause();
                }
            }
        }
    }
}