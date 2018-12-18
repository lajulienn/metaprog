//
// Created by julia on 12/18/18.
//

#ifndef TYPELIST_FIBONACCI_NUMBERS_H
#define TYPELIST_FIBONACCI_NUMBERS_H

template  <unsigned index>
struct FibonacciNumber {
  static const unsigned value = FibonacciNumber<index - 1>::value + FibonacciNumber<index - 2>::value;
};

template <>
struct FibonacciNumber<0> {
  static const unsigned value = 1;
};

template <>
struct FibonacciNumber<1> {
  static const unsigned value = 1;
};

#endif //TYPELIST_FIBONACCI_NUMBERS_H
