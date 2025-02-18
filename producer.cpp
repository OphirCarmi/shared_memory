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

static constexpr int num_iterations{1000000};

int main(int argc, char *argv[]) {
  if (argc > 1) {
    SetAffinity(std::atoi(argv[1]));
  }
  const key_t shm_key{ftok(".", 'x')};
  const int shm_id{shmget(shm_key, sizeof(Memory), IPC_CREAT | 0666)};
  if (shm_id < 0) {
    std::cout << "shmget error (producer)\n";
    return -1;
  }

  Memory *shm_ptr{reinterpret_cast<Memory *>(shmat(shm_id, NULL, 0))};
  if (reinterpret_cast<intptr_t>(shm_ptr) == -1) {
    std::cout << "shmat error (producer) ***\n";
    return -2;
  }
  std::cout << "Producer attached the memory to its virtual space...\n";

  sem_init(&shm_ptr->producer, !0, 1);
  sem_init(&shm_ptr->consumers, !0, 0);

  shm_ptr->current_index = -1;

  for (int i = 0; i < num_iterations; ++i) {
    sem_wait(&shm_ptr->producer);
    shm_ptr->current_index = (shm_ptr->current_index + 1) % N;
    shm_ptr->data[shm_ptr->current_index] = dist(rng);
    std::cout << "Producer iteration #" << std::setw(7) << i << " array index "
              << std::setw(2) << shm_ptr->current_index << " value "
              << std::setw(20) << shm_ptr->data[shm_ptr->current_index]
              << std::endl;
    sem_post(&shm_ptr->consumers);
  }

  std::cout << "Producer has detected the completion of its child...\n";
  shmdt(reinterpret_cast<void *>(shm_ptr));
  std::cout << "Producer has detached its shared memory...\n";
  shmctl(shm_id, IPC_RMID, NULL);
  std::cout << "Producer has removed its shared memory...\n";
  std::cout << "Producer exits...\n";
  return 0;
}