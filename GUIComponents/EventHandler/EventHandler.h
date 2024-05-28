//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_EVENTHANDLER_H
#define TEXT_INPUT_PROJECT_EVENTHANDLER_H

#include <SFML/Graphics/RenderWindow.hpp>

class EventHandler {
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //TEXT_INPUT_PROJECT_EVENTHANDLER_H
