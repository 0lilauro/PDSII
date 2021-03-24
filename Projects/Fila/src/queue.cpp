#include "queue.h"

struct Node {
  int key;
  Node* next;
};

Queue::Queue() {
  this->front_ = nullptr;
  this->back_ = nullptr;
}

void Queue::push(int k) {
  Node* new_node = new Node;

  new_node->key = k;
  new_node->next = nullptr;
  
  if(this->front_ == nullptr) {
    this->front_ = new_node;
    this->back_ = this->front_;
  } else {
    this->back_->next = new_node;
    this->back_ = new_node;
  }
}

void Queue::pop() {
  if(this->front_ == nullptr) {
    Queue::EmptyException expt;
    throw expt;
  } 
  this->front_ = this->front_->next;
}

int Queue::front() const {
  if(this->front_ == nullptr) {
    Queue::EmptyException expt;
    throw expt;
  } 
  int const response = this->front_->key;
  return response;
}

int Queue::back() const {
 if(this->back_ == nullptr) {
    Queue::EmptyException expt;
    throw expt;
  } 
  int const response = this->back_->key;
  return response;
}

int Queue::count() const {
  Node* running_node = this->front_;
  int counter = 0;
  while(running_node != nullptr) {
    counter++;
    running_node = running_node->next;
  }
  return counter;
}