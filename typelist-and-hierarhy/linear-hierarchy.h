//
// Created by julia on 12/18/18.
//

#ifndef TYPELIST_LINEAR_HIERARCHY_H
#define TYPELIST_LINEAR_HIERARCHY_H

#include "typelist.h"

template <typename T, class Base>
struct Unit : public Base {
  T* value;
};

template <typename TypeList, template <typename T, typename Base> class Unit>
struct LinearHierarchy;

template <typename Head, typename ...Tail, template <typename T, typename Base> class Unit>
struct LinearHierarchy<TypeList<Head, Tail...>, Unit> : public Unit<Head, LinearHierarchy<TypeList<Tail...>, Unit>> {};

template <template <typename T, typename Base> class Unit>
struct LinearHierarchy<EmptyTypeList, Unit> : public Unit<typelist::Null, typelist::Null> {};

#endif //TYPELIST_LINEAR_HIERARCHY_H
