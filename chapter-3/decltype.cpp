#include <iostream>
#include <string>
#include <type_traits>
#include <utility>
class Foo {
  static const int num = 0;
  int x;
};
// void f() {
//   float x, &r = x;
//   float b;
//   const int dc = 1;
//   (x) = 3;
//   decltype(dc) dd = 1;
//   decltype((dc)) dd1 = 1;
//   decltype((x + b)) ydd2 = (x);
//   decltype(r) r1 = x;
//   decltype(1) r3 = x;
//   decltype(((1 + 2))) r4 = x;
//   decltype((r)) r2 = x;
//   [=](int a) {
//     decltype(x) y1;        // y1 has type float
//     decltype((x)) y2 = y1; // y2 has type float const& because this lambda
//                            // is not mutable and x is an lvalue
//     decltype(r) r1 = y1;   // r1 has type float&
//     decltype((r)) r2 = y2; // r2 has type float const&
//   }(4);
// }
int func_int_r();   // 返回值为整型
int &func_int_rr(); // 返回值为整型地址

int test_1() { return 1; }
std::string test_2() {
  std::string s{"dasdasdas"};
  return s;
}
int main() {
  decltype((test_1())) cdsadas = 1;
  decltype(test_2()) cdsadas22 = "wqee";
  int n = 0;
  int ndd[5]{};
  decltype(ndd[5]) dsds = n;
  decltype((n)) b = n;
  decltype(n) b1 = n;
  int &cc = (n);
  int ccc = (n);
  volatile const int &a = n;
  decltype((10.0)) z = 5;
  decltype(a) c = n;
  decltype(func_int_r()) d = 0;
  decltype(func_int_rr()) e = n;

  struct A {
    double x;
  };
  const A *cccc = new A();
  double sx = 1;
  decltype((cccc->x)) dc = sx; // decltype((a->x))推导类型为const double&
  std::string cccdsa = test_2();
  cccdsa.append("d-----------------");
  std::cout << cccdsa;
  return 0;
}