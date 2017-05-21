/* Created by David Klostermann on 17.05.2017. */
#ifndef AMETHYST_FASTREADER_H
#define AMETHYST_FASTREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <streambuf>

#include "util/amethystexception.h"

namespace AM {

static bool fileExists(std::string path){
    if (FILE *file = fopen(path.c_str(), "r")) {
        fclose(file);
        return true;
    }else{
        return false;
    }
}

static void readFile(std::string path, std::vector<char>& data){
    if(!fileExists(path)){
        throwAmethystException("Could not read file " + path);
    }

    std::ifstream f(path.c_str());

    f.seekg(0, std::ios::end);
    data.reserve(f.tellg());
    f.seekg(0, std::ios::beg);

    data.assign(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
}

static void readFile(std::string path, std::string& data){
    std::vector<char> rawData;
    readFile(path, rawData);
    data.reserve(rawData.size());
    data.assign(rawData.begin(), rawData.end());
}

}

#endif
