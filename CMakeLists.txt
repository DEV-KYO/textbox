cmake_minimum_required(VERSION 3.15)

project(sfml_template)

# Tell CMake to build a executable
add_executable(${PROJECT_NAME} main.cpp
        TextBox/Cursor.cpp
        TextBox/Label.cpp
        TextBox/Label.cpp
        TextBox/TextBox.cpp
        TextBox/LetterObject.cpp
        TextBox/LetterObject.cpp
        Application.cpp
        States/States.cpp
        KeyboardShortcuts/KeyboardShortcuts.cpp
        History/History.cpp
        GUIComponents/GUIComponent.cpp
        GUIComponents/snapshot/Snapshot.cpp
        Font/FontManager.cpp)

# CMake SFML Project uses C++17 features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS NO CXX_STANDARD_REQUIRED YES)

# Set SFML_ROOT
set(SFML_ROOT "C:/SFML-2.6.1")

# Set SFML_DIR
set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics system window REQUIRED)

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)

# Install executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)
