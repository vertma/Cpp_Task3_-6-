#include <iostream>
#include "Queue.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Queue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);
    intQueue.push(15);

    std::cout << "Очередь целых чисел (int): ";
    while (!intQueue.isEmpty()) {
        std::cout << intQueue.front() << " ";
        intQueue.pop();
    }
    std::cout << std::endl;

    Queue<std::string> stringQueue;
    stringQueue.push("первый");
    stringQueue.push("второй");
    stringQueue.push("третий");

    std::cout << "Очередь строк (string): ";
    while (!stringQueue.isEmpty()) {
        std::cout << stringQueue.front() << " ";
        stringQueue.pop();
    }
    std::cout << std::endl;

    if (!intQueue.isEmpty()) {
        intQueue.pop();
    }
    else {
        std::cout << "Очередь уже пуста, удаление невозможно." << std::endl;
    }
}
