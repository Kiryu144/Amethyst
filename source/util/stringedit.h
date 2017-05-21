/* Created by David Klostermann on 21.05.2017. */
#ifndef AMETHYST_STRINGEDIT_H
#define AMETHYST_STRINGEDIT_H

#include <string>
#include <vector>
#include <sstream>

namespace AM {

static std::vector<std::string> splitString(std::string &s, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(s);

    std::string part;
    while (std::getline(ss, part, delim)) {
        parts.push_back(part);
    }

    return parts;
}

}

#endif
