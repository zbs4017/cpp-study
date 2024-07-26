struct ABParent {
  int k;
  virtual void parent_virtual1() {}
  virtual void parent_virtual2() {}
  virtual void parent_virtual3() {}
};
struct A : virtual ABParent {
  int a;
  virtual void a_virtual1() {}
  virtual void a_virtual2() {}
  virtual void parent_virtual1() {}
  virtual void a_pure() = 0;
  void a_do() {};
};
struct B : virtual ABParent {
  int b;
  virtual void b_virtual1() {}
  virtual void b_virtual2() {}
  virtual void parent_virtual2() {}
  virtual void b_pure() = 0;
  void b_do() {};
};

struct ABChild : A, B {
  void a_pure() override {}
  void b_pure() override {}
  virtual void child_virtual1() {}
  virtual void child_virtual2() {}
};

int main() {
  ABChild abc;
  ABChild *dd = new ABChild();
  dd->parent_virtual3();
  return 0;
}