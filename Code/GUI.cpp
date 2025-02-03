#include "GUI.hpp"

sf::RectangleShape pauseOverlay;
sf::Text pauseText;
sf::Sprite resumeButton;
sf::Sprite quitButton;

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

    // Set up the pause overlay (semi-transparent)
    pauseOverlay.setSize(sf::Vector2f(screenWidth, screenHeight));
    pauseOverlay.setFillColor(sf::Color(0, 0, 0, 150)); // Black with 150 transparency

    // Set up the pause text
    pauseText.setFont(font);
    pauseText.setCharacterSize(40.5);
    pauseText.setFillColor(sf::Color::White);
    pauseText.setString("Paused");
    pauseText.setOrigin(pauseText.getLocalBounds().width / 2, pauseText.getLocalBounds().height / 2);

    resumeButton.setTexture(resumeButtonTexture);
    resumeButton.setScale(Vector2f(4.5f,4.5f));
    resumeButton.setOrigin(resumeButton.getLocalBounds().width / 2, resumeButton.getLocalBounds().height / 2);
    
    quitButton.setTexture(quitButtonTexture);
    quitButton.setScale(Vector2f(4.5f, 4.5f));
    quitButton.setOrigin(quitButton.getLocalBounds().width / 2, quitButton.getLocalBounds().height / 2);

}

void drawGUI() {
    sf::View oldView = window.getView();
    

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
    if (isInPauseMenu) {
        window.setView(window.getDefaultView());
        window.draw(pauseOverlay);
        pauseText.setPosition(screenWidth / 2, screenHeight / 2 - 300);
        resumeButton.setPosition(screenWidth / 2, screenHeight / 2 - 100);
        quitButton.setPosition(screenWidth / 2, screenHeight / 2+100);
        window.draw(resumeButton);
        window.draw(quitButton);
        window.draw(pauseText);
        
    }
    window.setView(oldView);
}

void updateGUI() {
    //UPDATE
    mousePosition = Mouse::getPosition(window);

    // Check if the mouse is hovering over the button
    hoverButtonResume = resumeButton.getGlobalBounds().contains(Vector2f(mousePosition));
    hoverButtonQuit = quitButton.getGlobalBounds().contains(Vector2f(mousePosition));

    // Change the texture accordingly
    resumeButton.setTexture(hoverButtonResume ? resumeButtonHoverTexture : resumeButtonTexture);
    quitButton.setTexture(hoverButtonQuit ? quitButtonHoverTexture : quitButtonTexture);

}