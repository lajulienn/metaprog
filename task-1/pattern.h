#ifndef TASK_1_PATTERN_H
#define TASK_1_PATTERN_H

#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <ctime>

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
  Pattern(TennisCenter &tennis_center) : tennis_center_(tennis_center) {}

  void BookTime() override {
    std::cout << "Proxy is booking time." << std::endl;
    tennis_center_.BookTime();
  }

  void GetInfo() override {
    std::cout << "Proxy is requesting info about the Tennis Center named" << std::endl;
    tennis_center_.GetInfo();
  }

 private:
  TennisCenter tennis_center_;
};

template <>
class Pattern<Mediator> : public ITennisCentersManager {
 public:
  Pattern(std::vector<ITennisCenter *> tennis_centers_list) : tennis_centers_list_(tennis_centers_list) {}

  void GetInfoAboutNearestCenter() override {
    std::cout << "Mediator is deciding what tennis center to use." << std::endl;
    int nearest = GetNearestCenter(tennis_centers_list_.size());
    tennis_centers_list_[nearest]->GetInfo();
  }

 private:
  std::vector<ITennisCenter *> tennis_centers_list_;

  int GetNearestCenter(int count) {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> distribution(0, count - 1);
    return distribution(gen);
  }
};

template <>
class Pattern<Observer> : public IPublisher {
 public:
  Pattern() : subscribers_(std::set<ISubscriber *>()) {}
  void Subscribe(ISubscriber *subscriber) { subscribers_.insert(subscriber); }
  void Unsubscribe(ISubscriber *subscriber) { subscribers_.erase(subscriber); }
  void NotifySubscribers() {
    std::cout << "Observer is sending news to subscribers." << std::endl;
    for (auto &subscriber : subscribers_) {
      subscriber->SendNews();
    }
  }
 private:
  std::set<ISubscriber *> subscribers_;
};

#endif //TASK_1_PATTERN_H
