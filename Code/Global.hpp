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
extern Font font;
extern Font smallFont;
extern RectangleShape shading;
extern float shadeValue;
extern bool isShadeIncreasing;

extern bool isInPauseMenu;

//Menu Variables
extern bool isInMenu;
extern Vector2i mousePosition;
extern bool hoverButtonPlay;
extern bool hoverButtonExit;

extern bool hasGateKey;
extern bool isGateOpen;
extern string goingThrough;


extern Texture hpBarTexture;
extern shared_ptr<Sprite> hpBar;
extern Vector2f inputMovement;
extern int playerMoney;
extern Texture playerKeyTexture;
extern shared_ptr<Sprite> playerKey;
extern bool showHitbox;
extern Texture eKeyTexture;
extern Clock eKeyClock;
extern shared_ptr<Sprite> eKey;

//player textures
extern Texture playerTextureFrontIdle;
extern Texture playerTextureFrontWalk;
extern Texture playerTextureFrontAttack;
extern Texture playerTextureBackIdle;
extern Texture playerTextureBackWalk;
extern Texture playerTextureBackAttack;
extern Texture playerTextureSideIdle;
extern Texture playerTextureSideWalk;
extern Texture playerTextureSideAttack;

//npc textures
extern Texture shopKeeperTexture;

//tiles textures
	//exterior textures
extern Texture grassTile1Texture;
extern Texture grassTile2Texture;
extern Texture grassWallDownTexture;
extern Texture grassWallSideTexture;
extern Texture grassWallDownEndTexture;
extern Texture grassWallTopTexture;
extern Texture grassWallTopEndTexture;
extern Texture grassWallCornerTexture;
extern Texture waterTileTexture;
extern Texture bridgeTexture;
extern Texture treeTexture;
extern Texture highGroundTile;
extern Texture doorExteriorTileTexture;
extern Texture potTexture;
extern Texture houseTexture;
extern Texture houseDoorTexture;
extern Texture shopTexture;
extern Texture shopDoorTexture;
	//dungeon textures
extern Texture dungeonOffMapTexture;
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
extern Texture trapTexture;
	//house textures
extern Texture houseFloorTexture;
extern Texture houseWallTexture;
extern Texture houseWallBackTexture;
extern Texture houseWallTopCornerTexture;
extern Texture houseWallSideTexture;
extern Texture houseWallIntersectionTexture;
extern Texture houseExitTexture;

//items textures
extern Texture rubyTexture;
extern Texture swordTexture;
extern Texture axeTexture;
extern Texture daggerTexture;
extern Texture goldKeyTexture;

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

//GUI Sprites
extern Sprite pumpcoinPouch;
extern Sprite gateKey;
extern Sprite doorKey;

//GUI Textures
extern Texture pumpcoinPouchTexture;
extern Text pumpcoinText;
extern Text doorkeyText;
extern Texture gateKeyTexture;
extern Texture resumeButtonTexture;
extern Texture resumeButtonHoverTexture;
extern Texture quitButtonTexture;
extern Texture quitButtonHoverTexture;
extern Texture doorKeyTexture;

//GUI Interaction
extern bool hoverButtonResume;
extern bool hoverButtonQuit;

//Hunter Textures
extern Texture hunterTextureBot;
extern Texture hunterTextureTop;
extern Texture hunterTextureRight;
extern Texture hunterTextureLeft;

//Sounds
extern SoundBuffer pumpcoinCollectBuffer;
extern Sound pumpcoinCollectSFX;
extern SoundBuffer slashBuffer;
extern Sound slashSFX;
extern SoundBuffer potBreakBuffer;
extern Sound potBreakSFX;
extern SoundBuffer keyGetBuffer;
extern Sound keyGetSFX;

//Music
extern SoundBuffer titleThemeBuffer;
extern Sound titleTheme;
extern SoundBuffer overworldThemeBuffer;
extern Sound overworldTheme;
extern SoundBuffer dungeonThemeBuffer;
extern Sound dungeonTheme;
extern SoundBuffer houseThemeBuffer;
extern Sound houseTheme;
extern SoundBuffer shopThemeBuffer;
extern Sound shopTheme;


void loadTextures();
void loadSound();

void continueAnimation(shared_ptr<Sprite> sprite);

Vector2f normalize(Vector2f value);

void shadeScreen();