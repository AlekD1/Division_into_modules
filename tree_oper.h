#define _CRT_SECURE_NO_WARNINGS
#ifndef TREE_OPER_H
#define TREE_OPER_H
#include "tree_work.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
marsh vvod_st();
void prosmotr(tree* top);
tree* tree_org() , * read_file(FILE* f);
void tree_output(tree* top, int otstup);
tree* addtree(tree* top, const marsh& newtree_st);
#endif
