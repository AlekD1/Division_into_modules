#ifndef DROB_MOD_H
#define DROB_MOD_H
struct marsh {
	int id, number;
	char nap[15], kop[15];
};

struct tree {
	marsh inf;
	tree* right;
	tree* left;
};
const int size_marsh = sizeof(marsh);
void work();

#endif