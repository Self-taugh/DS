#pragma once
#include "Node.h"

Node* lca(Node* a, Node* b) {
	Node *temporarRoot = nullptr, *aNode = a, *bNode = b, *aPast = nullptr, *bPast = nullptr;
	
	while (true)
	{
		if (aNode->parent != nullptr) { // Если есть куда подниматься - поднимаемся
			aPast = aNode;
			aNode = aPast->parent;
		}
		else { // Если некуда - закрепляемся в качестве корня или проверяем связь
			
			if (temporarRoot == nullptr) {
				temporarRoot = aNode;
			}
			else {
				if (temporarRoot == aNode) {
					// Общий корень найден
					if (aPast == bPast) { // Маленькая оптимизация
						temporarRoot = aPast;
						break;
					}
					else {
						return temporarRoot;
					}
				}
				else {
					return nullptr; // Они не связанны общим корнем и потому не имеют предка
				}
			}
		}


		if (bNode->parent != nullptr) {
			bPast = bNode;
			bNode = bPast->parent;
		}
		else {

			if (temporarRoot == nullptr) {
				temporarRoot = bNode;
			}
			else {
				if (temporarRoot == bNode) {
					// Общий корень найден
					if (aPast == bPast) { // Маленькая оптимизация
						temporarRoot = aPast;
						break;
					}
					else {
						return temporarRoot;
					}
				}
				else {
					return nullptr;
				}
			}
		}
	}

	aNode = a; bNode = b; aPast = nullptr; bPast = nullptr;
	while (true) // Проверка 'импульсами' по 3 звена сразу
	{
		if (aNode->parent != temporarRoot) {
			aPast = aNode;
			aNode = aPast->parent;
		}
		
		if (bNode->parent != temporarRoot) {
			bPast = bNode;
			bNode = bPast->parent;
		}

		if (bNode->parent == temporarRoot && aNode->parent == temporarRoot) {
			if (aNode == bNode) {
				if (aPast == bPast) {
					temporarRoot = aPast;
					aNode = a; bNode = b; aPast = nullptr; bPast = nullptr;
				}
				else {
					return aNode;
				}
			}
			else {
				return temporarRoot;
			}
		}
	}
}