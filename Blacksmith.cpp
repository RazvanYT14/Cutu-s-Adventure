#include "Blacksmith.hpp"
#include <SFML/Graphics.hpp>
#include "Button.hpp"

void blacksmithDetection(float& px, float& py, char (*propsMap)[35], sf::RenderWindow& window, sf::Font& f,
                         Button& SwordGetBut, Button& SpearGetBut, Button& ScytheGetBut) {
    sf::RectangleShape uiBackground;
    uiBackground.setSize({400.f,500.f});
    uiBackground.setPosition({200.f, 50.f});
    uiBackground.setFillColor(sf::Color(127, 127, 127, 240));
    uiBackground.setOutlineColor(sf::Color(83, 83, 83, 250));
    uiBackground.setOutlineThickness(8.f);

    sf::RectangleShape uiTop;
    uiTop.setSize({400.f,50.f});
    uiTop.setPosition({200.f, 50.f});
    uiTop.setFillColor(sf::Color(83, 83, 83, 250));

    sf::Text uiText(f);
    uiText.setString("Blacksmith");
    uiText.setPosition({260.f, 49.f});
    uiText.setScale({1.5f,1.5f});

    int intX = scInt(px);
    int intY = scInt(py);

    if (propsMap[intY + 1][intX] == 65 ||
        propsMap[intY - 1][intX] == 65 ||
        propsMap[intY][intX + 1] == 65 ||
        propsMap[intY][intX - 1] == 65) {
        window.draw(uiBackground);
        window.draw(uiTop);
        window.draw(uiText);
        SwordGetBut.draw(window);
        SpearGetBut.draw(window);
        ScytheGetBut.draw(window);
    }
}
