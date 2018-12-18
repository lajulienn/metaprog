//
// Created by julia on 12/18/18.
//

#ifndef TYPELIST_FIBONACCI_HIERARCHY_H
#define TYPELIST_FIBONACCI_HIERARCHY_H

#include "typelist.h"
#include "linear-hierarchy.h"
#include "fibonacci-numbers.h"


template <typename TypeList, typename LinearBranch,
          unsigned branch_index, unsigned accumulated_branch_size, unsigned branch_size,
          template <typename T, typename Base> class Unit>
struct FibonacciHierarchyAuxiliary;


// Cutting input TypeList's head to get branch_size types for Linear Hierarchy branch
template <typename Head, typename ...Tail, typename ...LinearBranch,
          unsigned branch_index, unsigned accumulated_branch_size, unsigned branch_size,
          template <typename T, typename Base> class Unit>
struct FibonacciHierarchyAuxiliary<TypeList<Head, Tail...>, TypeList<LinearBranch...>,
    branch_index, accumulated_branch_size, branch_size, Unit>
    : public FibonacciHierarchyAuxiliary<TypeList<Tail...>, TypeList<Head, LinearBranch...>,
    branch_index, accumulated_branch_size + 1, branch_size, Unit> {};


// Deriving from the Linear Hierarchy branch, when it's finished. Proceed with separating next linear branch.
template <typename Head, typename ...Tail, typename ...LinearBranch,
          unsigned branch_index, unsigned branch_size,
          template <typename T, typename Base> class Unit>
struct FibonacciHierarchyAuxiliary<TypeList<Head, Tail...>, TypeList<LinearBranch...>,
    branch_index, branch_size, branch_size, Unit>
    : public LinearHierarchy<TypeList<LinearBranch...>, Unit>,
      public FibonacciHierarchyAuxiliary<TypeList<Head, Tail...>, EmptyTypeList,
      branch_index + 1, 0, FibonacciNumber<branch_index + 1>::value + 1, Unit> {};


// No more types left in TypeList, deriving only from branch we have just composed.
template <typename ...LinearBranch,
          unsigned branch_index, unsigned accumulated_branch_size, unsigned branch_size,
          template <typename T, typename Base> class Unit>
struct FibonacciHierarchyAuxiliary<EmptyTypeList, TypeList<LinearBranch...>,
    branch_index, accumulated_branch_size, branch_size, Unit>
    : public LinearHierarchy<TypeList<LinearBranch...>, Unit> {};


template <typename TypeList, template <typename T, typename Base> class Unit>
struct FibonacciHierarchy : public FibonacciHierarchyAuxiliary<TypeList, EmptyTypeList, 0, 0,
    FibonacciNumber<0>::value + 1, Unit> {};


#endif //TYPELIST_FIBONACCI_HIERARCHY_H
