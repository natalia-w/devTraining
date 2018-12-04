#include<stdio.h>
#include"binaryTree.h"
#include<stdlib.h>

#define STATIC static
typedef struct Node t_node;

struct Node
{
	int m_data;
	t_node* m_left;
	t_node* m_right;
	t_node* m_father;
};

struct Tree
{
	t_node* m_root;
};

typedef enum
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
}TreeTraverse;

t_tree* TreeCreate(){
	t_tree* _tree;
	_tree = (t_tree*)malloc(sizeof(t_tree));
	if (_tree == NULL){
		return NULL;
	}
	_tree->m_root = NULL;
	return _tree;
}

STATIC void TreeDestroyByRootRec(t_node* _root){
	if (_root->m_left == NULL && _root->m_right == NULL){
		free(_root);
		return;
	}
	if (_root->m_left != NULL){
		TreeDestroyByRootRec(_root->m_left);
	}
	if (_root->m_right != NULL){
		TreeDestroyByRootRec(_root->m_right);
	}
	free(_root);
	return;
}

void TreeDestroy(t_tree* _tree){
	if (_tree == NULL){
		return;
	}
	TreeDestroyByRootRec(_tree->m_root);
}
/*STATIC t_node* TreeInsertNodeRec(t_node* _root, int numToInsert){
	t_node* newNode;
	t_node* fatherNode = NULL;
	int tagMallocFailed = 0;
	if (_root == NULL){
		newNode = createNode(numToInsert, fatherNode);
		if (newNode == NULL){
		tagMallocFailed = 1;
		}		
		return newNode; 
	}
	if (_root->m_data < numToInsert){
		fatherNode = _root;
		_root->m_right = TreeInsertNodeRec(_root->m_right, numToInsert);
	}
	else if (_root->m_data > numToInsert){
		fatherNode = _root;
		_root->m_left = TreeInsertNodeRec(_root->m_left, numToInsert);
	}
	if (tagMallocFailed == 1){
		return; 
	}
	return _root;
}*/

STATIC t_node* SearchRoot(t_node* _root, int num){
	if (_root == NULL){
		return NULL;
	}
	if (_root->m_data < num ){
		if(_root->m_left == NULL){
			return _root;
		}
		return SearchRoot(_root->m_left, num);
	}
	if (_root->m_data > num){
		if(_root->m_right == NULL){
			return _root;
		}
		return SearchRoot(_root->m_left, num);
	}
	if (_root->m_data = num){
		return _root;
	}


}

ADTErr TreeInsert(t_tree* _tree, int _data){
	t_node* rootNode;
	t_node* newNode;
	if (_tree == NULL){
		return ERR_NOT_INITIALIZED;
	}
	rootNode = SearchRoot(_tree->m_root, _data);
	if (rootNode == NULL){
		newNode = (t_node*)malloc(sizeof(t_node));
		if (newNode == NULL){
			return ERR_ALLOCATION_FAILED;		
		}
		NodeAdd(t_node* 
	}
	return ERR_OK;
}


/*int treeIsDataFoundRec(t_node* _node, int _data){

}

int treeIsDataFound(t_tree* _tree, int _data){
	if (_tree == NULL){
		return 0;	
	}
	return treeIsDataFoundRec(_tree->m_root, _data);

}*/


	


