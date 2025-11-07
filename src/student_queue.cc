#include "student_queue.hpp"

void StudentQueue::Enqueue(const Student& student) {  
  Node* prev = nullptr;
  Node* cur = head_;

  while (cur != nullptr && !(cur->student_ < student)) {
    prev = cur;
    cur = cur->next_;
  }

  Node* n = new Node(student);
  n->next_ = cur;

  if (prev == nullptr) head_ = n;
  else prev->next_ = n;

  if (cur == nullptr) tail_ = n;
}

void StudentQueue::Dequeue() {
  if (head_ == nullptr) {
    return;
  }
  Node* to_delete = head_;
  head_ = head_->next_;
  delete to_delete;
  if (head_ == nullptr) {
    tail_ = nullptr;
  }
}
StudentQueue::StudentQueue(const StudentQueue& other) {
  if (other.head_ == nullptr) return;

  head_ = new Node(other.head_->student_);

  Node* cur_other = other.head_->next_; 
  Node* cur_copy = head_;
  
  while (cur_other != nullptr) {
    cur_copy->next_ = new Node(cur_other->student_);
    cur_copy = cur_copy->next_;
    cur_other = cur_other->next_;
  }

  tail_ = cur_copy;
}
StudentQueue& StudentQueue::operator=(const StudentQueue& other) {
  // TODO
  return *this;
}
StudentQueue::~StudentQueue() { Clear(); }

void StudentQueue::Clear() {
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next_;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
  tail_ = nullptr;
}
Student StudentQueue::Front() const {
  if (head_ == nullptr) {
    throw std::runtime_error("Queue is empty");
  }
  return head_->student_;
}
void StudentQueue::Display() const {
  Node* current = head_;
  while (current != nullptr) {
    std::cout << "--------------------------------\n";
    std::cout << "Name: " << current->student_.GetName() << '\n';
    std::cout << "GPA: " << current->student_.GetGPA() << '\n';
    std::cout << "Attendance Percentage: "
              << current->student_.GetAttendancePercentage() << '\n';
    std::cout << "--------------------------------\n";
    std::cout << "                |                \n";
    std::cout << "                |                \n";
    std::cout << "                |                \n";
    std::cout << "                V                \n";
    current = current->next_;
  }
  std::cout << "--------------------------------\n";
  std::cout << "|            nullptr           |\n";
  std::cout << "--------------------------------\n";
}
