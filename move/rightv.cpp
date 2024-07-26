#include <iostream>
#include <utility>
using namespace std;

// void f(int x) { cout << "重载1" << endl; }
/**
 * @brief
 *
 * @param x
 */
void f(int &&x) { cout << "重载2" << endl; }
void f(int &x) { cout << "重载3" << endl; }
/***
 * jfdksj
 * jsdkf
 * @pa
 */
int main() {
  //   int &&ri = 5; // 5是右值，ri是右值引用，ri是左值
  int a = 1;
  //   f(a);
  f(std::move(a));
  //   f(ri); // ri是左值，只可以被int绑定，无法被int&&绑定，选择重载1
  // f(std::move(ri));  //
  // 编译失败，std::move(ri)是右值，既可以被int绑定也可以被int&&绑定
  return 0;
}