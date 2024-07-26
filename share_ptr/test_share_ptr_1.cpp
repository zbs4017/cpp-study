
#include <bits/stdc++.h>
#include <memory>
using namespace std;
class A;
class B {
public:
  shared_ptr<A> a_;
//   void fun() {
//     // a_->hello();
//     // cout << a_->ddfd;
//   }
};
int main() {
  B b{};
  b.a_->hello();
  //   cout<<b.a_.ddfd;
  //   b.fun();
  return 0;
}