#include<iostream>


/*11,12,13,14,15,16,17,18,19,21,23,31,34,41,42,43,45,54,54,56,65,67,76,87,110,111,121,121,131,141,151,155,161,255,311,355,366,432,555,666,
678,777,*/ 

using namespace std ;
#define MAX 1000
int data[10][10] = {
		     {23,34,45,56,67,111,121,141,151,161},
		     {11,12,13,14,15,16,17,18,19,110}	,
		     {21,43,54,65,76,87,555,666,777,888},
		     {31,42,54,121,131,155,255,355,366,678},
		    {41,311,432,543,654,765,876,987,999,1000},	
		     {123,234,235,236,237,238,239,240,241,245},	
		     {124,125,126,127,128,129,130,131,132,133},	
		     {310,420,540,1210,1310,1550,2550,3550,3660,6780},
		     {410,3110,4320,5430,6540,7650,8760,9870,9990,10000},	
		     {1230,2340,2350,2360,2370,2380,2390,2400,2410,2450},			     
		   };

/**** min Heap ****/
class HeapNode
{
	public :	
	int data ;
	int x ;
	int y ;
	HeapNode();
};

HeapNode :: HeapNode() {
	data = -1 ;
	x = -1 ;
	y = -1 ;
}
class Heap
{
	HeapNode heap[MAX] ;
	int size ;
	public :
	void intializeHeap(int (*data)[10] ,int s);
	HeapNode extractMin();
	void heapifyTopDown(int i) ;
	void insertInHeap(int (*ptr)[10] ,int x,int y);
	void heapifiyFromBottomToUp(int i );
	int empty() ;
};

/**** checking the its empty *****/
int Heap::empty()
{
	if (size == 0 )
		return 1;
	else
		return 0 ;
}

void Heap::intializeHeap(int (*data)[10] , int siz)
{
	HeapNode temp ;
	this->size = siz ;
	for(int i = 0 ; i < siz ; i++)
	{
		heap[i].data = data[i][0] ;
		heap[i].x = i ;
		heap[i].y = 0 ;		
	}

	int min = size + 2  ;
	
	/**** heapifying ****/
	for(int i = size/2 ; i >=0 ; i--)
	{
		int left_child = 2*i + 1 ;
		int right_child= 2*i + 2 ;
		
		if(left_child < size && right_child < size)
		{
			if(heap[left_child].data < heap[right_child].data)
			{
				min = left_child ;
			}
			else
			{
				min = right_child ;
			}
		}
		
		else if(left_child < size)
		{
			min = left_child;
		}
		else if(right_child < size)
		{
			min = right_child ;
		}
		
		if(min < size)
		{
			if(heap[i].data > heap[min].data)
			{
				temp = heap[i] ;
				heap[i] = heap[min] ;
				heap[min] = temp ;
			}
		}		
	}
}

HeapNode Heap::extractMin()
{
	if(size == 0) return HeapNode() ;
	
	HeapNode min = heap[0] ;
	heap[0] = heap[size - 1] ;
	size-- ;

	/**** heapifying from the top to down ****/
	heapifyTopDown(0) ;
	
	
	return min ;
}

void Heap::heapifyTopDown(int i) 
{
	int left_child , right_child ,min = size + 2;
	left_child = 2*i+1 ;
	right_child= 2*i +2 ;
	HeapNode temp ;
	if(left_child < size && right_child < size)
	{
		if(heap[left_child].data < heap[right_child].data)
		{
			min = left_child ;
		}
		else
		{
			min = right_child ;
		}
	}
		
	else if(left_child < size)
	{
		min = left_child  ;
	}
	else if(right_child < size)
	{
		min = right_child ;
	}

	if(min < size)
	{
		if(heap[i].data > heap[min].data)
		{
			temp = heap[i] ;
			heap[i] = heap[min] ;
			heap[min] = temp ;
			heapifyTopDown(min) ;
		}
	}

			
}


void Heap::insertInHeap(int (*ptr)[10] , int x ,int y)
{
	if(size > 1000)
	{
		cout << "Insertion Not possible ";
		return ;
		}

	/**** range check , can be done using array ******/
	if(x >=0 && x <10 && y >=0 && y + 1 <10 )
	{
		size ++ ;
		heap[size -1].data = ptr[x][y+1] ;
		heap[size -1].x    = x ;
		heap[size -1].y    = y + 1 ;
		heapifiyFromBottomToUp(size  -  1) ;
	}
	
}

void Heap::heapifiyFromBottomToUp(int i)
{
	int parent = i / 2 ;
	HeapNode temp ;
	if(parent == 0 )
	{	
		if(heap[i].data < heap[parent].data)
		{
			temp = heap[i] ;
			heap[i] = heap[parent] ;
			heap[parent] = temp ;			
		}
		return ;
	}
	
	if(heap[i].data < heap[parent].data)
	{
		temp = heap[i] ;
		heap[i] = heap[parent] ;
		heap[parent] = temp ;			
		heapifiyFromBottomToUp(parent) ;
	}
	return ;
}

void display(int * array, int size)
{
	for(int i =0 ; i < size ; i++)
	{
		cout << array[i] << "   "  ;
	}

}

int main()
{
	int array[MAX] ;
	Heap heapObj ;
	int i = 0 ; 
	heapObj.intializeHeap(data,10) ;
	while(!heapObj.empty())
	{
		
		HeapNode n = heapObj.extractMin();
		array[i] = n.data ; i++ ;
		heapObj.insertInHeap(data, n.x,n.y) ;

	}
		
	display(array,i) ;
	return 0;
}
