/* Created by David Klostermann on 17.05.2017. */
#ifndef AMETHYST_AMETHYSTEXCEPTION_H
#define AMETHYST_AMETHYSTEXCEPTION_H

#include <cstring>
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#include <string>
#include <ctime>

class __AmethystException{
private:
    std::string m_exc;
    time_t m_triggerTime;
public:

    __AmethystException(std::string exc, std::string file, unsigned int line){
        if(file.size() > 0) {
            this->m_exc = "[" + file + ":" + std::to_string(line) + "] " + exc;
        }else{
            this->m_exc = exc;
        }
        m_triggerTime = time(0);
    }

    __AmethystException(std::string exc){
        __AmethystException(exc, "", 0);
    }

    std::string getExceptionError(){
        return m_exc;
    }

    const char* what(){
        return m_exc.c_str();
    }

    time_t getTriggerTime(){
        return m_triggerTime;
    }
};

#define throwAmethystException(exc) throw(__AmethystException(exc, __FILENAME__, __LINE__));

#endif
