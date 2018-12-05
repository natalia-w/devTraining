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

STATIC t_node* SearchRoot(t_node* _root, int num){
	if (_root == NULL){
		return NULL;
	}
	if (_root->m_data < num ){
		if(_root->m_right == NULL){
			return _root;
		}
		return SearchRoot(_root->m_right, num);
	}
	if (_root->m_data > num){
		if(_root->m_left == NULL){
			return _root;
		}
		return SearchRoot(_root->m_left, num);
	}
	if (_root->m_data = num){
		return _root;
	}
	return _root;
}

STATIC t_node* NodeAdd(t_node* _father, int _data){
	t_node* newNode = (t_node*)malloc(sizeof(t_node));
	if (newNode != NULL){
		newNode->m_data = _data;
		newNode->m_left = NULL;
		newNode->m_right = NULL;
		newNode->m_father = _father; 
	}
	return newNode;	
}

ADTErr TreeInsert(t_tree* _tree, int _data){
	t_node* rootNode;
	t_node* newNode;
	if (_tree == NULL){
		return ERR_NOT_INITIALIZED;
	}
	rootNode = SearchRoot(_tree->m_root, _data);
	if (rootNode == NULL || rootNode != NULL && rootNode->m_data != _data){
		newNode = NodeAdd(rootNode, _data);
		if (newNode == NULL){
			return ERR_ALLOCATION_FAILED;		
		}
	}
	if (rootNode == NULL){
		_tree->m_root = newNode;
	}
	else{
		if (rootNode->m_data != _data){
			if(rootNode->m_data > _data){
				rootNode->m_left = newNode;
			}
			else{
				rootNode->m_right = newNode;
			}
		}
	} 
	return ERR_OK;
}

STATIC int SearchNum(t_node* _root, int num){
	if (_root == NULL){
		return 0;	
	}
	else{
		if (_root->m_data == num){
			return 1;
		}
		else{
			return (SearchNum(_root->m_left, num) + SearchNum(_root->m_right, num)); 
		}
	}
} 

int TreeIsDataFound(t_tree* _tree, int _data){
	int instancesOfNum = 0;
	if (_tree == NULL){
		return 0;
	}
	if (_tree->m_root == NULL){
		return 0;
	}
	instancesOfNum = SearchNum(_tree->m_root, _data);
	if (instancesOfNum == 0){
		return instancesOfNum;
	}
	else{
		return 1;
	}
}

void NodesPrint(t_node* _root, TreeTraverse _traverseMode){
	if (_root == NULL){
		return;
	}
	if (_traverseMode == PRE_ORDER){
		printf(" %d, ", _root->m_data);
	}
	NodesPrint(_root->m_left, _traverseMode);
	if (_traverseMode == IN_ORDER){
		printf(" %d, ", _root->m_data);
	}
	NodesPrint(_root->m_right, _traverseMode);
	if (_traverseMode == POST_ORDER){
		printf(" %d, ", _root->m_data);
	}
}

void TreePrint(t_tree* _tree, TreeTraverse _traverseMode){
	if(_tree == NULL){
		printf("The tree is NULL \n");
		return;
	}
	NodesPrint(_tree->m_root, _traverseMode);
	printf("\n");
	return;
}



	


