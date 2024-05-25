//
// Created by Jonas Mendoza on 4/28/24.
//

#ifndef TEXT_INPUT_PROJECT_TEXTBOX_H
#define TEXT_INPUT_PROJECT_TEXTBOX_H
#include <vector>

//SFML
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

//FOLDERS
#include "Cursor.h"
#include "Label.h"
#include "LetterObject.h"
#include "../States/States.h"
#include "../Font/EnumFonts.h"
#include "../Font/FontManager.h"
#include "_LOCAL_CONSTANTS.h"


class TextBox : public GUIComponent {

private:
    //Variables
    sf::RectangleShape shape;           //Shape of the text box
    Label label;                        //Label object
    Cursor cursor;                      //Cursor object
    std::vector<LetterObject> letters;  //Vector of letters
    States active;                        //Boolean to check if the text box is active

public:
    TextBox();

    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void addLetter(LetterObject addedLetter);
    void removeLetter();

    bool isEnabled() const;
    void setState(ObjectState state);


    //Getters

    //Get local bounds
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    sf::RectangleShape& getShape();


};


#endif //TEXT_INPUT_PROJECT_TEXTBOX_H