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
                textBox.addEventHandler(window, event);
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