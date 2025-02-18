#ifndef COMMON_
#define COMMON_

#include <array>
#include <cstdint>
#include <iostream>

#include <semaphore.h>
#include <sched.h>
#include <unistd.h>

constexpr int N{100};

struct Memory {
  sem_t producer;
  sem_t consumers;
  int current_index{0};
  std::array<uint64_t, N> data;
};

inline void SetAffinity(const int cpu_ind) {
  cpu_set_t my_set;  /* Define your cpu_set bit mask. */
  CPU_ZERO(&my_set); /* Initialize it all to 0, i.e. no CPUs selected. */
  CPU_SET(cpu_ind, &my_set); /* set the bit that represents core i. */
  if (sched_setaffinity(0, sizeof(cpu_set_t), &my_set) == -1) {
    std::cout << "sched_setaffinity failed to set cpu ind " << cpu_ind;
  }
}

#endif // COMMON_
