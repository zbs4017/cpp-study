#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <string.h>
#include <time.h>

using namespace std;

static inline int64_t get_time_ns() {
  std::chrono::nanoseconds a =
      std::chrono::high_resolution_clock::now().time_since_epoch();
  return a.count();
}

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Usage：./test [01234567]" << endl;
    cout << "0 - aligned, 1-7 - nonaligned offset" << endl;
    return 0;
  }
  uint64_t offset = atoi(argv[1]);
  const uint64_t BUFFER_SIZE = 10000;
  alignas(64) uint8_t data_ptr[BUFFER_SIZE];
  memset(data_ptr, 0, sizeof(uint8_t) * BUFFER_SIZE);
  const uint64_t LOOP_CNT = 1000000;
  auto start = get_time_ns();
  for (uint64_t i = 0; i < LOOP_CNT; ++i) {
    uint32_t src = rand();
    for (uint64_t j = offset; j + 64 <= BUFFER_SIZE;
         j += 64) { // align:offset = 0 nonalign: offset=1-7
      memcpy(data_ptr + j, &src, 4);
    }
  }
  auto end = get_time_ns();
  cout << "time elapsed " << std::setprecision(2)
       << (end - start) / ((double)LOOP_CNT * BUFFER_SIZE / 64)
       << "ns per write (rand:" << (int)data_ptr[rand() % BUFFER_SIZE] << ")"
       << endl;
  return 0;
}