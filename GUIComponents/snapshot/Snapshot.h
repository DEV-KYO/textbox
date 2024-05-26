//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_SNAPSHOT_H
#define TEXT_INPUT_PROJECT_SNAPSHOT_H
#include <string>

class Snapshot {
private:
    std::string text;

public:
    Snapshot(const std::string& text) : text(text) {}

    [[nodiscard]] const std::string& getText() const {
        return text;
    }



};


#endif //TEXT_INPUT_PROJECT_SNAPSHOT_H
