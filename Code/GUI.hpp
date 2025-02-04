#pragma once

#include "Global.hpp"
#include <iostream>
#include "Player.hpp"
#include "GameUpdate.hpp"

extern Vector2i mousePosition;
extern RectangleShape pauseOverlay;
extern Text pauseText;
extern Sprite resumeButton;
extern Sprite quitButton;

void initGUI();

void drawGUI();

void updateGUI();

