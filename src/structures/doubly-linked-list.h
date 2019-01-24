#pragma once

#include <iostream>

template <typename Key>
struct DoublyLinkedListNode {
    Key key;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;

    DoublyLinkedListNode() = default;

    static DoublyLinkedListNode* createNil() {
        auto nil = new DoublyLinkedListNode();
        nil->prev = nil;
        nil->next = nil;
        return nil;
    }

    explicit DoublyLinkedListNode(Key key) : key(key) {}
};

template <typename Key>
class DoublyLinkedList {
    using Node=DoublyLinkedListNode<Key>;

private:
    Node* nil;
    int size;

public:
    DoublyLinkedList() {
        nil = DoublyLinkedListNode<Key>::createNil();
        size = 0;
    }

    int getSize() const {
        return size;
    }

    void pushFront(Key key) {
        Node* front = new Node(key);
        front->next = nil->next;
        front->prev = nil;
        front->next->prev = front;
        nil->next = front;
        size++;
    }

    Key popFront() {
        assert(size > 0 && "DoublyLinkedList::popFront(): empty");
        Node* front = nil->next;
        Key key = front->key;
        nil->next = front->next;
        front->prev = nil;
        delete front;
        size--;
        return key;
    }

    void pushBack(Key key) {
        Node* back = new Node(key);
        back->prev = nil->prev;
        back->next = nil;
        back->prev->next = back;
        nil->prev = back;
        size++;
    }

    Key popBack() {
        assert(size > 0 && "DoublyLinkedList::popBack(): empty");
        Node* back = nil->prev;
        Key key = back->key;
        nil->prev = back->prev;
        back->prev->next = nil;
        delete back;
        size--;
        return key;
    }

    Key getFront() const {
        return nil->next->key;
    }

    Key getBack() const {
        return nil->prev->key;
    }

    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& doubly_linked_list) {
        os << "DoublyLinkedList[ ";
        os << "size = " << doubly_linked_list.size << ", ";
        os << "keys = [ ";
        Node* curr = doubly_linked_list.nil->next;
        while (curr != doubly_linked_list.nil) {
            os << curr->key << ' ';
            curr = curr->next;
        }
        os << "]";
        return os;
    }

    ~DoublyLinkedList() {
        Node* curr = nil->next;
        while (curr != nil) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        delete curr;
    }
};