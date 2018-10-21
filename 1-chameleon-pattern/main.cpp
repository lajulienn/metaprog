#include <iostream>

#include "pattern.h"

int main() {
  std::cout << "------------  Proxy  ------------------" << std::endl;

  TennisCenter tennis_center = TennisCenter(std::string("TC"));
  auto tennisCenterProxy = Pattern<Proxy>(tennis_center);

  TennisPlayer player = TennisPlayer(std::string("player"), &tennisCenterProxy);
  player.BookTime();


  std::cout << std::endl << "------------  Mediator  ---------------" << std::endl;

  std::vector<ITennisCenter *> tennis_centers_list;
  for (int i = 0; i < 7; ++i) {
    auto center = new TennisCenter(std::to_string(i));
    tennis_centers_list.push_back(center);
  }

  auto tennis_centers_manager = Pattern<Mediator>(tennis_centers_list);

  TennisPlayer another_player = TennisPlayer(std::string("another_player"), &tennis_centers_manager);
  another_player.GetInfoAboutNearestCenter();

  for (auto &center : tennis_centers_list) {
    delete center;
  }


  std::cout << std::endl << "------------  Observer  ---------------" << std::endl;
  auto publisher = Pattern<Observer>();
  tennis_center.SetNotificationSystem(&publisher);

  auto subcribers_list = std::vector<TennisPlayer *>();
  for (int i = 0; i < 7; ++i) {
    auto some_player = new TennisPlayer(std::to_string(i), &tennis_center);
    subcribers_list.push_back(some_player);
    publisher.Subscribe(some_player);
  }
  tennis_center.NotifySubscribers();

  for (auto &subscriber : subcribers_list) {
    delete subscriber;
  }

  std::cout << std::endl << "------------  Other type  ---------------" << std::endl;
  auto other = Pattern<int>();
  std::cout << other.Info() << std::endl;
}