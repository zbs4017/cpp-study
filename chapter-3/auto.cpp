#include <iostream>
#include <type_traits>

class A {};
template <class T> auto return_ref(T &t) -> decltype(t) { return t; }
int main() {
  //   int cc { 3.14 };
  int x1 = 0;
#define REF(x) << #x " ?: " << x << '\n'
  std::cout << std::boolalpha REF(std::is_reference_v<A>)
          REF(std::is_reference_v<A &>) REF(std::is_reference_v<A &&>)
              REF(std::is_reference_v<long>) REF(std::is_reference_v<long &>)
                  REF(std::is_reference_v<long &&>)
                      REF(std::is_reference_v<double *>)
                          REF(std::is_reference_v<double *&>)
                              REF(std::is_reference_v<double *&&>);
#undef REF
  static_assert(std::is_reference_v<decltype(return_ref(x1))>);
}