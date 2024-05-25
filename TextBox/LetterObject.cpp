//
// Created by Jonas Mendoza on 4/26/24.
//

#include "LetterObject.h"


LetterObject::LetterObject() {
    text = sf::Text();
    text.setFont(FontManager::getFont(EnumFonts::PIXELGEORGIA));
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(sf::Color::White);
    text.setPosition(1, TEXT_BOX_Y + 3);
}


void LetterObject::update() {

}

void LetterObject::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void LetterObject::setCharacter(char typedChar) {
    text.setString(typedChar);
}

sf::Vector2f LetterObject::getPosition() {
    return text.getPosition();
}

void LetterObject::setPosition(const sf::Vector2f& position) {
    text.setPosition(position);
}

void LetterObject::setState(ObjectState state) {
    if(state == ENABLED)
        text.setFillColor(sf::Color::White);
    else {
        text.setFillColor(sf::Color::Red);
    }
}

sf::FloatRect LetterObject::getLocalBounds() const {
    return text.getLocalBounds();
}
