#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

mutex mtx;
void f() { 
    sleep(1);
    mtx.lock(); }
int main() {
  thread t(f);

  mtx.unlock();
  t.join();
  return 0;
}
