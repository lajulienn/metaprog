#ifndef TASK_1_PATTERN_H
#define TASK_1_PATTERN_H

#include <iostream>
#include <string>

#include "tennis-classes.h"

class Proxy {};
class Mediator {};
class Observer {};

template <class T>
class Pattern {
public:
    std::string info() { return std::string("Unsupported template type."); }
};

template <>
class Pattern<Proxy> : public ITennisCenter {
public:
    Pattern(TennisCenter &tennisCenter) : tennisCenter(tennisCenter) {}
private:
    TennisCenter tennisCenter;
public:
    void book_time() override {
        std::cout << "Proxy is booking time." << std::endl;
        tennisCenter.book_time();
    }
    void send_tournament_invitation() override {
        std::cout << "Proxy is sending invitation." << std::endl;
        tennisCenter.send_tournament_invitation();
    }
};


#endif //TASK_1_PATTERN_H
