#include <iostream>
#include <ostream>
#include <vector>

class MyClass {
public:
  MyClass(int value) : m_value(value) {
    std::cout << "MyClass constructor called with value: " << value
              << std::endl;
  }
  MyClass() = default;
  ~MyClass() {
    std::cout << "MyClass destructor called for value: " << m_value
              << std::endl;
  }

  MyClass(const MyClass &other) {
    m_value = other.m_value;
    std::cout << "MyClass copy constructor called for value: " << m_value
              << std::endl;
  }

  MyClass &operator=(const MyClass &other) {
    std::cout << "在这里执行析构,原来的值是" << m_value << " 现在是"
              << other.m_value << std::endl;
    m_value = other.m_value;
    std::cout << "MyClass copy assignment operator called for value: "
              << m_value << std::endl;
    return *this;
  }

private:
  int m_value = 1;
};

int main() {
  std::vector<MyClass> vec(3);

  //   // 添加初始元素
  //   vec.emplace_back(10);
  //   vec.emplace_back(20);

  //   // 重新赋值第二个元素
  vec[1] = MyClass(30);
  MyClass tmp{10};
  vec[1] = tmp;
  // 添加新元素
  //   vec.emplace_back(40);

  return 0;
}