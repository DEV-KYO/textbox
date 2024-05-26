//
// Created by Jonas Mendoza on 4/27/24.
//

#ifndef TEXT_INPUT_PROJECT_HISTORY_H
#define TEXT_INPUT_PROJECT_HISTORY_H
#include "HistoryNode.h"
#include <stack>
#include <SFML/Window/Event.hpp>

class History : public GUIComponent{
private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //TEXT_INPUT_PROJECT_HISTORY_H
