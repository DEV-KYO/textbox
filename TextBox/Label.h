//
// Created by Jonas Mendoza on 4/28/24.
//

#ifndef TEXT_INPUT_PROJECT_LABEL_H
#define TEXT_INPUT_PROJECT_LABEL_H

//SFML
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

//FOLDERS
#include "../Font/EnumFonts.h"
#include "../Font/FontManager.h"
#include "_LOCAL_CONSTANTS.h"

class Label : public sf::Drawable {
private:
    sf::Text text;
    sf::Font font;
    EnumFonts fontType;
    std::string textString;
    sf::Vector2f position;
    sf::Color color;
    unsigned int fontSize{};
    sf::Text::Style style;



public:
    Label();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setText(const std::string &textString);
};


#endif //TEXT_INPUT_PROJECT_LABEL_H
