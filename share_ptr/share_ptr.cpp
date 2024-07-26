#include <atomic>
#include <iostream>
namespace my_share_ptr {
class ControlCount {
public:
  ControlCount(int i, int j) : use_counts_(i), weak_use_counts_(j){};
  void AddUseCount() { use_counts_++; }
  bool DeleteUseCount() {
    if (--use_counts_ == 0) {
      return true;
    } else {
      return false;
    }
  }
  int getWeakUseCounts() { return weak_use_counts_; }
  int getUseCounts() { return use_counts_; }

private:
  std::atomic<int> use_counts_;
  std::atomic<int> weak_use_counts_;
};

template <typename T> class my_share_ptr {
public:
  explicit my_share_ptr(T *ptr = nullptr) : ptr_(ptr) {
    if (ptr == nullptr) {
      ctl_ = nullptr;
    } else {
      ctl_ = new ControlCount{1, 0};
    }
  };

  my_share_ptr<T>(const my_share_ptr<T> &other)
      : ptr_(other.ptr_), ctl_(other.ctl_) {
    if (ptr_ != nullptr) {
      ctl_->AddUseCount();
    }
  };

  my_share_ptr<T> &operator=(const my_share_ptr<T> &other) {
    if (&other != this) {
      release();
      ptr_ = other.ptr_;
      ctl_ = other.ctl_;
    }
  }
  T *operator->() { return ptr_; }
  T *get() const { return ptr_; }
  T &operator*() { return *ptr_; }
  int getUseCount() { return ctl_ != nullptr ? ctl_->getUseCounts() : 0; }
  ~my_share_ptr<T>() { release(); }

private:
  T *ptr_;
  ControlCount *ctl_;
  void release() {
    if (ptr_ && ctl_->DeleteUseCount()) {
      delete ptr_;
      ptr_ = nullptr;
      if (ctl_->getWeakUseCounts() == 0) {
        delete ctl_;
      }
    }
  }
};

template <typename T>
class my_weak_ptr{
    public:
    my_weak_ptr<T>(const my_weak_ptr<T>& other){
        
    }
};
} // namespace my_share_ptr