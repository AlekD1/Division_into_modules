#define _CRT_SECURE_NO_WARNINGS
#include "io_tree.h"
#include "tree_oper.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;

void work() {
	int c;
	int s;
	char q[10];
	tree* top = NULL;
	FILE* f = fopen("data.dat", "rb+");
	if (f == NULL) {
		f = fopen("data.dat", "wb+");
		cout << "Файл создан" << endl;
		if (f == NULL) {
			cout << "Неудалось открыть файл";
			exit(1);
		}
	}
	fseek(f, 0, 0);
	while (1) {
		_getch();
		system("cls");
		cout << "Меню" << endl <<
			"1.Организовать дерево" << endl <<
			"2.Просмотреть дерево" << endl <<
			"3.Отобразить структуру дерева" << endl <<
			"4.Добавить узел в дерево" << endl <<
			"5.Исключить узел из дерева" << endl <<
			"6.Сохранить в файл" << endl <<
			"7.Загрузить дерево из файла" << endl <<
			"8.Найти уровень самого правого элемента" << endl <<
			"9.Печать информации о маршрутах" << endl;
		cin >> c;
		switch (c) {
		case 0: fclose(f); free_memory(top); return;
		case 1: top = tree_org(); break;
		case 2: prosmotr(top); break;
		case 3: tree_output(top, 0); break;
		case 4: addtree(top, vvod_st()); break;
		case 5: {
			puts("Введите номер маршрута");
			scanf("%d", &s);
			tree_delete(top, s); break;
		}
		case 6: save_tree(top, f); cout << "Список сохранен"; break;
		case 7: top = read_file(f); break;
		case 8: {int rmost = most_right(top, 0);
			if (rmost == -1) printf("Дерево пустое\n");
			else printf("Уровень самого правого элемента: %d\n", rmost);
			break; }
		case 9: {
			puts("Введите название маршрута");
			cin >> q;
			pechat(top, q);
			break;
		}
		default: break;
		}
	}
}