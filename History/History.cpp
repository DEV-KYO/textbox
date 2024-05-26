//
// Created by Jonas Mendoza on 4/27/24.
//

#include "History.h"

#include "../KeyboardShortcuts/KeyboardShortcuts.h"

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.key.code == KeyboardShortcuts::isUndo() && !stack.empty()) {
        HistoryNode node = stack.top();
        stack.pop();
    }
}
