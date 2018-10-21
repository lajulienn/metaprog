#include <iostream>

#include "pattern.h"

int main() {
  /**
   * Please, uncomment appropriate block to test functionality
   */

  /** ---------  Proxy  ------------------
  TennisCenter center = TennisCenter();
  auto tennisCenterProxy = Pattern<Proxy>(center);

  TennisPlayer player = TennisPlayer(&tennisCenterProxy);
  player.BookTime();
  */

  std::vector<ITennisCenter *> tennis_centers_list;
  for(int i = 0; i < 7; ++i) {
    auto center = TennisCenter(std::to_string(i));
    tennis_centers_list.push_back(&center);
  }

  auto tennis_centers_manager = Pattern<Mediator>(tennis_centers_list);

  TennisPlayer player = TennisPlayer(&tennis_centers_manager);
  player.GetInfoAboutNearestCenter();
}