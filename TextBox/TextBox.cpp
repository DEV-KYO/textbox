//
// Created by Jonas Mendoza on 4/28/24.
//

#include "TextBox.h"

TextBox::TextBox() {
    shape.setSize(sf::Vector2f(200, TEXT_SIZE + 10));
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setPosition(1, 20);
    active.enableState();

}


void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(shape, states);
    window.draw(label, states);
    window.draw(cursor, states);
    //Draw all the letters
    for (auto &letter : letters) {
        window.draw(letter, states);
    }
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TextBox::update() {
    cursor.update();
    if (!letters.empty()) {
        cursor.setPosition(letters.back().getPosition() + sf::Vector2f(10, 1));
    }
    else {
        cursor.setPosition(shape.getPosition() + sf::Vector2f(2, 4));
    }
    for (auto &letter : letters) {
        letter.update();
    }
}

void TextBox::addLetter(LetterObject addedLetter) {
    if (!letters.empty()) {
        // Get the position of the last letter
        sf::Vector2f lastLetterPos = letters.back().getPosition();

        // Set the position of the new letter to be next to the last one
        addedLetter.setPosition(lastLetterPos + sf::Vector2f(LETTER_WIDTH, 0));
    }

    letters.push_back(addedLetter);
}
void TextBox::removeLetter() {
    if (!letters.empty()) {
        letters.pop_back();
    }
}

bool TextBox::isEnabled() const {
    return active.getState();
}

void TextBox::setState(ObjectState state) {
    active.toggleState();
    cursor.setState(state);
    for(auto &letter : letters) {
        letter.setState(state);
    }
}

sf::FloatRect TextBox::getLocalBounds() const {
    return shape.getLocalBounds();
}

sf::FloatRect TextBox::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

sf::RectangleShape &TextBox::getShape() {
    return shape;
}




