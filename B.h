#ifndef B_H_
#define B_H_

#include <TFile.h>
#include <Rtypes.h>
#include <iostream>
#include <array>

class B {
 public:
  B(TRootIOCtor*) {} // Constructor for ROOT I/O
  B(int id) : id_(id) {}
  B() {}
  virtual ~B() {}
  int get_id() { return id_; }
 private:
  int id_;
  ClassDef(B, 1);
};

#endif // B_H_