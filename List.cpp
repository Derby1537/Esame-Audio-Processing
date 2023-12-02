
#include"List.h"
#include"Question.h"

template <class T>
List<T>::List() {
    head = nullptr;
    size = 0;
}

template <class T>
List<T>::~List() {
    Node<T>* p = head;
    while(p) {
        Node<T>* tmp = p;
        p = p->next;
        delete tmp;
    }
}

template <class T>
List<T>* List<T>::push(T key) {
    Node<T>* nw = new Node<T>();
    nw->key = key;
    nw->next = head;
    head = nw;
    size++;
    return this;
}

template<class T>
List<T>* List<T>::remove(T key) {
    if(head && head->key == key) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return this;
    }
    Node<T>* p = head;
    Node<T>* prev = head;
    while(p && p->key != key) {
        prev = p;
        p = p->next;
    }
    if(p != nullptr) {
        prev->next = p->next;
        delete p;
        size--;
    }
    return this;
}

template <class T>
T List<T>::get(int i) const {
    Node<T>* p = head;
    while(i >= 0) {
        p = p->next;
        i--;
    }
    return p->key;
}

template <class T>
int List<T>::getSize() const {return size;}

template class List<Question*>;
template class List<Answer*>;
