#include<stdio.h>
#include"binaryTree.h"

main(){

	t_tree* tree;
	TreePrint(tree, PRE_ORDER);
	tree = TreeCreate();
	if (tree == NULL){
		printf("The tree is null");
	}	
	printf("After TreeCreate(): ");
	TreePrint(tree, PRE_ORDER);
	printf("\n ");
	TreeInsert(tree, 10);
	printf(" TreeInsert Ok \n");
	printf("PRE_ORDER \n ");
	TreePrint(tree, PRE_ORDER);
	printf(" result of treeIsDataFound(tree, 5) is %d \n", TreeIsDataFound(tree, 5));
	printf(" result of treeIsDataFound(tree, 10) is %d \n", TreeIsDataFound(tree, 10));
	TreeDestroy(tree);
	printf(" TreeDestroy Ok \n");
	printf("PRE_ORDER \n ");
	TreePrint(tree, PRE_ORDER);
	printf(" result of treeIsDataFound(tree, 5) is %d \n", TreeIsDataFound(tree, 5));
	printf(" result of treeIsDataFound(tree, 10) is %d \n", TreeIsDataFound(tree, 10));
	TreeInsert(tree, 4);
	TreeInsert(tree, 2);
	TreeInsert(tree, 1);
	TreeInsert(tree, 3);
	TreeInsert(tree, 6);
	TreeInsert(tree, 5);
	TreeInsert(tree, 7);
	TreeInsert(tree, 8);
	printf("PRE_ORDER \n ");
	TreePrint(tree, PRE_ORDER);
	printf("IN_ORDER \n ");
	TreePrint(tree, IN_ORDER);
	printf("POST_ORDER \n ");
	TreePrint(tree, POST_ORDER);
	printf(" result of treeIsDataFound(tree, 4) is %d \n", TreeIsDataFound(tree, 4));
	printf(" result of treeIsDataFound(tree, 2) is %d \n", TreeIsDataFound(tree, 2));
return;
}
