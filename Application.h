//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_APPLICATION_H
#define TEXT_INPUT_PROJECT_APPLICATION_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "TextBox/LetterObject.h"


#include <iostream>

#include "TextBox/TextBox.h"
#include "History/History.h"


class Application {
private:
    sf::RenderWindow window;        //This is the window that will be displayed
    TextBox textBox;                //This is the text box that will be displayed

public:
    Application();

    //Runs the application & main loop
    //It will run a while loop that will process events, update, and render
    void run();

    //Function called to draw function of any object
    //that needs to be drawn on the window
    void draw();

    //This function processes events that are happening in the window
    void processEvents();

    //This function updates the state of the application
    void update();

    //Renders all objects to the window
    void render();
};


#endif //TEXT_INPUT_PROJECT_APPLICATION_H
