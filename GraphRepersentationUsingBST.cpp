#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct NodePtr
{
	int nodeID ;
	int edge   ;
	struct NodePtr *next ;
};

struct GraphNode
{
	int nodeID ;
	struct GraphNode *left ;
	struct GraphNode *right;
	struct NodePtr *next ;
};

int isExsit(struct GraphNode *root , int key)
{
	if(root == NULL)
		return 0 ;


	if(root->nodeID == key)
	{
		return 1 ;
	}
	else if( root->nodeID > key)
		return isExsit(root->left , key)  ;
	else
		return isExsit(root->right , key) ;
}


struct GraphNode * Insert(struct GraphNode *root , int u)
{
	if(root == NULL)
	{
		root = malloc(sizeof(struct GraphNode)) ;
		root->left  = NULL ;
		root->right = NULL ;		
		root->next  = NULL ;
		root->nodeID = u ;
		return root ;
	}
		
	if(root->nodeID > u)
	{
		root->left = Insert(root->left , u) ;
	}
	else if(root->nodeID < u)
	{
		root->right = Insert(root->right , u) ;
	}
	return root ;
}

/**** insert any edge need to check node exsists or not ***/
struct GraphNode * insert(struct GraphNode *root , int u , int v , int edge)
{
	/***** is u exsit in AVL Tree *****/
	if(!isExsit(root , u))
	{
		root = Insert(root ,u) ;
	}

	if(!isExsit(root , v))
	{
		root = Insert(root , v) ;
	}
	/***** Till Now both node is in the AVL Tree *****/
	/*****
		1. search u
		2. create new node 
		3. edit v , edge ****/	
	/**B1**/
	struct GraphNode *temp = root ;
	struct NodePtr *ptr1  = malloc(sizeof(struct NodePtr)) ;
	struct NodePtr *ptr2 =  malloc(sizeof(struct NodePtr)) ;
	
	while(temp->nodeID != u)
	{
		if(temp->nodeID > u)
			temp  = temp->left ;
		else
			temp = temp->right ;
	}

	ptr1->nodeID = v ;
	ptr1->edge = edge ;
	ptr1->next = temp->next ;
	temp->next = ptr1 ;

	/***** same for the v *****/
	temp = root ;
	while(temp->nodeID != v)
	{
		if(temp->nodeID > v)
			temp  = temp->left ;
		else
			temp = temp->right ;
	}

	ptr2->nodeID = u ;
	ptr2->edge = edge ;
	ptr2->next = temp->next ;
	temp->next = ptr2 ;
	
	return root ;
}

void display(struct GraphNode * root)
{
	if(root == NULL)
		return ;

	printf("%d    ", root -> nodeID) ;
	display(root->left) ;
	display(root->right);
}

/***** displaying the graph using preorder terversal ****/
void displayGraph(struct GraphNode *root)
{
	
	if(root == NULL)
		return ;

	printf("%d  : " ,root->nodeID) ;	
	struct NodePtr * temp = root->next   ;
	while(temp)
	{
		printf("(%d , %d) , " , temp->nodeID ,temp->edge ) ;
		temp = temp->next ;
	}
	printf("\n\n");
	displayGraph(root->left) ;
	displayGraph(root->right);
}

int main()
{

	struct GraphNode *root = NULL ;
	root =insert(root , 1 , 4 , 3) ;	
	root =insert(root , 1 , 5 , 2) ;
	root =insert(root , 2,3,1) ;
	root =insert(root , 2,7,7) ;
	root =insert(root , 3,7,4) ;
	root =insert(root , 3,5,2) ;
	root =insert(root , 3,4,5) ;
	root =insert(root , 4,5,3) ;
	root =	insert(root , 5,6,1) ;
	root =insert(root , 6,7,1) ;
//	display(root) ;
	displayGraph(root);
}
