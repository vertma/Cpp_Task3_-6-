#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int head;
    int tail;
    int count;

    void resize();

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    void push(const T& value);
    void pop();
    T front() const;
    bool isEmpty() const;
    int getSize() const;
};

template <typename T>
void Queue<T>::resize() {
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];

    for (int i = 0; i < count; ++i) {
        newData[i] = data[(head + i) % capacity];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    head = 0;
    tail = count;
}

template <typename T>
Queue<T>::Queue(int initialCapacity) {
    if (initialCapacity <= 0) initialCapacity = 10;
    capacity = initialCapacity;
    data = new T[capacity];
    head = 0;
    tail = 0;
    count = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
void Queue<T>::push(const T& value) {
    if (count == capacity) {
        resize();
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Ошибка: Очередь пуста!");
    }
    head = (head + 1) % capacity;
    count--;
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Ошибка: Очередь пуста!");
    }
    return data[head];
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
int Queue<T>::getSize() const {
    return count;
}

#endif