#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void thread_func1() {
  std::this_thread::sleep_for(
      std::chrono::seconds(2)); // Hold the lock for 2 seconds
  mtx.lock();
  std::cout << "Thread 1 acquired the lock." << std::endl;
}

void thread_func2() {
//   std::this_thread::sleep_for(
//       std::chrono::seconds(1)); // Wait for thread 1 to acquire the lock
  mtx.unlock(); // Attempt to unlock the mutex (undefined behavior)
  std::cout << "Thread 2 unlocked the mutex." << std::endl;
}

int main() {
  std::thread t1(thread_func1);
  std::thread t2(thread_func2);

  t1.join();
  t2.join();

  return 0;
}