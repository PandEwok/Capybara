#pragma once

#include "Global.hpp"
#include "Player.hpp"
#include "GameUpdate.hpp"

extern Vector2i mousePosition;
extern RectangleShape pauseOverlay;
extern Text pauseText;
extern Sprite resumeButton;
extern Sprite quitButton;
extern Sprite gameOverScreen;
extern Text gameOverText;


void initGUI();

void drawGUI();

void updateGUI();

