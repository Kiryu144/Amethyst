/* Created by David Klostermann on 13.08.2017. */
#ifndef AMETHYST_RUNNABLE_H
#define AMETHYST_RUNNABLE_H

#include "math/time.h"

namespace AM{

class Runnable{
protected:
    void (*m_function)();
    bool m_cancel = false;

    void cancel();
public:
    Runnable(void (*function)());
    bool isCanceled();
    virtual void update() = 0;
};

class LoopedRunnable : public Runnable {
protected:
    double m_i = 0; //How often the function was called by now
    double m_max = 0; //Hof often the function has to be called before it cancels
    long m_time;
    long m_lastTime;
public:
    LoopedRunnable(void (*function)(), long timeInbetweenRun, double maxRunAmount);
    LoopedRunnable(void (*function)(), long timeInbetweenRun);
    void update();
};


}


#endif
