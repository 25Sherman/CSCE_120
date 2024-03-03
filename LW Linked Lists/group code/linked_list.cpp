#include "linked_list.h"
#include <iostream>
#include <string>

using namespace std;

void MyList::add(const std::string &name, int score) {
  MyNode *insNode = new MyNode(name, score);
  if (this->_head == nullptr) {
    this->_head = this->_tail = insNode;
  } else {
    insNode->next = nullptr;
    _tail->next = insNode;
    insNode->prev = this->_tail;
    _tail = insNode;
  }
  this->_size++;
}

void MyList::clear() {
  MyNode *cur = this->_head;
  while (cur != nullptr) {
    MyNode *temp = cur->next;
    delete cur;
    cur = temp;
  }
  this->_size = 0;
  this->_head = nullptr;
  this->_tail = nullptr;
}

bool MyList::remove(const std::string &name) {
  // MyNode *cur = this->_head;
  // MyNode *pre = this->_head;
  // for (size_t i = 0; i < this->_size; i++) {
  //   if (cur->name == name) {
  //     MyNode *delMe = cur;
  //     pre->next = cur->next;
  //     delete delMe;
  //     this->_size--;
  //     return true;

  //   } else {
  //     pre = cur;
  //     cur = cur->next;
  //   }
  // }

  return false;
}

bool MyList::insert(const std::string &name, int score, size_t index) {

  // MyNode *insNode = new MyNode(name, score);
  // if (this->_head == nullptr) {
  // }
  // MyNode *cur = this->_head;
  // for (int i = 0; i < index; i++) {
  // }

  return false;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() { clear(); }

size_t MyList::size() const { return _size; }

bool MyList::empty() const { return _head == nullptr; }

MyNode *MyList::head() const { return _head; }

ostream &operator<<(ostream &os, const MyList &myList) {
  MyNode *_current = myList.head();
  if (_current == nullptr) {
    os << "<empty>" << endl;
    return os;
  }

  os << "[ " << _current->name << ", " << _current->score << " ]";
  _current = _current->next;
  while (_current != nullptr) {
    os << " --> [ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
  }

  return os;
}

MyNode::MyNode(const std::string &name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
