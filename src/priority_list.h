#include <functional>
#include <vector>

template <typename T, typename Cmp = std::less<T>> class PriorityList {
public:
  using value_type = T;
  using value_cmp = Cmp;
  static constexpr int _init_size = 16;

public:
  PriorityList() : size_(0) {}

  void insert(T k) {
    if (size_ == data_.size()) {
      data_.push_back(k);
      size_++;
    } else {
      data_[size_] = k;
      size_++;
    }
    if (size_ == 1) {
      return;
    }
    heap_insert(size_ - 1);
  }

  const T &top() { return data_[0]; }

  void pop() {
    if (!size_) {
      return;
    }
    data_[0] = data_[size_ - 1];
    size_--;
    heap_ify(0);
  }
  unsigned size() { return size_; }

private:
  void heap_insert(unsigned index) {
    unsigned father = get_father_index(index);
    if (!check_index_valid(father)) {
      return;
    }
    if (compare(data_[index], data_[father])) {
      swap(index, father);
    }
    heap_insert(father);
  }
  void heap_ify(unsigned index) {
    unsigned tmp = index;
    unsigned left_chd = get_left_child_index(index);
    if (check_index_valid(left_chd)) {
      tmp = compare(data_[left_chd], data_[tmp]) ? left_chd : tmp;
    }
    unsigned right_chd = get_right_child_index(index);
    if (check_index_valid(right_chd)) {
      tmp = compare(data_[right_chd], data_[tmp]) ? right_chd : tmp;
    }
    if (tmp != index) {
      swap(tmp, index);
      heap_ify(tmp);
    }
  }
  unsigned get_father_index(unsigned index) { return (index - 1) >> 1; }
  unsigned get_left_child_index(unsigned index) { return (index << 1) + 1; }
  unsigned get_right_child_index(unsigned index) { return (index << 1) + 2; }
  bool check_index_valid(unsigned index) { return index >= 0 && index < size_; }
  bool compare(const T &a, const T &b, Cmp cmp = Cmp()) { return !cmp(a, b); }
  void swap(unsigned id1, unsigned id2) {
    T tmp = data_[id1];
    data_[id1] = data_[id2];
    data_[id2] = tmp;
  }

private:
  std::vector<T> data_;
  unsigned size_;
};
