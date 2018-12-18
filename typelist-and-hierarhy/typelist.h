//
// Created by julia on 12/18/18.
//

#ifndef TYPELIST_H
#define TYPELIST_H

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


#endif //TYPELIST_H
