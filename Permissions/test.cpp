#include <bits/stdc++.h>
using namespace std;

class A {
private:
  int a{};

protected:
  int b{};

public:
  int c{};
};

class B : public A {
  int a1{};
  void fun() {
    b = 1;
    // a = 1;
  }
};
class C : protected A {
  void func() {
    a = 1;
    b = 1;
    c = 1;
  }
} ;class D : private C {
  void func() {
    a = 1;
    b = 1;
    c=1;
  }
}

int main() {
  A tmp{};
  tmp.a;
  tmp.b;
  B tn{};
  tmp.a;
  tmp.b;
  tn.b;
  tn.a;
  tn.c;
  C f{};
  f.a;
  f.b;
  f.c;
}