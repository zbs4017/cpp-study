#include <iostream>

class A {
protected:
  int a;

public:
  A(int val) : a(val) {}
  void printA() { std::cout << "A: " << a << std::endl; }
};

class B {
protected:
  int b;

public:
  B(int val) : b(val) {}
  void printB() { std::cout << "B: " << b << std::endl; }
};

class C : virtual public A, virtual public B {
protected:
  int c;

public:
  C(int val1, int val2, int val3) : A(val1), B(val2), c(val3) {}
  void printC() { std::cout << "C: " << c << std::endl; }
};

int main() {
  C obj(1, 2, 3);
  obj.printA(); // 输出 A: 1
  obj.printB(); // 输出 B: 2
  obj.printC(); // 输出 C: 3
  return 0;
}