//
// (c) 2024 Eduardo Doria.
//

#ifndef PANEL_COMPONENT_H
#define PANEL_COMPONENT_H

#include "util/FunctionSubscribe.h"

namespace Supernova{

    enum class PanelEdge{
        NONE,
        RIGHT,
        RIGHT_BOTTOM,
        BOTTOM,
        LEFT_BOTTOM,
        LEFT
    };

    struct PanelComponent{
        Entity headerimage = NULL_ENTITY;
        Entity headercontainer = NULL_ENTITY;
        Entity headertext = NULL_ENTITY;

        AnchorPreset titleAnchorPreset = AnchorPreset::CENTER;

        bool canMove = true;
        bool canResize = true;
        bool canTopOnFocus = true;

        bool headerPointerDown = false;
        PanelEdge edgePointerDown = PanelEdge::NONE;

        bool needUpdatePanel = true;
    };

}

#endif //PANEL_COMPONENT_H