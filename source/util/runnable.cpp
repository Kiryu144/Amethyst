/* Created by David Klostermann on 13.08.2017. */
#include "runnable.h"

AM::Runnable::Runnable(void (*function)()) {
    this->m_function = function;
}

void AM::Runnable::cancel() {
    m_cancel = true;
}

bool AM::Runnable::isCanceled() {
    return m_cancel;
}

AM::LoopedRunnable::LoopedRunnable(void (*function)(), long timeInbetweenRun, double maxRunAmount) : Runnable(function) {
    m_time = timeInbetweenRun;
    m_max = maxRunAmount;
    m_lastTime = AM::getTime() - timeInbetweenRun;
}

AM::LoopedRunnable::LoopedRunnable(void (*function)(), long timeInbetweenRun) : Runnable(function) {
    LoopedRunnable(function, timeInbetweenRun, 0);
}

void AM::LoopedRunnable::update() {
    if(m_max != 0 && m_i >= m_max){
        this->cancel();
    }else{
        double currentTime = AM::getTime();
        if(currentTime - m_lastTime >= m_time){
            m_lastTime = currentTime;
            m_i++;
            m_function();
        }
    }
}


