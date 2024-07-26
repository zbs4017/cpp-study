#include <chrono>
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
  cout << "offset = " << offset << endl;
  const uint64_t BUFFER_SIZE = 4000000;
  //   alignas(64) uint8_t *data_ptr = new uint8_t[BUFFER_SIZE];
  alignas(64) uint8_t data_ptr[BUFFER_SIZE];
  // if (data_ptr == nullptr) {
  //   cout << "apply for memory failed" << endl;
  //   return 0;
  // }
  memset(data_ptr, 0, sizeof(uint8_t) * BUFFER_SIZE);
  const uint64_t LOOP_CNT = 100000;
  cout << "start" << endl;
  auto start = get_time_ns();
  for (uint64_t i = 0; i < LOOP_CNT; ++i) {
    // for (uint64_t j = offset; j <= BUFFER_SIZE - 8;
    //      j += 64) { // align:offset = 0 nonalign: offset=1-7
    //   auto tmp = *(uint64_t *)&data_ptr[j]; // read from memory
    //   // mov rax,QWORD PTR [rbx+rdx*1] // rbx+rdx*1 = 0x7fffc76fe019
    //   // mov QWORD PTR [rsp+0x8],rax
    //   ++tmp;
    //   // mov rcx,QWORD PTR [rsp+0x8]
    //   // add rcx,0x1
    //   // mov QWORD PTR [rsp+0x8],rcx
    //   *(uint64_t *)&data_ptr[j] = tmp; // write to memory
    //                                    // mov rcx,QWORD PTR [rbx+rdx*1],rcx
    // }
    uint32_t src = rand();
    for (uint64_t j = offset; j + 64 <= BUFFER_SIZE;
         j += 64) { // align:offset = 0 nonalign: offset=1-7
      memcpy(data_ptr + j, &src, 4);
    }
  }
  auto end = get_time_ns();
  cout << "time elapse " << end - start << "ns" << endl;
  return 0;
}