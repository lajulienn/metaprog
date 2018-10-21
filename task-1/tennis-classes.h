#ifndef TASK_1_TENNIS_CLASSES_H
#define TASK_1_TENNIS_CLASSES_H

#include <iostream>
#include <string>

class ITennisCenter {
 public:
  virtual void BookTime() = 0;
  virtual void SendTournamentInvitation() = 0;
  virtual void GetInfo() = 0;
};

class ITennisCentersManager {
 public:
  virtual void GetInfoAboutNearestCenter() = 0;

};

// class A
class TennisPlayer {
 public:
  TennisPlayer(ITennisCenter *tennis_center) : favourite_tennis_center_(tennis_center) {}
  TennisPlayer(ITennisCentersManager *tennis_center_manager) : tennis_center_manager_(tennis_center_manager) {}

  void BookTime() {
    std::cout << "Player requested time booking." << std::endl;
    favourite_tennis_center_->BookTime();
  }

  void GetInfoAboutNearestCenter() {
    std::cout << "Player requested info about nearest tennis center." << std::endl;
    tennis_center_manager_->GetInfoAboutNearestCenter();
  }

 private:
  ITennisCenter *favourite_tennis_center_;
  ITennisCentersManager *tennis_center_manager_;
};

// class B
class TennisCenter : public ITennisCenter {
 public:
  TennisCenter(std::string name) : name_(name) {}

  void BookTime() override {
    std::cout << "Tennis center booked time for Player." << std::endl;
  }

  void SendTournamentInvitation() override {
    std::cout << "Tennis center sent a tournament invitation." << std::endl;
  }

  void GetInfo() override {
    std::cout << "Returned info about the Tennis Center named *" << name_ << "*." << std::endl;
  }
 private:
  std::string name_;
};

#endif //TASK_1_TENNIS_CLASSES_H
