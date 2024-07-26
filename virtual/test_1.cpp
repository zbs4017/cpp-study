#include <bits/stdc++.h>
using namespace std;

class A {
public:
  A() {
    cout << "A" << endl;
    func();
  }
  int c = 8;
  virtual void func() { cout << "A func" << endl; }
};

class B : public A {
public:
  B() { func(); }
  // void func() override { cout << "B func" << endl; }
};
class C : public B {
public:
  C() { func(); }
  void func() override { cout << "C func" << endl; }
};
int main() {
  //   A a{};
  atomic<int> cc = 1;
  C b{};
  return 0;
}