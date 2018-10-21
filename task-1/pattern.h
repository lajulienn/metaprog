#ifndef TASK_1_PATTERN_H
#define TASK_1_PATTERN_H

#include <iostream>
#include <vector>
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
 private:
  TennisCenter tennis_center_;
 public:
  void BookTime() override {
    std::cout << "Proxy is booking time." << std::endl;
    tennis_center_.BookTime();
  }
  void SendTournamentInvitation() override {
    std::cout << "Proxy is sending invitation." << std::endl;
    tennis_center_.SendTournamentInvitation();
  }
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
    std::uniform_int_distribution<int> distribution(0, count);
    return distribution(gen);
  }
};

#endif //TASK_1_PATTERN_H
