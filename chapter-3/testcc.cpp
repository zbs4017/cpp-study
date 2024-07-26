#include <iostream>
#include <string>
// 怎么改变const的值
int main() {
  const volatile int a = 1;
  int *c = (int *)&a;
  *c = 2;
  std::cout << a << c << std::endl;
}