/* Created by David Klostermann on 17.05.2017. */
#ifndef AMETHYST_FASTREADER_H
#define AMETHYST_FASTREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <streambuf>

#include "util/amethystexception.h"

#define AM_FASTFILEIO_FILE_NOT_EXISTS 1
#define AM_FASTFILEIO_COULD_NOT_READ  2

namespace AM {

static bool fileExists(std::string path){
    if (FILE *file = fopen(path.c_str(), "r")) {
        fclose(file);
        return true;
    }else{
        return false;
    }
}

template <typename T>
static void readFile(std::string path, std::vector<T>& data){
    if(!fileExists(path)){
        throwAmethystException(AM_FASTFILEIO_FILE_NOT_EXISTS, "File does not exist!");
    }

    try{
        std::ifstream f(path.c_str(), std::ios::binary);

        data.assign((std::istreambuf_iterator<char>(f)),
                    (std::istreambuf_iterator<char>()));
    }catch(...){
        throwAmethystException(AM_FASTFILEIO_COULD_NOT_READ, "File could not be read!")
    }
}

static void readFile(std::string path, std::string& data){
    std::vector<char> rawData;
    readFile(path, rawData);

    try{
        data.reserve(rawData.size());
        data.assign(rawData.begin(), rawData.end());
    }catch(...){
        throwAmethystException(AM_FASTFILEIO_COULD_NOT_READ, "File could not be read!")
    }
}

}

#endif
