#include <iostream>

namespace typelist {
struct Null {};
}

template <typename T=typelist::Null, typename ... U>
struct TypeList {
  using head = T;
  using tail  = TypeList<U ...>;
};

template <typename T>
struct TypeList<T> {
  using head = T;
  using tail = typelist::Null;
};

typedef TypeList<typelist::Null> EmptyTypeList;

// ------------------- Length ---------------------
template <typename TypeList>
struct Length {
  static constexpr int value = Length<typename TypeList::tail>::value + 1;
};

template <>
struct Length<EmptyTypeList> {
  static constexpr int value = 0;
};

template <>
struct Length<typelist::Null> {
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

template <>
struct Empty<typelist::Null> {
  static const bool value = true;
};

int main() {
  typedef TypeList<float, double, long> float_types;
  typedef TypeList<> empty;
  typedef EmptyTypeList empty2;

  typedef float_types type_to_test;

  std::cout << "Length: " << Length<type_to_test>::value << std::endl;
  std::cout << "Empty: " << Empty<type_to_test>::value << std::endl;
  return 0;
}