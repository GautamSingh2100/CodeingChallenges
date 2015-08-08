#include <stdlib.h>
#include <stdio.h>
#define MAX 100 
int L[MAX]  ;


/*** initializing the table ****/
void initialize()
{
	/***** single length increasing subsequence ****/

	int i ;
	for(i = 0 ; i < MAX ; i++)
		L[i] = 1 ;
}

/**** return the inddex of the max element ****/
int maxIndex(int *arr , int n)
{
	int max =  0 ;
	int i  ;
	for( i = 1 ; i < n ; i ++)
	{
		if(arr[max] < arr[i])
			max = i ;
	}

	return max ;
}

/**** filtering the subseq ****/
void filterSubseq(int *array , int *subSeq, int max , int index , int *level)
{
	if(index < 0)
	{
		return ;
	}

	int i = index - 1 ;
	while( i >= 0 && L[i] != (max - 1))
	{
		i -- ;
	}

	if(i >= 0)
	{
		filterSubseq(array , subSeq ,  L[i] , i ,level) ;		
	}	
	subSeq[*level] =  array[index] ;
	(*level)++ ;		
}
int * largestIncreasingSubseq(int *array , int n)
{
	int *subSeq = (int *) calloc(sizeof(int) ,  n) ;
	
	/*** intializing the table ****/
	initialize() ;
	
	int i , j  , k; 
	
	for(i = 1 ; i < n ; i++)
	{
		for(j = 0 ; j  < i ; j++)
		{
			if(array[j] < array[i] && L[i] < (L[j] + 1))
			{
				L[i] = L[j] + 1 ;
			}
		}
	}		

	i = 0 ;
	filterSubseq(array , subSeq , L[maxIndex(L , n)] , maxIndex(L , n) , &i) ;
	return subSeq ;
}

void displayList(int * arr , int n)
{

	int i  ;
	for(i = 0 ;  i < n  ; i++)
	{	
		if(arr[i]!= 0)
			printf(" %d ", arr[i] ) ;
		else
		{
			return ;
		}
	}
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 } ;
	int size  = 9 ;
	int *arr1  = largestIncreasingSubseq(arr , size) ;

	displayList(arr1 , size) ;
	return 0 ;

}
