/***** this is the simple example to show the right rotation and left rotation ****/
/***** Here sq-matrix repersents Imagge 
		1. reverse the matrix row wise and transpose it --->left rotation
		2. transpose then reverse right rotation ****/
#include<iostream>



#define MAX 10

void swap(int &data1 , int &data2)
{
	int temp = data1 ;
	data1 = data2 ;
	data2= temp ;	
}

void reverse(int (*mat)[MAX] , int row,int lb ,int ub)
{
	if(lb > ub)
		return ;
		
	swap(mat[row][lb], mat[row][ub])	;
	reverse(mat,row,lb+1 , ub -1) ;
}

/*****rotating right by 90 degree ****/
void RightRotate(int (*mat)[MAX] , int size)
{
	
	int i , j , temp;
	/**** reversing the matrix ***/
	for(i = 0 ; i < size ; i++)
	{
			reverse(mat, i , 0 , size) ;
	}
	
	/*****transpose ****/
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < i ; j++)
		{
			swap(mat[i][j] , mat[j][i]) ;
		}
	}	
}

/***** rotating left side by 90 degree ****/
void LeftRotate(int (*mat)[MAX] , int size)
{
	int i , j , temp;
	
	
	/*****transpose ****/
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < i ; j++)
		{
			swap(mat[i][j] , mat[j][i]) ;
		}
	}	
	/**** reversing the matrix ***/
	for(i = 0 ; i < size ; i++)
	{
			reverse(mat, i , 0 , size) ;
	}
}

/****to be continued ****/
