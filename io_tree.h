#ifndef IO_TREE_H
#define IO_TREE_H
#include "tree_work.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
void free_memory(tree* top);
void save_tree(tree* top, FILE* f);
int most_right(tree* top, int level);
tree* tree_delete(tree* top, int s);
void pechat(tree* top, char* q);
#endif