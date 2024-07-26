#include <iostream>
#include <string>

// 处理 lvalue 引用
template <typename T> void process(T &s) {
  std::cout << "Lvalue processed: " << s << std::endl;
}

// 处理 rvalue 引用
template <typename T> void process(T &&s) {
  std::cout << "Rvalue processed: " << s << std::endl;
}

// 转发函数，没有使用完美转发
template <typename T> void forwarder(T &&arg) {
  process(arg); // 不使用 std::forward
}
void tt(const int &a) {
  // a=1;
}
void tt(int &a) { a = 1; }
int main() {
  std::string lv = "lvalue";
  forwarder(lv);       // 应该处理 lvalue
  forwarder("rvalue"); // 应该处理 rvalue，但没有使用完美转发
}
