#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> v;
  std::string str = "example";
  v.push_back(std::move(str)); // str is now valid but unspecified
  str.back(); // undefined behavior if size() == 0: back() has a precondition
              // !empty()
  if (!str.empty()) {
    std::cout << "-------" << std::endl;
    str.back(); // OK, empty() has no precondition and back() precondition is
  }
  // met

  str.clear(); // OK, clear() has no preconditions
}