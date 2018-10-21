#include "tennis-classes.h"

void TennisPlayer::BookTime() {
  std::cout << "Player requested time booking." << std::endl;
  favourite_tennis_center_->BookTime();
}

void TennisPlayer::GetInfoAboutNearestCenter() {
  std::cout << "Player requested Info about nearest tennis center." << std::endl;
  tennis_center_manager_->GetInfoAboutNearestCenter();
}

void TennisPlayer::SendNews() {
  std::cout << "Player *" << name_ <<"* received news." << std::endl;
}


void TennisCenter::BookTime() {
  std::cout << "Tennis center booked time for Player." << std::endl;
}

void TennisCenter::GetInfo() {
  std::cout << "Returned Info about the Tennis Center named *" << name_ << "*." << std::endl;
}

void TennisCenter::SetNotificationSystem(IPublisher *notification_system) {
  notification_system_ = notification_system;
}

void TennisCenter::NotifySubscribers() {
  std::cout << "Tennis center notifies subscribers about some news." << std::endl;
  notification_system_->NotifySubscribers();
}

