#include <cmath>
#include <iomanip>
#include <iostream>

#include <sys/shm.h>

#include "common.h"

static constexpr int num_iterations{1'000'000};

bool IsPrime(uint64_t num) {
  const uint32_t sqrt{static_cast<uint32_t>(std::sqrt(num))};
  for (uint32_t i = 2; i < sqrt + 1; ++i)
    if (num % i == 0)
      return false;
  return true;
}

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

  uint64_t current_number{0};
  bool is_prime{false};
  for (int i = 0; i < num_iterations; ++i) {
    // lock the consumers semaphore
    sem_wait(&shm_ptr->consumers);
    
    // copy the number from the shared memory
    current_number = shm_ptr->data;
    
    // unlock the producer semaphore
    sem_post(&shm_ptr->producer);

    is_prime = IsPrime(current_number);

    std::cout << "Consumer " << core_id << " iteration #" << std::setw(7) << i << " number "
              << std::setw(20) << current_number << " is "
              << (is_prime ? "" : "not ") << "prime" << std::endl;
  }

  // detach from the shared memory
  shmdt(reinterpret_cast<void *>(shm_ptr));
  std::cout << "Consumer " << core_id << " has detached its shared memory...\n";
  std::cout << "Consumer " << core_id << " exits...\n";
  return 0;
}