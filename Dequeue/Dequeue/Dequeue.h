#pragma once
#include <cstddef>
#include <vector>
#include <iostream>
template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:

    bool Empty() const {
        if (head.empty() && tail.empty()) {
            return true;
        }
        else {
            return false;
        }
    }

    size_t Size() const {
        return head.size() + tail.size();
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator [] (size_t i) const {
        if (i > head.size()) {
            return tail[i - head.size()];
        }
        else {
            return head[head.size - i];
        }
    }

    T& operator [] (size_t i) {
        if (i > head.size()) {
            return tail[i - head.size()];
        }
        else {
            return head[head.size - i];
        }
    }
    
    const T& At(size_t i) const {
        if (i+1 <= head.size()) {
            return head[i];
        }
        else if (i + 1 - head.size() <= tail.size()) {
            return tail[i - head.size()];
        }
        else {
            throw std::out_of_range("Element dosent exist");
        }
    }// throws std::out_of_range on incorrect index
    
    T& At(size_t i) {
        
        if (i + 1 <= head.size()) {
            return head[i];
        }
        else if (i + 1 - head.size() <= tail.size()) {
            return tail[i - head.size()];
        }
        else {
            throw std::out_of_range("Element dosent exist");
        }
    }// throws std::out_of_range on incorrect index

    const T& Front() const {
        if (head.size() > 0) {
            return head[head.size() - 1];
        }
        else if (tail.size() > 0) {
            return tail[0];
        }
        else {
            throw std::out_of_range("Element dosent exist");
        }
    }

    T& Front() {
        if (head.size() > 0) {
            return head[0];
        }
        else if (tail.size() > 0) {
            return tail[0];
        }
        else {
            throw std::out_of_range("Element dosent exist");
        }
        
    }

    const T& Back() const {
        if (tail.size() > 0) {
            return tail[tail.size() - 1];
        }
        else if (head.size() > 0) {
            return head[head.size() - 1];
        }
        else {
            throw std::out_of_range("Element dosent exist");
        }
    }

    T& Back() {
        if (tail.size() > 0) {
            return tail[tail.size() - 1];
        }
        else if (head.size() > 0) {
            return head[head.size() - 1];
        }
        else {
            throw std::out_of_range("Element dosent exist");
        }
    }

    void PushFront(const T& elem) {
        std::vector<T> v {elem};
        for (T n : head) {
            v.push_back(n);
        }
        head.clear();
        head = v;
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};