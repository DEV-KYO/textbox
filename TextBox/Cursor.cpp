#include "Cursor.h"

Cursor::Cursor() {
    cursor.setSize(sf::Vector2f(1, TEXT_SIZE));
    cursor.setFillColor(sf::Color::White);
    cursor.setPosition(3, TEXT_BOX_Y + 1);
    cursorInterval = 0.5;
    visible = true;
    cursorStates.enableState();
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(visible && cursorStates.getState())
        window.draw(cursor, states);
}

void Cursor::update() {
    if(clock.getElapsedTime().asSeconds() > cursorInterval  && cursorStates.getState())
    {
        visible = !visible;
        clock.restart();
    }
}

void Cursor::setPosition(const sf::Vector2f &position) {
    cursor.setPosition(position);
}

void Cursor::setSize(const sf::Vector2f &size) {
    cursor.setSize(size);
}

void Cursor::setFillColor(const sf::Color &color) {
    cursor.setFillColor(color);
}

void Cursor::setOutlineColor(const sf::Color &color) {
    cursor.setOutlineColor(color);
}

void Cursor::setState(ObjectState state) {
    if(state == ENABLED) {
        cursorStates.enableState();
        visible = state;
    } else {
        cursorStates.disableState();
        visible = state;
    }
}

void Cursor::getPosition() {
    cursor.getPosition();
}


