//
// Created by Jonas Mendoza on 4/28/24.
//

#ifndef TEXT_INPUT_PROJECT_CURSOR_H
#define TEXT_INPUT_PROJECT_CURSOR_H

//SFML
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

//FOLDERS
#include "../States/States.h"
#include "_LOCAL_CONSTANTS.h"

class Cursor : public sf::Drawable {
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    bool visible;
    float cursorInterval;
    States cursorStates;


public:
    Cursor();
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void update();
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    void setFillColor(const sf::Color& color);
    void setOutlineColor(const sf::Color& color);
    void setState(ObjectState state);



    void getPosition();
};


#endif //TEXT_INPUT_PROJECT_CURSOR_H
