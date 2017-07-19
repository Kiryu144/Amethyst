/* Created by David Klostermann on 17.05.2017. */
#ifndef AMETHYST_AMETHYSTEXCEPTION_H
#define AMETHYST_AMETHYSTEXCEPTION_H

#include <cstring>
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#include <string>
#include <ctime>

class __AmethystException{
private:
    int m_errorID;
    std::string m_exc;
    time_t m_triggerTime;
public:

    __AmethystException(int id, std::string exc, std::string file, unsigned int line){
        this->m_errorID = id;
        if(file.size() > 0) {
            this->m_exc = "[" + file + ":" + std::to_string(line) + ", " + std::to_string(id) + "] " + exc;
        }else{
            this->m_exc = exc;
        }
        m_triggerTime = time(0);
    }

    __AmethystException(int id, std::string exc = "NULL"){
        __AmethystException(id, exc, "", 0);
    }

    std::string getExceptionString(){
        return m_exc;
    }

    time_t getTriggerTime(){
        return m_triggerTime;
    }

    int getID(){
        return m_errorID;
    }
};

#define throwAmethystException(id, exc) throw(__AmethystException(id, exc, __FILENAME__, __LINE__));

#endif
