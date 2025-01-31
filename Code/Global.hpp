#pragma once

#include <iostream>
#include <fstream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <memory>
#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>

using namespace std;
using namespace sf;

extern string whiteString;
extern string greenString;
extern string redString;

extern float screenWidth, screenHeight;
extern RenderWindow window;
extern View mainView;
extern bool isGameRunning;
extern bool playable;
extern Time timeSinceLastFrame;
extern Time timeSinceLastFrameInputs;

//Menu Variables
extern bool isInMenu;
extern Vector2i mousePosition;
extern bool hoverButtonPlay;
extern bool hoverButtonExit;




extern Texture hpBarTexture;
extern shared_ptr<Sprite> hpBar;
extern Vector2f inputMovement;
extern int playerMoney;
extern Texture playerKeyTexture;
extern shared_ptr<Sprite> playerKey;
extern bool showHitbox;

//player textures
extern Texture playerTextureFrontIdle;
extern Texture playerTextureFrontWalk;
extern Texture playerTextureBackIdle;
extern Texture playerTextureBackWalk;
extern Texture playerTextureSideIdle;
extern Texture playerTextureSideWalk;

//tiles textures
	//exterior textures
extern Texture grassTile1Texture;
extern Texture grassTile2Texture;
extern Texture grassWallDownTexture;
extern Texture grassWallSideTexture;
extern Texture grassWallDownEndTexture;
extern Texture grassWallTopTexture;
extern Texture grassWallTopEndTexture;
extern Texture waterTileTexture;
extern Texture bridgeTexture;
extern Texture treeTexture;
extern Texture highGroundTile;
extern Texture doorExteriorTileTecture;
extern Texture potTexture;
	//dungeon textures
extern Texture wallTileTexture;
extern Texture wallTileSideTexture;
extern Texture wallTileBackTexture;
extern Texture wallTileBackEndTexture;
extern Texture wallTileBackIntersectionTexture;
extern Texture wallTileMiddleTexture;
extern Texture wallTileMiddleEndTexture;
extern Texture wallTileIntersectionTexture;
extern Texture wallTileIntersectionSideTexture;
extern Texture floorTileTexture;
extern Texture doorTileLeftTexture;
extern Texture doorTileRightTexture;
extern Texture flagTileTexture;
extern Texture candleTexture;

//items textures
extern Texture rubyTexture;
extern Texture swordTexture;
extern Texture axeTexture;
extern Texture daggerTexture;

//Main Menu Textures
extern Texture backgroundTexture;
extern Texture buttonPlayTexture;
extern Texture buttonPlayHoverTexture;
extern Texture buttonExitTexture;
extern Texture buttonExitHoverTexture;

//Main Menu Sprites
extern Sprite background;
extern Sprite buttonPlay;
extern Sprite buttonOptions;
extern Sprite buttonExit;
extern Vector2i mousePosition;
extern bool hoverButtonPlay;


void loadTextures();

void continueAnimation(shared_ptr<Sprite> sprite);

Vector2f normalize(Vector2f value);
