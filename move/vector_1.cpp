
#include <algorithm>
#include <string>
#include <vector>
int main() {
  std::vector<std::string> cc;
  cc.push_back(std::string{"dsadsa"});
  cc.push_back(std::move(std::string{"dsadsa"}));
  cc.push_back("dsadsa");
  cc.emplace_back("dsadsa");
  return 0;
}