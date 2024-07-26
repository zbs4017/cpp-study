/**
 * 为什么要尽量使用常量引用作为函数的形参
 *
 */
#include <iostream>
class Base {
public:
  int a = 0;
};

class Drive : public Base {
public:
  int b = 0;
};

void test(Base &b) {
  b.a = 1;
  std::cout << b.a << std::endl;
}

int main() {
  //   auto a = new Drive();
  Drive c{};
  c.a = 1;
  c.b = 1;
  test(c);
  return 0;
}