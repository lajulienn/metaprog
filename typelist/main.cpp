#include <iostream>

namespace typelist {
struct Null {};
}

template <typename ... T>
struct TypeList {
  using head = typelist::Null;
  using tail = typelist::Null;
};

template <typename T, typename ... U>
struct TypeList<T, U ...> {
  using head = T;
  using tail  = TypeList<U ...>;
};

typedef TypeList<> EmptyTypeList;

// ------------------- Length ---------------------
template <typename TypeList>
struct Length {
  static constexpr int value = Length<typename TypeList::tail>::value + 1;
};

template <>
struct Length<EmptyTypeList> {
  static constexpr int value = 0;
};

// ----------------- Empty -----------------------
template <typename TypeList>
struct Empty {
  static const bool value = false;
};

template <>
struct Empty<EmptyTypeList> {
  static const bool value = true;
};

// ----------------- Get At ----------------------
template <typename TypeList, size_t index>
struct GetAt {};

template <size_t index>
struct GetAt<EmptyTypeList, index> {
  using value = typelist::Null;
};

template <typename Head, typename ... Tail>
struct GetAt<TypeList<Head, Tail ...>, 0> {
  using value = Head;
};

template <typename Head, typename ... Tail, size_t index>
struct GetAt<TypeList<Head, Tail ...>, index> {
  using value = typename GetAt<TypeList<Tail ...>, index - 1>::value;
};

// ---------------- Change At ----------------------
template <size_t index, typename NewType, typename TypeList>
struct ChangeAt {};

//template <size_t index, typename NewType>
//struct ChangeAt<index, NewType, EmptyTypeList> {
//  using value = EmptyTypeList;
//};

template <typename NewType, typename Head, typename ... Tail>
struct ChangeAt<0, NewType, TypeList<Head, Tail ...>> {
  using value = TypeList<NewType, Tail ...>;
};

template <size_t index, typename NewType, typename Head, typename ... Tail>
struct ChangeAt<index, NewType, TypeList<Head, Tail ...>> {
  using value = TypeList<Head, typename ChangeAt<index - 1, NewType, TypeList<Tail ...>>::value>;
};

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


  std::cout << "----------ChangeAt----------" << std::endl;
  using ints = TypeList<int, int, int>;
  using changed_ints = ChangeAt<1, float, ints>::value;
  using WasInt = GetAt<changed_ints , 1>::value;
  WasInt was_int = some_float_to_check_on;
  std::cout << "Old double (12):" << was_int << std::endl;

  return 0;
}