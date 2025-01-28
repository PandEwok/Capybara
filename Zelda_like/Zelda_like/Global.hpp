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
extern Time timeSinceLastFrame;
extern Time timeSinceLastFrameInputs;

extern Texture hpBarTexture;
extern shared_ptr<Sprite> hpBar;
extern Vector2f inputMovement;
extern int playerScore;
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

void loadTextures();

void continueAnimation(shared_ptr<Sprite> sprite);

Vector2f normalize(Vector2f value);