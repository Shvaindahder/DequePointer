#include "Deque.hpp"

Deque::Deque(int s): size(s) {
    size = s;
    for(int i = 0; i < s; i++) {
        if(i==0) {
            firstElem = new Elem();
            firstElem->prev = nullptr;
            firstElem->next = nullptr;
        }
        else {
            if(!lastElem) {
                lastElem = new Elem();
                firstElem->next = lastElem;
                lastElem->prev = firstElem;
                lastElem->next = nullptr;
            }
            else {
                Elem* temp = new Elem();
                lastElem->next = temp;
                temp->prev = lastElem;
                temp->next = nullptr;
                lastElem = temp;
            }
        }
    }
}

void Deque::push_back(int num) {
    size += 1;
    if(!firstElem) {
        firstElem = new Elem();
        firstElem->prev = nullptr;
        firstElem->next = nullptr;
        firstElem->current = num;
    }

    else if(!lastElem) {
        lastElem = new Elem();
        lastElem->prev = firstElem;
        lastElem->next = nullptr;
        firstElem->next = lastElem;
        lastElem->current = num;
    }

    else {
        Elem* temp = new Elem();
        temp->current = num;
        lastElem->next = temp;
        temp->prev = lastElem;
        temp->next = nullptr;
        lastElem = temp;
    }
}

void Deque::push_front(int num) {
    size += 1;
    if(!firstElem) {
        firstElem = new Elem();
        firstElem->prev = nullptr;
        firstElem->next = nullptr;
        firstElem->current = num;
    }

    else if(!lastElem) {
        lastElem = new Elem();
        lastElem->prev = firstElem;
        firstElem->next = lastElem;
        lastElem->current = firstElem->current;
        firstElem->current = num;
    }

    else {
        Elem* temp = new Elem();
        temp->current = num;
        firstElem->prev = temp;
        temp->next = firstElem;
        temp->prev = nullptr;
        firstElem = temp;
    }
}

bool Deque::pop_back() {
    if (size == 0) {
        return false;
    }
    size -= 1;
    Elem* temp = lastElem->prev;
    temp->next = nullptr;
    delete lastElem;
    lastElem = temp;
    return true;
}

bool Deque::pop_front() {
    if (size == 0) {
        return false;
    }
    size -= 1;
    Elem* temp = firstElem->next;
    temp->prev = nullptr;
    delete firstElem;
    firstElem = temp;
    return true;
}

int Deque::operator[] (int pos) {
    Elem* temp = firstElem;
    while(pos>0) {
        temp = temp->next;
        pos -= 1;
    }
    return temp->current;
}

void Deque::sort() {
    bool not_sorted = true;
    while(not_sorted) {
        bool not_sorted = false;
        Elem* current_elem = firstElem;
        while(current_elem->next) {
            int current_num = current_elem->current;
            int next_num = current_elem->next->current;
            if(current_num > next_num) {
                not_sorted = true;
                current_elem->next->current = current_num;
                current_elem->current = next_num;
            }
            current_elem = current_elem->next;
        }
    }
}

void Deque::print_deque() {
    Elem* temp = firstElem;

    do {
      std::cout<<temp->current<<'\t';
      temp = temp->next;
    } while(temp);
    std::cout<<std::endl;
}

Deque::~Deque() {
    Elem* temp = lastElem->prev;
    while (temp->prev) {
        delete temp->next;
        temp->next = nullptr;
        temp = temp->prev;
    }
    delete firstElem->next;
    firstElem->next = nullptr;
    delete firstElem;
    firstElem = nullptr;
    lastElem = nullptr;
}
