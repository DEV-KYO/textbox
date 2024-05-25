//
// Created by Jonas Mendoza on 4/26/24.
//

#ifndef TEXT_INPUT_PROJECT_GUICOMPONENT_H
#define TEXT_INPUT_PROJECT_GUICOMPONENT_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "EventHandler/EventHandler.h"
#include "snapshot/SnapshotInterface.h"
#include "../States/States.h"

class GUIComponent  :   public EventHandler,
//                      public SnapshotInterface,
                        public States,
                        public sf::Drawable,
                        public sf::Transformable {

};


#endif //TEXT_INPUT_PROJECT_GUICOMPONENT_H
