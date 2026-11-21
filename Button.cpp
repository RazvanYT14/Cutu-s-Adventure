#include "data.hpp"
#include "Button.hpp"

void Button::setCallback(std::function<void()> callback) {
    m_callback = callback;
}

void Button::handleEvent(const sf::Event& event, sf::Vector2f mouseOrTouchPos) {
    bool isStartAction = event.is<sf::Event::MouseButtonPressed>() || event.is<sf::Event::TouchBegan>();

    // Când jocul procesează un eveniment nou, mutăm cadrele o singură dată
    static const sf::Event* lastEvent = nullptr;
    if (&event != lastEvent) {
        m_wasDrawnLastFrame = m_wasDrawnThisFrame;
        m_wasDrawnThisFrame = false;
        lastEvent = &event;
    }

    // Butonul este activ doar dacă a fost trimis spre randare în cadrul curent sau anterior
    bool isCurrentlyVisible = m_wasDrawnThisFrame || m_wasDrawnLastFrame;

    if (!isCurrentlyVisible) {
        if (isStartAction) {
            m_isPressed = false;
        }
        return;
    }

    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    bool startAction = false;
    bool endAction = false;

    if (auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mousePressed->button == sf::Mouse::Button::Left) {
            startAction = true;
        }
    } else if (auto* touchBegan = event.getIf<sf::Event::TouchBegan>()) {
        if (touchBegan->finger == 0) {
            startAction = true;
        }
    }

    if (startAction && bounds.contains(mouseOrTouchPos)) {
        m_isPressed = true;
        m_sprite.setScale(m_baseScale * 0.92f);
        m_sprite.setColor(sf::Color(200, 200, 200, 200));
    }

    if (auto* mouseReleased = event.getIf<sf::Event::MouseButtonReleased>()) {
        if (mouseReleased->button == sf::Mouse::Button::Left) {
            endAction = true;
        }
    } else if (auto* touchEnded = event.getIf<sf::Event::TouchEnded>()) {
        if (touchEnded->finger == 0) {
            endAction = true;
        }
    }

    if (endAction) {
        m_sprite.setScale(m_baseScale);
        m_sprite.setColor(sf::Color::White);

        if (m_isPressed && bounds.contains(mouseOrTouchPos)) {
            m_hasBeenClicked = true;
            if (m_callback) m_callback();
        }
        m_isPressed = false;
    }
}

void Button::draw(sf::RenderWindow& window) {
    // Ori de câte ori structura ta de if-uri din main rulează .draw(), butonul confirmă că e pe ecran
    m_wasDrawnThisFrame = true;
    window.draw(m_sprite);
}

bool Button::isClicked() const {
    bool isCurrentlyVisible = m_wasDrawnThisFrame || m_wasDrawnLastFrame;
    if (!isCurrentlyVisible) {
        return false;
    }

    if (m_hasBeenClicked) {
        m_hasBeenClicked = false;
        return true;
    }
    return false;
}
