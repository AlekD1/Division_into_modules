#define _CRT_SECURE_NO_WARNINGS
#include "io_tree.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>

using namespace std;

/*Просмотреть дерево*/
void pechat(tree* top, char* q) {
	if (top == NULL) printf("");
	else {
		if ((strcmp(top->inf.nap, q) == 0) || (strcmp(top->inf.kop, q) == 0)) {
			printf("| %2d | %4d | %-15s | %-15s |\n",
				top->inf.id, top->inf.number, top->inf.nap, top->inf.kop);
		}
		pechat(top->left, q);
		pechat(top->right, q);
	}
}

/*Удаление узла дерева*/
tree* tree_delete(tree* top, int s) {
	if (top == NULL) return top;
	if (top->inf.number == s) {
		tree* tmp;
		if (top->right == NULL) tmp = top->left;
		else {
			tree* ptr = top->right;
			if (ptr->left == NULL) {
				ptr->left = top->left;
				tmp = ptr;
			}
			else {
				tree* pmin = ptr->left;
				while (pmin->left != NULL) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = top->left;
				pmin->right = top->right;
				tmp = pmin;
			}
		}
		delete top;
		return tmp;
	}
	else if (top->inf.number == s) top->left = tree_delete(top->left, s);
	else top->right = tree_delete(top->right, s);
	return top;
}
/*Поиск глубины самого правого элемента*/
int most_right(tree* top, int level) {
	if (top == NULL) return -1; // если дерево пустрое
	else if (top->right == NULL) return level;
	else {
		return most_right(top->right, level + 1);
	}
}

/*Освобождение памяти*/
void free_memory(tree* top) {
	if (top) {
		if (top->left != NULL) free_memory(top->left);
		if (top->right != NULL) free_memory(top->right);
		delete top;
	}
}