#include <iomanip>
#include <iostream>
#include <limits>
#include <random>

#include <sys/shm.h>

#include "common.h"

static std::random_device dev;
static std::mt19937_64 rng(dev());
static std::uniform_int_distribution<uint64_t>
    dist(1, std::numeric_limits<uint64_t>::max());

static constexpr int kNumIterations{1'000'000};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "usage: " << argv[0] << " <unique_core_id>\n";
    return -3;
  }

  const int core_id{std::atoi(argv[1])};
  SetAffinity(core_id);

  // create the shared memory
  const key_t shm_key{ftok(".", 'x')};
  const int shm_id{shmget(shm_key, sizeof(Memory), IPC_CREAT | 0666)};
  if (shm_id < 0) {
    std::cout << "shmget error (producer)\n";
    return -1;
  }

  // attach to the new shared memory
  Memory *shm_ptr{reinterpret_cast<Memory *>(shmat(shm_id, NULL, 0))};
  if (reinterpret_cast<intptr_t>(shm_ptr) == -1) {
    std::cout << "shmat error (producer) ***\n";
    return -2;
  }
  std::cout << "Producer " << core_id << " attached the memory to its virtual space...\n";

  // init the semaphores
  sem_init(&shm_ptr->producer, !0, 1);
  sem_init(&shm_ptr->consumers, !0, 0);

  for (int i = 0; i < kNumIterations; ++i) {
    // lock the producer semaphore
    sem_wait(&shm_ptr->producer);

    // get random number and put it in the shared memory
    shm_ptr->data = dist(rng);

    // unlock the consumers semaphore
    sem_post(&shm_ptr->consumers);

    std::cout << "Producer " << core_id << " iteration #" << std::setw(7) << i << " value  "
              << std::setw(20) << shm_ptr->data
              << std::endl;
  }

  std::cout << "Producer " << core_id << " has detected the completion of its child...\n";

  // detach from the shared memory
  shmdt(reinterpret_cast<void *>(shm_ptr));
  std::cout << "Producer " << core_id << " has detached its shared memory...\n";

  // remove the shared memory
  shmctl(shm_id, IPC_RMID, NULL);
  std::cout << "Producer " << core_id << " has removed its shared memory...\n";
  std::cout << "Producer " << core_id << " exits...\n";
  return 0;
}