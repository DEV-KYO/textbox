//
// Created by Jonas Mendoza on 4/27/24.
//

#ifndef TEXT_INPUT_PROJECT_HISTORYNODE_H
#define TEXT_INPUT_PROJECT_HISTORYNODE_H
#include "../GUIComponents/Snapshot/SnapshotInterface.h"
#include "../GUIComponents/GUIComponent.h"


struct HistoryNode
{
    Snapshot snapshot;
    GUIComponent* component;
};

#endif //TEXT_INPUT_PROJECT_HISTORYNODE_H
