#include <atomic>
#include <bits/stdc++.h>
using namespace std;

int main() {
  atomic_int a = 1;
  int b = a.load(std::memory_order_acq_rel);
  return 0;
}