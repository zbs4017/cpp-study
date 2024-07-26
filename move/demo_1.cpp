#include <iostream>
class A {
public:
  int *a = nullptr;
  A() { std::cout << "默认初始化" << std::endl; }
  A(int i) {
    a = new int;
    *a = i;
    std::cout << "有参初始化" << std::endl;
  }
  A(const A &b) {
    a = new int;
    *a = *b.a;
    std::cout << "拷贝构造" << std::endl;
  }
  A(A &&b) {
    a = b.a;
    b.a = nullptr;
    std::cout << "移动构造" << std::endl;
  }
  ~A() {
    if (a != nullptr) {
      delete a;
      a = nullptr;
    }
    std::cout << "析构" << std::endl;
  }
  A &operator=(const A &b) {
    if (this == &b) {
      return *this;
    }
    if (a != nullptr) {
      delete a;
      a = nullptr;
    }
    a = new int;
    *a = *b.a;
    std::cout << "拷贝赋值" << std::endl;
    return *this;
  }
};
int main() { return 0; }