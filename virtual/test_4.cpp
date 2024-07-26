#include <bits/stdc++.h>
using namespace std;
class A {
public:
  int a = 1;

  virtual void funa() { cout << "A funa" << endl; }
  virtual void funa2() { cout << "A funa1" << endl; }
  virtual ~A() { cout << "A die" << endl; }
};
class B {
public:
  int b;
  virtual void funb() { cout << "B funb" << endl; }
  virtual void funb2() { cout << "B funb2" << endl; }
  void funb3() { cout << "B funb3" << endl; }
  virtual void funb4() { cout << "B funb2" << endl; }
  virtual ~B() { cout << "B die" << endl; }
};
class C : public A, public B {
public:
  int c;
  ~C() { cout << "C die" << endl; }
  void funa() override { cout << "C funa" << endl; }
  void funb() override { cout << "C funb" << endl; }
};
int main() {

  C *a = new C();
  B *b = new C();
  b->funb2();
  b->funb();
  b->funb3();
  cout << a << endl;
  cout << &a->a << endl;
  cout << &a->b << endl;
  cout << &a->c << endl;
  A *cc = a;
  B *dd = a;
  cout << cc << endl;
  cout << dd << endl;
  C *ee = dynamic_cast<C *>(dd);

  a->funb();
  a->funa2();
  a->funb2();
  a->funb3();
  a->funa();
  delete a;
  delete b;
  return 0;
}