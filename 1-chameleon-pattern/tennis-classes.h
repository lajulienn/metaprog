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

/**
 * Class A
 */
class TennisPlayer : public ISubscriber {
 public:
  TennisPlayer(std::string name, ITennisCenter *tennis_center)
    : name_(name),
      favourite_tennis_center_(tennis_center) {}

  TennisPlayer(std::string name, ITennisCentersManager *tennis_center_manager)
    : name_(name),
      tennis_center_manager_(tennis_center_manager) {}

  void BookTime();
  void GetInfoAboutNearestCenter();
  void SendNews() override;

 private:
  ITennisCenter *favourite_tennis_center_;
  ITennisCentersManager *tennis_center_manager_;
  std::string name_;
};

/**
 * Class B
 */
class TennisCenter : public ITennisCenter {
 public:
  TennisCenter(std::string name) : name_(name) {}

  void BookTime() override;
  void GetInfo() override;
  void SetNotificationSystem(IPublisher *notification_system);
  void NotifySubscribers();

 private:
  std::string name_;
  IPublisher *notification_system_;
};

#endif //TASK_1_TENNIS_CLASSES_H
