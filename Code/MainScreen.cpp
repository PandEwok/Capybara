#include "MainScreen.hpp"


using namespace std;
using namespace sf;

void MainScreen::MainScreenInit() {
    background.setTexture(backgroundTexture);
    background.setScale(Vector2f(1.17f,1.0f));
    //background.setOrigin(background.getLocalBounds().width / 2, background.getLocalBounds().height / 2);
    //background.setPosition(desktop.width / 2, desktop.height / 2);

    buttonPlay.setTexture(buttonPlayTexture);
    buttonPlay.setScale(Vector2f(0.7f, 0.7f));
    buttonPlay.setOrigin(buttonPlay.getLocalBounds().width / 2, buttonPlay.getLocalBounds().height / 2);
    buttonPlay.setPosition(screenWidth / 2, screenHeight / 2-150);

    buttonExit.setTexture(buttonExitTexture);
    buttonExit.setScale(Vector2f(0.7f, 0.7f));
    buttonExit.setOrigin(buttonExit.getLocalBounds().width / 2, buttonExit.getLocalBounds().height / 2);
    buttonExit.setPosition(screenWidth / 2, screenHeight / 2);

    buttonOptions.setTexture(backgroundTexture);
    buttonOptions.setScale(Vector2f(0.6f, 0.6f));
    buttonOptions.setOrigin(buttonOptions.getLocalBounds().width / 2, buttonOptions.getLocalBounds().height / 2);
    buttonOptions.setPosition(screenWidth / 2 - 250, screenHeight / 2);
}

void MainScreen::MainScreenUpdate() {
    // Update the mouse position every frame
    mousePosition = Mouse::getPosition(window);

    // Check if the mouse is hovering over the button
    hoverButtonPlay = buttonPlay.getGlobalBounds().contains(Vector2f(mousePosition));
    hoverButtonExit = buttonExit.getGlobalBounds().contains(Vector2f(mousePosition));

    // Change the texture accordingly
    buttonPlay.setTexture(hoverButtonPlay ? buttonPlayHoverTexture : buttonPlayTexture);
    buttonExit.setTexture(hoverButtonExit ? buttonExitHoverTexture : buttonExitTexture);
}


void MainScreen::MainScreenDraw() {
    window.draw(background);
    window.draw(buttonPlay);
    window.draw(buttonExit);
    //window.draw(buttonOptions);
}