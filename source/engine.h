/* Created by David Klostermann on 20.07.2017. */
#ifndef AMETHYST_INIT_H
#define AMETHYST_INIT_H

#include "amethyst"

namespace AM{

static bool framestart(bool updateWindow, bool clearWindow){
    bool running = true;
    if(updateWindow){
        running = AM::WindowHandler::update(clearWindow);
    }
    AM::Time::update();
    AM::InputController::process();
    return running;
}

}

#endif
