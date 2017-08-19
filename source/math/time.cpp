/* Created by David Klostermann on 25.05.2017. */
#include "time.h"

double AM::DeltaTime::m_lastTime;
float AM::DeltaTime::m_deltaTime;
float AM::DeltaTime::m_bigDeltaTime;

void update();
float getDeltaTime();
float getBigDeltaTime();

void AM::DeltaTime::update() {
    double currentTime = glfwGetTime();
    m_deltaTime = currentTime - m_lastTime;
    m_lastTime = currentTime;
    m_bigDeltaTime = m_deltaTime * BIG_DELTATIME_FACTOR;
}

float AM::DeltaTime::getDeltaTime() {
    return m_deltaTime;
}

float AM::DeltaTime::getBigDeltaTime() {
    return m_bigDeltaTime;
}

float AM::FPS::getFPS() {
    return 1.0f/DeltaTime::getDeltaTime();
}