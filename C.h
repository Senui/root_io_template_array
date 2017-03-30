#ifndef C_H_
#define C_H_

#include "A.h"
#include "B.h"

class C {
 public:
  C(TRootIOCtor*) : // needs to be initialized
        arrayA_({{A<int>(0), A<int>(0), A<int>(0)}}),
        arrayB_({{B(0), B(0), B(0)}})
        {} // Constructor for ROOT I/O
  C() : // needs to be initialized
        arrayA_({{A<int>(0), A<int>(0), A<int>(0)}}),
        arrayB_({{B(0), B(0), B(0)}})
        {}
  virtual ~C() {}

  void set_arrayA(std::array<A<int>, 3> foo) { arrayA_ = foo; }

  void set_arrayB(std::array<B, 3> foo) { arrayB_ = foo; }

  void set_vectorA(std::vector<A<int> > foo) { vectorA_ = foo; }

  void print_arrayA() {
    for (unsigned int i = 0; i < arrayA_.size(); i++)
      std::cout << arrayA_[i].get_id() << ",";
    std::cout << std::endl;
  }

  void print_arrayB() {
    for (unsigned int i = 0; i < arrayB_.size(); i++)
      std::cout << arrayB_[i].get_id() << ",";
    std::cout << std::endl;
  }

  void print_vectorA() {
    for (unsigned int i = 0; i < vectorA_.size(); i++)
      std::cout << vectorA_[i].get_id() << ",";
    std::cout << std::endl;
  }  

 private:
  std::array<A<int>, 3> arrayA_;
  std::array<B, 3> arrayB_;
  std::vector<A<int>> vectorA_;
  ClassDef(C, 1);
};

#endif // C_H_