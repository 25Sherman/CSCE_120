# include "linked_list.h"
# include <iostream>
# include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // add node to end of linked list
    if(_head==nullptr){ // nothing in linked list already
        _head=_tail=new MyNode(name, score);
        _size++;
    } else {
        MyNode* added=new MyNode(name, score);
        _tail->next=added;
        _tail=added;
        _tail->next=nullptr;
        _size++;
    }
}

void MyList::clear() {
    // TODO

    MyNode *cur = this->_head;
  for (size_t i = 0; i < this->_size; i++) {
    MyNode *next = cur->next;
    cur->prev = nullptr;
    delete cur;
    cur = next;
  }
  this->_size = 0;
  this->_head = this->_tail = nullptr;
  delete this;

  /*  MyNode* ptr = _head;

   for (size_t i = 0; i < _size; i++)
    {
        MyNode* next_ptr = ptr->next;
        delete ptr;
        ptr = next_ptr ;
    }
    //delete _head;
    delete _tail;

    _head = nullptr;
    _tail = nullptr;
    
   _size = 0;
    */

}

bool MyList::remove(const std::string& name) {
    // TODO
/*
    MyNode* current = _head;

    while (current != nullptr && current->name != name) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        _head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        _tail = current->prev;
    }

    delete current;
    _size--;
    */
    return false;
    
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO

    return false;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
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

MyNode::MyNode(const std::string& name, int score) : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
