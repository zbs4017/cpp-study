#include <bits/stdc++.h>

using namespace std;
class Base {
protected:
public:
  // Base()=default;
  Base(int val = 0) : baseData(val){};
  Base(int val = 0, int y=1) : baseData(val){};
  int baseData;
  Base(const Base &other) : baseData(other.baseData) {}
};

class Derived : public Base {
private:
public:
  int derivedData;
  Derived(int base, int derived) : Base(), derivedData(derived) {}
  Derived(const Derived *other) : derivedData(other->derivedData) {}
  // 拷贝构造函数
  Derived(const Derived &other) : derivedData(other.derivedData) {}
};
class A {
public:
  A() = default;

  int a{};
  A(const A &other);
};
class B : public A {
public:
  int b{};
  B() = default;
  B(const B &other) : b(other.b){};
  //   B(const B &other) {}
};
int main() {
  A *c = new A();
  A *dd = new B();
  B cc{};
  B vv = cc;
  Derived x{1, 1};
  Derived sw = x;
  Derived sw1 = &x;
  cout << sw.baseData;
  return 0;
}