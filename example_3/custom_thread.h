#ifndef CUSTOM_THREAD_
#define CUSTOM_THREAD_

#include <condition_variable>
#include <math.h>
#include <mutex>
#include <thread>

#include "common.h"

class CustomThread {
public:
  CustomThread(int affinity, Memory *shm_ptr, int start_index, int end_index)
      : affinity_(affinity), shm_ptr_(shm_ptr), start_index_(start_index),
        end_index_(end_index),
        thread_(std::thread(&CustomThread::Execute, this)) {}

  ~CustomThread() {
    thread_condition_variable_.notify_all();
    thread_.join();
  }

  std::mutex mtx1_;
  std::mutex mtx2_;
  std::condition_variable main_thread_condition_variable_;
  std::condition_variable thread_condition_variable_;

  bool flag{false};

private:
  void Execute() {
    SetAffinity(affinity_);

    for (;;) {
      {
        std::unique_lock<std::mutex> lck2(mtx2_);
        thread_condition_variable_.wait(lck2);
      }

      auto answer_it{shm_ptr_->answer.begin() + start_index_};
      auto data_it{shm_ptr_->data.begin() + start_index_};
      const auto data_end{shm_ptr_->data.begin() + end_index_};
      for (; data_it != data_end; ++data_it, ++answer_it) {
        *answer_it = sqrtf(data_it->x * data_it->x + data_it->y * data_it->y);
      }

      {
        std::lock_guard<std::mutex> lck1(mtx1_);
        
        main_thread_condition_variable_.notify_all();
      }
    }
  }

  int affinity_{0};
  int start_index_{0};
  int end_index_{0};
  Memory *shm_ptr_;
  std::thread thread_;
};

#endif // CUSTOM_THREAD_
