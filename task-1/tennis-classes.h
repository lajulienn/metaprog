#ifndef TASK_1_TENNIS_CLASSES_H
#define TASK_1_TENNIS_CLASSES_H

#include <iostream>
#include <string>

class ITennisCenter {
 public:
  virtual void BookTime() = 0;
  virtual void GetInfo() = 0;
};

class ITennisCentersManager {
 public:
  virtual void GetInfoAboutNearestCenter() = 0;

};

class ISubscriber {
 public:
  virtual void SendNews() = 0;
};

class IPublisher {
 public:
  virtual void Subscribe(ISubscriber *subscriber) = 0;
  virtual void Unsubscribe(ISubscriber *subscriber) = 0;
  virtual void NotifySubscribers() = 0;
};

// class A
class TennisPlayer : public ISubscriber {
 public:
  TennisPlayer(std::string name, ITennisCenter *tennis_center)
    : name_(name),
      favourite_tennis_center_(tennis_center) {}

  TennisPlayer(std::string name, ITennisCentersManager *tennis_center_manager)
    : name_(name),
      tennis_center_manager_(tennis_center_manager) {}

  void BookTime() {
    std::cout << "Player requested time booking." << std::endl;
    favourite_tennis_center_->BookTime();
  }

  void GetInfoAboutNearestCenter() {
    std::cout << "Player requested Info about nearest tennis center." << std::endl;
    tennis_center_manager_->GetInfoAboutNearestCenter();
  }

  void SendNews() override {
    std::cout << "Player *" << name_ <<"* received news." << std::endl;
  }

 private:
  ITennisCenter *favourite_tennis_center_;
  ITennisCentersManager *tennis_center_manager_;
  std::string name_;
};

// class B
class TennisCenter : public ITennisCenter {
 public:
  TennisCenter(std::string name) : name_(name) {}

  void BookTime() override {
    std::cout << "Tennis center booked time for Player." << std::endl;
  }

  void GetInfo() override {
    std::cout << "Returned Info about the Tennis Center named *" << name_ << "*." << std::endl;
  }

  void SetNotificationSystem(IPublisher *notification_system) {
    notification_system_ = notification_system;
  }

  void NotifySubscribers() {
    std::cout << "Tennis center notifies subscribers about some news." << std::endl;
    notification_system_->NotifySubscribers();
  }
 private:
  std::string name_;
  IPublisher *notification_system_;
};

#endif //TASK_1_TENNIS_CLASSES_H
