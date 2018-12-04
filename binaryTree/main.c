#include<stdio.h>
#include"binaryTree.h"

main(){

	t_tree* _tree;
	_tree =(t_tree*) TreeCreate();
	if (_tree == NULL){
		printf("The tree is null");
	}	
	printf("Ok \n");
	TreeInsert(_tree, 10);
	printf(" TreeInsert Ok \n");
	TreeDestroy(_tree);
	printf(" TreeDestroy Ok \n");
return;
}
