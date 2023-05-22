#define _CRT_SECURE_NO_WARNINGS
#include "tree_oper.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;

void save_tree(tree* top, FILE* f) {
	if (top) {
		fwrite(&top->inf, size_marsh, 1, f);
		if (top->left != NULL) save_tree(top->left, f);
		if (top->right != NULL) save_tree(top->right, f);
	}
}
/*Чтение с файла*/
tree* read_file(FILE* f) {
	fseek(f, 0, 0);
	rewind(f);
	tree* top = NULL;
	marsh d;
	while (!feof(f)) {
		if (fread(&d, size_marsh, 1, f) != 0) {
			top = addtree(top, d);
		}
	}
	cout << "Список скопирован";
	return top;
}
/*Создание узла*/
tree* addtree(tree* top, const marsh& newtree_st) {
	if (!top) {
		top = (tree*)malloc(sizeof(tree));
		top->inf = newtree_st;
		top->left = NULL;
		top->right = NULL;
	}
	else {
		if (top->inf.number > newtree_st.number) {
			top->left = addtree(top->left, newtree_st);
		}
		else {
			top->right = addtree(top->right, newtree_st);
		}
	}
	return top;
}
/*Структура дерева*/
void tree_output(tree* top, int otstup) {
	if (top) {
		otstup += 3;
		tree_output(top->right, otstup);
		for (int i = 0; i < otstup; i++) cout << " ";
		cout << top->inf.number << endl;
		tree_output(top->left, otstup);
	}
}
/*Ввод данных студента*/
marsh vvod_st() {
	marsh d;
	puts("Введите порядковый номер");
	scanf_s("%d", &d.id);
	puts("Введите номер маршрута");
	scanf_s("%d", &d.number);
	puts("Введите начальный пункт");
	scanf_s("%s", d.nap, (unsigned)_countof(d.nap));
	puts("Введите конечный пункт");
	scanf_s("%s", d.kop, (unsigned)_countof(d.kop));
	return d;
}

/*Создать дерево*/
tree* tree_org() {
	int answer;
	tree* top = NULL;
	while (1) {
		top = addtree(top, vvod_st());
		cout << "0. Закончить" << endl << "1. Продолжить ввод" << endl;
		scanf_s("%d", &answer);
		if (answer == 0) return top;
	}
	return top;
}
/*Просмотреть дерево*/
void prosmotr(tree* top) {
	if (top) {
		printf("| %2d | %4d | %-15s | %-15s |\n",
			top->inf.id, top->inf.number, top->inf.nap, top->inf.kop);
		prosmotr(top->left);
		prosmotr(top->right);
	}
}