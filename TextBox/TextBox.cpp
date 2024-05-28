//
// Created by Jonas Mendoza on 4/28/24.
//

#include "TextBox.h"

#include "../KeyboardShortcuts/KeyboardShortcuts.h"

TextBox::TextBox() {
    shape.setSize(sf::Vector2f(200, TEXT_SIZE + 10));
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(1);
    shape.setPosition(1, 20);
    active.enableState();
    text_box_snapshot = Snapshot();
    History::pushHistory({text_box_snapshot, this});

}

// Draw the shape, label, cursor, and all the letters
void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(shape, states);
    window.draw(label, states);
    window.draw(cursor, states);
    //Draw all the letters
    for (auto &letter : letters) {
        window.draw(letter, states);
    }
}

// Add an event handler to the text box
void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        if (MouseEvents<sf::RectangleShape>::mouseClicked(shape, window)) {
            std::cout << "Mouse Clicked on TextBox" << std::endl;
            setState(ENABLED);
        } else {
            std::cout << "Mouse Clicked outside TextBox" << std::endl;
            setState(DISABLED);
        }
    }
    if(event.type == sf::Event::TextEntered) {
        if (isEnabled() && event.text.unicode < 128 && event.text.unicode != '\b' && event.text.unicode != 26) { // We only handle ASCII
            char typedChar = static_cast<char>(event.text.unicode);

            // Create a new LetterObject with the typed character
            LetterObject newLetter;
            newLetter.setCharacter(typedChar);

            // Add the new LetterObject to the letters vector
            addLetter(newLetter);
        } else if (event.text.unicode > 127 || event.text.unicode == 26)
            std::cout << "Invalid character" << std::endl;

    }
}

// Update the cursor and all the letters
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

Snapshot &TextBox::getSnapshot() {
    std::map<std::string, std::any> snapshotData;
    snapshotData["letters"] = letters;

    text_box_snapshot = Snapshot(snapshotData);
    return text_box_snapshot;
}

void TextBox::applySnapshot(const Snapshot &snapshot_in) {
    text_box_snapshot = snapshot_in;
    if (text_box_snapshot.getCount() > 0) {
        letters = std::any_cast<std::vector<LetterObject>>(text_box_snapshot.getSnapshot("letters"));
    } else {
        // Handle the case where the "letters" key doesn't exist in the snapshot
        // For example, you might want to clear the letters vector
        letters.clear();
    }
}


// Add a snapshot of the text box
void TextBox::addLetter(LetterObject addedLetter) {
    if (!letters.empty()) {
        // Get the position of the last letter
        sf::Vector2f lastLetterPos = letters.back().getPosition();

        // Set the position of the new letter to be next to the last one
        addedLetter.setPosition(lastLetterPos + sf::Vector2f(LETTER_WIDTH, 0));
    }
    else {
        // Set the position of the new letter to be at the beginning of the text box
        addedLetter.setPosition(shape.getPosition() + sf::Vector2f(2, 4));
    }

    letters.push_back(addedLetter);

    getSnapshot();

    // Create a snapshot and push it to the history stack
    History::pushHistory({text_box_snapshot, this});
}


// Remove a letter from the text box
void TextBox::removeLetter() {
    if (!letters.empty()) {
        letters.pop_back();

        getSnapshot();

        History::pushHistory({text_box_snapshot, this});
    }
    else {
        std::cout << "No letters to remove" << std::endl;
    }
}

// Check if the text box is enabled
bool TextBox::isEnabled() const {
    return active.getState();
}

// Set the state of the text box
void TextBox::setState(ObjectState state) {
    active.toggleState();
    cursor.setState(state);
    for(auto &letter : letters) {
        letter.setState(state);
    }
}

// Add a snapshot of the text box
sf::FloatRect TextBox::getLocalBounds() const {
    return shape.getLocalBounds();
}

// Add a snapshot of the text box
sf::FloatRect TextBox::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

// Add a snapshot of the text box
sf::RectangleShape &TextBox::getShape() {
    return shape;
}




