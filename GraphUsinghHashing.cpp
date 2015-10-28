#include<stdio.h>
#include<stdlib.h>

#define MAX 10001

struct EdgeNode
{
	int nodeID;
	int edge  ;
	struct EdgeNode *next ;	
};

struct GraphNode
{
	int vertex ;
	struct GraphNode *nodeNext ;
	struct EdgeNode *next ;
};

struct GraphTable
{
	struct GraphNode *table[MAX] ;
};

void initializeTable(struct GraphTable *root)
{
	int i ;
	for(i = 0 ; i < MAX ; i++)
		root->table[i] = NULL ;
}
int HashFunction(int u)
{
	return (u*u + u + 1)%MAX ;
}

/**** weather given node already exsits or not *****/
int isExist(struct GraphTable *root,int u)
{
	int hash = HashFunction(u) ;
	struct GraphNode * ptr = root->table[u] ;
	while(ptr && ptr->vertex !=u)
		ptr = ptr->nodeNext ;

	if(ptr == NULL)
		return 0 ;
	return 1 ;
}

/***** inserting the node in the hash table *****/
void insertU(struct GraphTable *root , int u)
{
	if(root == NULL)
		return ;

	int hash = HashFunction(u) ;
	struct GraphNode *node = root->table[hash] ;
	struct GraphNode *newNode = malloc(sizeof(struct GraphNode)) ;
	newNode->vertex = u ;
	newNode->nodeNext = node ;
	root->table[hash] = newNode ;
	newNode->next     = NULL ;

}

/***** inserting the node that not inserted ****/
void insert(struct GraphTable *root, int u , int v , int edge)
{
	if(!isExist(root , u))
	{
		insertU(root , u) ;
	}

	if(!isExist(root,v))
	{
		insertU(root,v) ;
	}

/***** for the u *****/	
	int hash = HashFunction(u) ;
	struct GraphNode *ptr = root->table[hash] ;

	while(ptr && ptr->vertex != u)
	{
		ptr = ptr->nodeNext ;
	}

	struct EdgeNode *newNode = malloc(sizeof(struct EdgeNode)) ;
	newNode->nodeID = v    ;
	newNode->edge   = edge ;
	newNode->next = ptr->next ;
	ptr->next     = newNode ;

/**** for the v ****/
	 hash = HashFunction(v) ;
	 ptr = root->table[hash] ;

	while(ptr && ptr->vertex != v)
	{
		ptr = ptr->nodeNext ;
	}

	newNode = malloc(sizeof(struct EdgeNode)) ;
	newNode->nodeID = u    ;
	newNode->edge   = edge ;
	newNode->next = ptr->next ;
	ptr->next     = newNode ;
}

void displayList(struct GraphNode *root)
{
	struct EdgeNode *edgeRoot = root->next ;
	printf("%d  : " ,root->vertex) ;

	while(edgeRoot)
	{
		printf("(%d , %d)",edgeRoot->nodeID, edgeRoot->edge) ;
		edgeRoot = edgeRoot->next ;
	}
	printf("\n\n") ;
}

/**** displaying the graph *****/
void Display(struct GraphTable *root )
{
	int i ; 
	for(i = 0 ; i < MAX ; i++)
	{
		if(root->table[i] != NULL)
		{
			struct GraphNode *ptr = root->table[i] ;
			displayList(ptr) ;
			ptr = ptr->nodeNext ;
			while(ptr)
			{
				displayList(ptr) ;
				ptr = ptr->nodeNext ;
			}
		}
	}

}

int main()
{
	struct GraphTable *root = malloc(sizeof(struct GraphTable)) ;
	initializeTable(root);
	insert(root , 1,4,3) ;	
	insert(root , 1,5,2) ;
	insert(root , 2,3,1) ;
	insert(root , 2,7,7) ;
	insert(root , 3,7,4) ;
	insert(root , 3,5,2) ;
	insert(root , 3,4,5) ;
	insert(root , 4,5,3) ;
	insert(root , 5,6,1) ;
	insert(root , 6,7,1) ;
	Display(root) ;

}
