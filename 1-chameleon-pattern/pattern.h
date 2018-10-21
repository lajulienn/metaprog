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
  std::string Info() { return std::string("Unsupported template type."); }
};

template <>
class Pattern<Proxy> : public ITennisCenter {
 public:
  Pattern(TennisCenter &tennis_center) : tennis_center_(tennis_center) {}

  void BookTime() override;
  void GetInfo() override;

 private:
  TennisCenter tennis_center_;
};

template <>
class Pattern<Mediator> : public ITennisCentersManager {
 public:
  Pattern(std::vector<ITennisCenter *> tennis_centers_list) : tennis_centers_list_(tennis_centers_list) {}

  void GetInfoAboutNearestCenter() override;

 private:
  std::vector<ITennisCenter *> tennis_centers_list_;

  int GetNearestCenter(int count);
};

template <>
class Pattern<Observer> : public IPublisher {
 public:
  Pattern() : subscribers_(std::set<ISubscriber *>()) {}
  void Subscribe(ISubscriber *subscriber);
  void Unsubscribe(ISubscriber *subscriber);
  void NotifySubscribers();
 private:
  std::set<ISubscriber *> subscribers_;
};

#endif //TASK_1_PATTERN_H
