#pragma once
#include "data.hpp"

struct Button {
    sf::Sprite m_sprite;
    std::function<void()> m_callback;

    sf::Vector2f m_baseScale;
    bool m_isPressed = false;
    mutable bool m_hasBeenClicked = false;

    // Flag-urile inteligente pentru urmărirea cadrelor (fără pâlpâit)
    bool m_wasDrawnThisFrame = false;
    bool m_wasDrawnLastFrame = false;

    Button(sf::Texture& texture, float x, float y, sf::Vector2f scaleFactor)
        : m_sprite(texture), m_baseScale(scaleFactor)
    {
        m_sprite.setPosition({x, y});
        m_sprite.setScale(m_baseScale);
    }

    void setCallback(std::function<void()> callback);
    void handleEvent(const sf::Event& event, sf::Vector2f mouseOrTouchPos);
    void draw(sf::RenderWindow& window);

    bool isClicked() const;
};
