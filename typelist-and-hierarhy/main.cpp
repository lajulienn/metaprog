#include <iostream>

#include "typelist.h"
#include "linear-hierarchy.h"


// Main for hierarchy check
int main() {
  LinearHierarchy<TypeList<int, long, float, double>, Unit> linear;

  return 0;
}

/*
// Main for typelist check
int main() {
  using ints_and_floats = TypeList<int, long, float, double>;
  using one_int = TypeList<int>;
  using empty =  TypeList<>;

  std::cout << "----------Length----------" << std::endl;
  std::cout << "ints_and_floats (4): " << Length<ints_and_floats >::value << std::endl;
  std::cout << "one_int (1): " << Length<one_int >::value << std::endl;
  std::cout << "empty (0): " << Length<empty >::value << std::endl;


  std::cout << "----------Empty----------" << std::endl;
  std::cout << "ints_and_floats (0): " << Empty<ints_and_floats >::value << std::endl;
  std::cout << "one_int (0): " << Empty<one_int >::value << std::endl;
  std::cout << "empty (1): " << Empty<empty >::value << std::endl;


  std::cout << "----------GetAt----------" << std::endl;
  float some_float_to_check_on = 12.34;
  std::cout << "ints_and_floats (12, 12, 12.34, 12.34): ";

  using IntVar = GetAt<ints_and_floats, 0>::value;
  IntVar int_variable = some_float_to_check_on;
  std::cout << int_variable << ", ";

  using LongVar = GetAt<ints_and_floats, 1>::value;
  LongVar long_variable = some_float_to_check_on;
  std::cout << long_variable << ", ";

  using FloatVar = GetAt<ints_and_floats, 2>::value;
  FloatVar float_variable = some_float_to_check_on;
  std::cout << float_variable << ", ";

  using DoubleVar = GetAt<ints_and_floats, 3>::value;
  DoubleVar double_variable = some_float_to_check_on;
  std::cout << double_variable << std::endl;

  using IntVar = GetAt<one_int , 0>::value;
  IntVar int_var = some_float_to_check_on;
  std::cout << "one_int (12): " << int_var << std::endl;

  return 0;
}

*/