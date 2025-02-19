#include <cmath>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <math.h>

#include <sys/shm.h>

#include "common.h"

static constexpr int kNumIterations{1'000'000};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "usage: " << argv[0] << " <unique_core_id>\n";
    return -3;
  }

  const int core_id{std::atoi(argv[1])}; 
  SetAffinity(core_id);

  const key_t shm_key{ftok(".", 'x')};
  const int shm_id{shmget(shm_key, sizeof(Memory), 0666)};
  if (shm_id < 0) {
    std::cout << "shmget error (consumer)\n";
    return -1;
  }
  std::cout << "Consumer " << core_id << " has received a shared memory...\n";

  // attach to the existing shared memory
  Memory *shm_ptr{reinterpret_cast<Memory *>(shmat(shm_id, NULL, 0))};
  if (reinterpret_cast<intptr_t>(shm_ptr) == -1) {
    std::cout << "shmat error (consumer)\n";
    return -2;
  }
  std::cout << "Consumer " << core_id << " has attached the shared memory to it's virtual memory "
               "space...\n";

  int j{0};
  std::chrono::high_resolution_clock::time_point start;
  int64_t elapsed{-1};
  for (int i = 0; i < kNumIterations; ++i) {
    // lock the consumers semaphore
    sem_wait(&shm_ptr->consumers);

    start = std::chrono::high_resolution_clock::now();

    j = 0;
    for (const auto &pt : shm_ptr->data)
      shm_ptr->answer[j++] = sqrtf(pt.x * pt.x + pt.y * pt.y);
    
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count();

    // unlock the producer semaphore
    sem_post(&shm_ptr->producer);

    std::cout << "Consumer " << core_id << " iteration #" << std::setw(7) << i << " duration " << elapsed << "ns" << std::endl;
  }

  // detach from the shared memory
  shmdt(reinterpret_cast<void *>(shm_ptr));
  std::cout << "Consumer " << core_id << " has detached its shared memory...\n";
  std::cout << "Consumer " << core_id << " exits...\n";
  return 0;
}