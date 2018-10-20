#ifndef TASK_1_TENNIS_CLASSES_H
#define TASK_1_TENNIS_CLASSES_H

#include <iostream>
#include <string>

class ITennisCenter {
public:
    virtual void book_time() {}
    virtual void send_tournament_invitation() = 0;
};

// class A
class TennisPlayer {
public:
    TennisPlayer(ITennisCenter *tennisCenter) : tennisCenter(tennisCenter) {}
    void book_time() {
        tennisCenter->book_time();
    }

private:
    ITennisCenter *tennisCenter;
};

// class B
class TennisCenter : public ITennisCenter {
public:
    void book_time() override {
        std::cout << "Time booked in TC." << std::endl;
    }
    void send_tournament_invitation() override {
        std::cout << std::string("TC sent a tournament invitation.") << std::endl;
    }
};

#endif //TASK_1_TENNIS_CLASSES_H
