#pragma once
// #include "class_b.cpp"
// using cc = double;
double bal;
class A {
public:
  using cc = int;
  cc tt() { return bal; }
  cc bal = 1;
};

int main() { return 0; }