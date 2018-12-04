#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include"ADTErr.h"
typedef struct Tree t_tree;
t_tree* TreeCreate();
void TreeDestroy(t_tree* _tree);
ADTErr TreeInsert(t_tree* _tree, int _data);
int treeIsDataFound(t_tree* _tree, int _data);
#endif
