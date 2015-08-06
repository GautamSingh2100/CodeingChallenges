#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int M[ROW][COL] = {0};
int P[ROW][COL] = {0};

/***** recursive solution of the matrix chain multiplication ****/
int MatrixChainMultiplicationRec(int *p , int lb  , int ub) 
{
	/**** when there is only one matrix ****/
	if(lb >= ub)
		return 0 ;

	/**** case when only two elements there  ****/
	if((lb + 1 ) == ub)
	{
		return p[lb-1] * p[lb] * p[ub] ;
	}

	
	int product = 0 , k;
	int min = 1000000000 ;
	
	for(k = lb ; k < ub ; k++)
	{
		product = MatrixChainMultiplicationRec(p , lb , k) + 
			  MatrixChainMultiplicationRec(p , k + 1 , ub) + p[lb-1] * p[k] * p[ub] ;

		if(product < min)
			min = product ;
	}
	
	return min ;
}

/**** initialization of the matrix , setting all element to zero ****/
/**** it require only upper half to set zero , but for the sec of simplicity 
      setting to all ****/

void initializeTheMatrix()
{
	int i = 0 ,j;
	for(i = 0 ; i <= ROW  ; i ++)
	{
		for(j = 0 ; j <= COL ; j++)
		{
			M[i][j] = 0 ;
			P[i][j] = 0 ;
		}
	
	}
}

/**** DP - aproach of the , TOp-Down ****/
int MatrixChainMultiplicationItr(int *p , int lb  , int ub) 
{
	/**** when there is only one matrix ****/
	if(lb >= ub)
		return 0 ;

	/**** case when only two elements there  ****/
	if((lb + 1 ) == ub)
	{
		return p[lb-1] * p[lb] * p[ub] ;
	}

	/***** already calculated *****/
	if(M[lb][ub] != 0 )
		return M[lb][ub] ;
	
	int product = 0 , k;
	M[lb][ub] = 1000000000 ;
		
	for(k = lb ; k < ub ; k++)
	{
		product = MatrixChainMultiplicationItr(p , lb , k) + 
			  MatrixChainMultiplicationItr(p , k + 1 , ub) + p[lb-1] * p[k] * p[ub] ;

		if(product < M[lb][ub])
		{
			M[lb][ub] = product ;
			P[lb][ub] = k ;
		}
	}
	
	return M[lb][ub] ;
}


/**** calculation of the chain multiplication using iterative solution ****/
int MatrixChainMultiplication(int *p , int lb ,int ub)
{
	if(lb == ub )
		return 0 ;
	
	if((lb + 1)== ub)
		return p[lb-1] * p[lb] * p[ub] ;

	
	initializeTheMatrix() ;

	int l , i ,x ,j, lb1 , ub1 ; 

	for(l = 2 ; l <= ub ; l++)
	{
		for(i = 1 ;  i <= ub - l + 1 ; i++)
		{	
			lb1 = i ;
			ub1 = i + l -1 ;
			M[lb1][ub1] = 100000000 ;
			for(j = lb1 ; j < ub1 ; j ++)
			{
				x = M[lb1][j] + M[j+1][ub1] + p[lb1 - 1]*p[j]*p[ub1] ;
				if(x < M[lb1][ub1] )
				{
					M[lb1][ub1] = x ;
					P[lb1][ub1] = j ;
				}
			}
		}
	}

	return M[lb][ub] ;
}


/**** print the path of the matrix that will be choosen for the product of the matrix multiplication *****/
/**** list of the index such that matrix multiplication can be done using its like postorder traversal ****/
void printWayToMultiply(int lb , int ub)
{
	if(lb >= ub)
		return ;

	if(lb + 1 == ub)
	{
		printf("%d  %d  %d \n" , lb -1 , lb , ub) ;
		return ;
	}

	printWayToMultiply(lb , P[lb][ub]) ;
	printWayToMultiply(P[lb][ub] + 1 , ub) ;	 
	printf("%d  %d  %d \n" , lb -1 , P[lb][ub] , ub) ;
}

int main()
{
	int array [] = {60 ,5 , 30 , 10} ;
	int min = MatrixChainMultiplication(array , 1 , 3 ) ;
	
	printf("%d \n" , min) ;

	printWayToMultiply(1 ,3) ;
	return 0 ;
}
