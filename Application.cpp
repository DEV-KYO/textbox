//
// Created by Jonas Mendoza on 4/26/24.
//

#include "Application.h"

#include "KeyboardShortcuts/KeyboardShortcuts.h"

Application::Application() {

    //Create the window with a resolution of "pixelWidth" x "pixelHeight"
    unsigned int pixelWidth = 600; ///sf::VideoMode::getDesktopMode().width;
    unsigned int pixelHeight = 800; ///sf::VideoMode::getDesktopMode().height;

    //Create the window using given resolution and title
    window.create(sf::VideoMode(
            pixelWidth,
            pixelHeight
            ), "Text Input Project");

    //Set the framerate limit to 60
    window.setFramerateLimit(60);

}


void Application::run() {

    std::cout   << "APPLICATION STARTING"
                << std::endl;

    //Main loop of the application
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }

    std::cout   << std::endl
                << "APPLICATION CLOSING"
                << std::endl;
}

void Application::processEvents() {

    //MAIN EVENT OBJECT
    sf::Event event{};

    //The event loop that will process all events that are happening in the window
    //This loop will run as long as there are events to process

    while(window.pollEvent(event))
    {
        //switch statement that determines what type of event is happening
        //Events can be anything from closing the window to pressing a key
        switch (event.type)
        {
            //Close window
            case sf::Event::Closed:
                window.close();
                break;

            //Mouse Button Pressed
            case sf::Event::MouseButtonPressed:
                std::cout << "Mouse Button Pressed" << std::endl;

                //This calls the addEventHandler function in the TextBox class
                textBox.addEventHandler(window, event);
            break;

            //Key Pressed
            case sf::Event::KeyPressed:

                //Every time a key is pressed, a new event is added to the history
                //History will eventually be expanded to include more than just key presses
                History::EventHistory(window, event);

                //This switch statement will determine what key was pressed
                switch(event.key.code)
                {
                    //Escape key
                    case sf::Keyboard::Escape:
                        window.close();
                    break;

                    //Backspace key
                    case sf::Keyboard::BackSpace:
                        textBox.removeLetter();
                    break;
                }
            break;

            // This event is triggered when text is entered
            case sf::Event::TextEntered:
                //This calls the addEventHandler function in the TextBox class
                textBox.addEventHandler(window, event);
                break;
        }
    }
}

void Application::update()
{
    textBox.update();
}

void Application::render() {
    window.clear({sf::Color::Black});
    draw();
    window.display();
}

void Application::draw() {
    textBox.draw(window, sf::RenderStates::Default);
}