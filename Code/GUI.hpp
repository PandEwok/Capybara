#pragma once

#include "Global.hpp"
#include <iostream>

extern Vector2i mousePosition;
extern sf::RectangleShape pauseOverlay;
extern sf::Text pauseText;
extern sf::Sprite resumeButton;
extern sf::Sprite quitButton;


void initGUI();

void drawGUI();

void updateGUI();

