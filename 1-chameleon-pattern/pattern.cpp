#include "pattern.h"


void Pattern<Proxy>::BookTime() {
  std::cout << "Proxy is booking time." << std::endl;
  tennis_center_.BookTime();
}

void Pattern<Proxy>::GetInfo() {
  std::cout << "Proxy is requesting Info about the Tennis Center named" << std::endl;
  tennis_center_.GetInfo();
}


void Pattern<Mediator>::GetInfoAboutNearestCenter() {
  std::cout << "Mediator is deciding what tennis center to use." << std::endl;
  int nearest = GetNearestCenter(tennis_centers_list_.size());
  tennis_centers_list_[nearest]->GetInfo();
}

int Pattern<Mediator>::GetNearestCenter(int count) {
  std::mt19937 gen(time(0));
  std::uniform_int_distribution<int> distribution(0, count - 1);
  return distribution(gen);
}


void Pattern<Observer>::Subscribe(ISubscriber *subscriber) {
  subscribers_.insert(subscriber);
}

void Pattern<Observer>::Unsubscribe(ISubscriber *subscriber) {
  subscribers_.erase(subscriber);
}

void Pattern<Observer>::NotifySubscribers() {
  std::cout << "Observer is sending news to subscribers." << std::endl;
  for (auto &subscriber : subscribers_) {
    subscriber->SendNews();
  }
}