typedef double TYPE_T; // #1

class A {
public:
  /**
@brief
   *
   * @return TYPE_T
   */
  // typedef int TYPE_T;
  TYPE_T f1() { return bal; } // 使用外层作用域的 TYPE_T

private:
  TYPE_T bal;
};
int a;
using cc = int;
int main() {
  a = 1;
  cc b = 1;
  using cc = double;
  cc c = 2.2;
  int a;
  a = 2;
  return 0;
}