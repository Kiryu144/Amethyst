/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_LOGGER_H
#define AMETHYST_LOGGER_H

#include <iostream>

namespace AM {

class Logger {
public:
    template<typename T>
    static void info(T info, int level, bool endl = true) {
        std::cout << "[INFO] " << info;
        if (endl) {
            std::cout << std::endl;
        }
    }

    template<typename T>
    static void warning(T warn, int level, bool endl = true) {
        std::cout << "[WARNING] " << warn;
        if (endl) {
            std::cout << std::endl;
        }
    }

    template<typename T>
    static void error(T err, bool endl = true) {
        std::cout << "[ERROR] " << err;
        if (endl) {
            std::cout << std::endl;
        }
    }
};

}

#endif
