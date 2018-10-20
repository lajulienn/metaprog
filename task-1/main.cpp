#include <iostream>

#include "pattern.h"

int main() {
    TennisCenter center = TennisCenter();
    auto tennisCenterProxy = Pattern<Proxy>(center);

    TennisPlayer player = TennisPlayer(&tennisCenterProxy);
    player.book_time();
}