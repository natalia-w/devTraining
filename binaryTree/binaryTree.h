#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include"ADTErr.h"
typedef struct Tree t_tree;
typedef enum{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
}TreeTraverse;
t_tree* TreeCreate();
void TreeDestroy(t_tree* _tree);
ADTErr TreeInsert(t_tree* _tree, int _data);
int TreeIsDataFound(t_tree* _tree, int _data);
void TreePrint(t_tree* tree, TreeTraverse _traverseMode);
#endif
