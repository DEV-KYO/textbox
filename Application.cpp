//
// Created by Jonas Mendoza on 4/26/24.
//

#include "Application.h"

Application::Application() {

    unsigned int pixelWidth = 600; ///sf::VideoMode::getDesktopMode().width;
    unsigned int pixelHeight = 800; ///sf::VideoMode::getDesktopMode().height;



    window.create(sf::VideoMode(
            pixelWidth,
            pixelHeight
            ), "Text Input Project");
    window.setFramerateLimit(60);

}


void Application::run() {

    std::cout   << "APPLICATION STARTING"
                << std::endl;

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

    sf::Event event{};

    //Event Loop
    while(window.pollEvent(event))
    {
        //switch statement for event type
        switch (event.type)
        {

            //Close window
            case sf::Event::Closed:
                window.close();
                break;

            //Mouse Button Pressed
            case sf::Event::MouseButtonPressed:
                std::cout << "Mouse Button Pressed" << std::endl;
                if (MouseEvents<TextBox>::mouseClicked(textBox, window)) {
                    std::cout << "Mouse Clicked on TextBox" << std::endl;
                    textBox.setState(ENABLED);
                } else {
                    std::cout << "Mouse Clicked outside TextBox" << std::endl;
                    textBox.setState(DISABLED);
                }
            break;

            //Key Pressed
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    //Escape key
                    case sf::Keyboard::Escape:
                        window.close();
                    break;

                    case sf::Keyboard::BackSpace:
                        textBox.removeLetter();
                    break;
                }

                break;
            // Text entered
            case sf::Event::TextEntered:
                if (textBox.isEnabled() && event.text.unicode < 128 && event.text.unicode != '\b') { // We only handle ASCII
                    char typedChar = static_cast<char>(event.text.unicode);

                    // Create a new LetterObject with the typed character
                    LetterObject newLetter;
                    newLetter.setCharacter(typedChar);

                    // Add the new LetterObject to the letters vector
                    textBox.addLetter(newLetter);
                }
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