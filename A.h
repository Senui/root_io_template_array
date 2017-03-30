#ifndef A_H_
#define A_H_

#include <TFile.h>
#include <Rtypes.h>
#include <iostream>
#include <array>
#include <vector>

template <typename T>
class A {
 public:
  A(TRootIOCtor*) {} // Constructor for ROOT I/O
  A(T id) : id_(id) {}
  A() {}
  virtual ~A() {}
  T get_id() { return id_; }
 private:
  T id_;
  ClassDef(A, 1);
};

#endif // A_H_