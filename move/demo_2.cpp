#include <algorithm>
#include <iostream>
#include <string>
/**
@brief 
 * 
 * @param s 
 */
void func(std::string &&s) { // 接受右值引用 (可以是纯右值或将亡值)
  // 实现针对右值的逻辑

  std::string a{s};
  std::cout << a << std::endl;
  std::cout << s << std::endl;
}

void func(const std::string &s) { // 接受左值
  // 实现针对左值的逻辑
  std::cout << "..............." << std::endl;
}

int main() {
  std::string s{"ddd"};
  // func(s);
  // func(std::string{"dfsdf"});
  // func(std::move(s));
  // std::string &&cc = std::move(s);
  // func(cc);
  // std::cout << s << std::endl;
  std::string &&cc = std::move(s);
  // std::string &&ccs = cc;
  std::string dsa = std::move(s);
  std::string c = cc;
}