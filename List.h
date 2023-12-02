
#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <class T>
class List {
    private:
        Node<T>* head;
        int size;

    public:
        List();
        ~List();
        List<T>* push(T);
        List<T>* remove(T);
        int getSize() const;
        T get(int) const;
};

#endif
