/* Created by David Klostermann on 25.05.2017. */
#ifndef AMETHYST_TIME_H
#define AMETHYST_TIME_H

#define BIG_DELTATIME_FACTOR 12.5f

#include <chrono>
#include "view/window.h"

typedef std::chrono::high_resolution_clock::time_point time_point;
typedef std::chrono::high_resolution_clock::duration duration;

namespace AM {

static time_point currentTimePoint() {
    return std::chrono::high_resolution_clock::now();
}

static int getTime() {
    return std::clock();
}

class DeltaTime {
private:
    static double m_lastTime;
    static float m_deltaTime;
    static float m_bigDeltaTime; //With 120FPS you should have a factor of 0.1
public:
    static void update();
    static float getDeltaTime();
    static float getBigDeltaTime();
};

class FPS {
public:
    static float getFPS();
};

namespace Time {

static void update() {
    DeltaTime::update();
}

}

}

#endif
