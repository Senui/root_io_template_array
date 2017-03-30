#include "C.h"

int main(void) {
  C c;
  c.set_arrayA({{A<int>(1), A<int>(2), A<int>(3)}});
  c.set_arrayB({{B(1), B(2), B(3)}});
  c.set_vectorA({{A<int>(1), A<int>(2), A<int>(3)}});

  TFile *write = new TFile("myfile.root", "RECREATE");
  write->WriteObject(&c, "objname");
  write->Close();

  C *c_r;
  TFile *read = TFile::Open("myfile.root");
  read->GetObject("objname", c_r);
  read->Close();

  std::cout << "Expected       : 1,2,3," << std::endl;

  std::cout << "std::array<A>  : ";
  c_r->print_arrayA();
  
  std::cout << "std::array<B>  : ";
  c_r->print_arrayB();

  std::cout << "std::vector<A> : ";
  c_r->print_vectorA();

  return 0;
}