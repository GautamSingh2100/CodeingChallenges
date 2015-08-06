/**** Solution developed in NITK - second Year   ****/
/**** It Took 1 year to design and ipmelement it ****/
/**** solution complexity can be further improve ****
      by using graph traversal over the advice array ,
      such that traversal will start with smallest 
	possible way ****/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sudoku[10][10] = 
{{0,0,0,0,0,0,0,0,0,0},
{0,0,8,0,0,0,9,0,7,2},
{0,6,0,0,0,0,0,0,0,4},
{0,0,5,0,0,6,0,9,0,1},
{0,2,0,0,0,0,5,0,0,0},
{0,3,7,6,1,8,4,2,9,5},
{0,0,0,0,3,0,0,0,0,6},
{0,9,0,1,0,2,0,0,4,0},
{0,5,0,0,0,0,0,0,0,9},
{0,8,4,0,9,0,0,0,2,0}}; // very hard sudo ku prblem

int row[10][10] = {0} ; // this matrix used for the hashing the row and the digit
int col[10][10] = {0} ; // this is for the hashing the column
int TCT[4][4][10] ={0} ; // three cross three (for the three cross three matrix) to hashing the 3*3 board
int counter[10] = {0};
int l = 0 ;
// this take the information of about the list of the data that can be insereted into the matrix of // the sudo ku
struct advice 
{
	int i , j ;
	int count ;
	int adv[10] ;
};

long int total ;

typedef struct advice advice ;

advice adv1[81] ;

void advicearray(advice *adv) ;

/* this method for the setting the those position that is filled already in the matrix (row , col , TCT->three cross )
// in the TCT we are using the hasing */

void initial()
{
	int i , j , m,n;
	for(i = 1 ; i < 10 ;i++ )
	{
		for(j = 1 ; j < 10 ; j++)
		{
			if(sudoku[i][j])
			{
				row[i][sudoku[i][j]] = 1 ;
				col[j][sudoku[i][j]] = 1 ;
				TCT[(int)ceil((double)i/3)][(int)ceil((double)j/3)][sudoku[i][j]] = 1 ;
			}
		}
	}
}

// based on the initialization we can create the list of the of unfilled with and the possible input that is advice list
void advicearray(advice *adv1)
{
	int i , j , k , counter[10] = {0} , m ;
	l = 0 ;
	for(i = 1 ; i < 10 ;i++ )
	{
		for(j = 1 ; j < 10 ; j++)
		{
			if(!sudoku[i][j])
			{
				for(k = 1 ; k < 10 ; k++)
				counter[k] = row[i][k] || col[j][k] || TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][k] ;
				
				m = 1 ;
				for(k = 1 ; k < 10 ; k++)
				{
					if(!counter[k])
						adv1[l].adv[m++] = k ;
					
					counter[k] = 0 ;
				}
			
				adv1[l].count = m ;
				adv1[l].i = i ;
				adv1[l].j = j ;
				l++ ;
			}	
		}
	}
}

void print()
{
	int i,j;
	for( i = 1 ; i < 10 ;i++)
	{
		for(j = 1; j < 10 ; j++)
			printf("%d \t",sudoku[i][j]) ;
		putchar('\n');
		putchar('\n');
	}
}

/* this is the main logic for the solving the sudo ku using hasing and the back-tracking */
int sudoku_solver(int i , int j , int lb,int ub)
{
	int k,p,m,num ; // next num

	if(lb == ub)
		return 1 ;

	for(k = 1 ; k < adv1[lb].count ; k++)
	{
		 total++ ;
		num = adv1[lb].adv[k] ;
		p = row[i][num] || col[j][num] || TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][num] ; /// checking the row 			col and TCT
		if(p == 0) // recursive call
		{
			sudoku[i][j] = num ;
			row[i][num] = 1 ;
			col[j][num] = 1 ;
			TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][num] = 1;
			if(!sudoku_solver(adv1[lb+1].i , adv1[lb+1].j,lb+1,ub))
			{
				row[i][num] = 0 ;
				col[j][num] = 0 ;
				TCT[(int)ceil((double)i/3)][(int)ceil((double) j/3)][num] = 0 ;
				sudoku[i][j] = 0;
			}
			else
				return 1 ;
		}

	}

	return 0 ;
}

int main()
{

	initial();
	advicearray(adv1) ;
	if(sudoku_solver(adv1[0].i , adv1[0].j , 0 , l)) ;
		print();
	return 0;
}
