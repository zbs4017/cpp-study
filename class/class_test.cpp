#include <iostream>
#include <string>
/**
 * explicit 只对一个实参的构造函数有效，因为隐式转换只能发生在一个实参的情况下。
 * explicit的构造函数只能用于直接初始化，之前的拷贝初始化就无法使用了。因为拷贝初始化相当于先构造一个临时对象，然后再拷贝给左值。
 */
class A {
public:
  constexpr static int d = 1;
};

int main() {
  const int *cc = &(A::d);
  std::cout << cc << std::endl;
  return 0;
}