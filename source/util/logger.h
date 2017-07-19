/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_LOGGER_H
#define AMETHYST_LOGGER_H

#include <iostream>

namespace AM {

class Logger {
public:
    template<typename T>
    static void info(T info) {
        std::cout << "[INFO] " << info << std::endl;
    }

    template<typename T>
    static void warning(T warn) {
        std::cout << "[WARNING] " << warn;
    }

    template<typename T>
    static void error(T err) {
        std::cerr << "[ERROR] " << err << std::endl;
    }
};

}

#endif
