#include <iostream>

#include "Application.h"


int main() {
    //container class that holds
    //      .run
    Application app;

    app.run();

    std::cout   << std::endl
                << std::endl
                << std::endl
                << "PROGRAM END" << std::endl;

    return 0;
}
