/* Created by David Klostermann on 13.08.2017. */
#include "scheduler.h"

std::vector<AM::Runnable*> AM::Scheduler::m_runnables;

static void registerRunnable(AM::Runnable* runnable);
static void update();

void AM::Scheduler::registerRunnable(AM::Runnable *runnable) {
    m_runnables.push_back(runnable);
}

void AM::Scheduler::update() {
    for(int i = 0; i < m_runnables.size(); i++){
        Runnable* runnable = m_runnables.at(i);
        if(runnable->isCanceled()){
            delete(runnable);
            m_runnables.erase(m_runnables.begin() + i);
        }else{
            runnable->update();
        }
    }
}
