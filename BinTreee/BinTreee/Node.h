#pragma once
#define _CRT_RAND_S
#include <stdlib.h>
#include <iostream>
struct Node {
    Node* parent;
    Node* left;
    Node* right;
    unsigned int number; // Для проверки работы пришлось немного (много) пошаманить с постройкой древа
    Node() {
        parent = nullptr; left = nullptr; right = nullptr; number = 0;
    }
    Node(Node* par) {
        parent = par; left = nullptr; right = nullptr;
        unsigned int x;
        rand_s(&x);
        x = x % unsigned int{ 10 };
        number = par->number * 10 + x;
    }
};