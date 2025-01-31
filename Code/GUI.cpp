#include "GUI.hpp"


void initGUI() {
    // Load font (make sure "font.ttf" exists in your project directory)
    if (!font.loadFromFile("Images/fonts/Super-Mario-World.ttf")) {
        cout << "Failed to load font!" << endl;
    }

    //PUMPCOIN
    // Set up the text
    pumpcoinText.setFont(font);
    //pumpcoinText.scale()
    pumpcoinText.setCharacterSize(8.5); // Adjust as needed
    pumpcoinText.setFillColor(sf::Color::White);
    pumpcoinText.setOutlineColor(sf::Color::Black);
    pumpcoinText.setOutlineThickness(1.0f);
    pumpcoinText.setString("x 0"); // Default value

    pumpcoinPouch.setTexture(pumpcoinPouchTexture);
    pumpcoinPouch.setScale(Vector2f(0.4f,0.4f));

    //GATEKEY
    gateKey.setTexture(gateKeyTexture);
    gateKey.setScale(Vector2f(0.8f, 0.8f));
    
    
}

void drawGUI() {
    cout << "Pumpcoin Position: " << pumpcoinPouch.getPosition().x << ", " << pumpcoinPouch.getPosition().y << endl;

    pumpcoinPouch.setPosition(mainView.getCenter().x-110, mainView.getCenter().y-50);
    gateKey.setPosition(mainView.getCenter().x - 110, mainView.getCenter().y+40);
    hpBar->setPosition(mainView.getCenter() + Vector2f(mainView.getSize().x / -2.f, mainView.getSize().y / 2.f) - Vector2f(0, hpBarTexture.getSize().y+99.20));


    pumpcoinText.setString("x " + to_string(playerMoney)); // Update the counter
    pumpcoinText.setPosition(pumpcoinPouch.getPosition().x+15, pumpcoinPouch.getPosition().y+1.5); // Adjust position

    // Draw elements
    window.draw(pumpcoinPouch);
    window.draw(pumpcoinText);
    window.draw(gateKey);
    window.draw(*hpBar);
}
