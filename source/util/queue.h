/* Created by David Klostermann on 10.07.2017. */
#ifndef AMETHYST_QUEUE_H
#define AMETHYST_QUEUE_H

#include <deque>
#include <algorithm>

namespace AM {

//Kinda like a reverse stack
template <typename T>
class Queue {
private:
    std::deque<T> data;

    auto getIterator(T& element){
        return std::find(data.begin(), data.end(), element);
    }
public:
    bool contains(T& element){
        this->getIterator(element) != data.end();
    }

    void add(T& element){
        if(!this->contains(element)){
            data.push_back(element);
        }
    }

    void remove(T& element){
        auto it = this->getIterator(element);
        if(it != data.end()){
            data.erase(it);
        }
    }

    int size(){
        return data.size();
    }

    T capBottom(){
        T t = data.at(0);
        data.erase(data.begin());
        return t;
    }
};

}

#endif
