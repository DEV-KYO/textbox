//
// Created by Jonas Mendoza on 4/27/24.
//

#ifndef TEXT_INPUT_PROJECT_FONTMANAGER_H
#define TEXT_INPUT_PROJECT_FONTMANAGER_H
#include <map>
#include <SFML/Graphics/Font.hpp>
#include "EnumFonts.h"

class FontManager {
private:
    static std::map<EnumFonts, sf::Font> fonts;
    static void loadFont(EnumFonts font);
    static std::string getFontPath(EnumFonts font);

public:
    static sf::Font& getFont(EnumFonts font);

};


#endif //TEXT_INPUT_PROJECT_FONTMANAGER_H
