/* Created by David Klostermann on 13.08.2017. */
#ifndef AMETHYST_SCHEDULER_H
#define AMETHYST_SCHEDULER_H

#include "runnable.h"

namespace AM{

class Scheduler {
private:
    static std::vector<Runnable*> m_runnables;
    Scheduler() {};
public:
    static void registerRunnable(Runnable* runnable);
    static void update();
};

}

#endif
