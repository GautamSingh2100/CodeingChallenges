#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX  50
//linne validation 

/**** Algorithm :this algorithm is based on the , line slope , since no two points in n-queen solution has slope 1..
	1. choose the point , check row and col is already used or not .
	2. if not , check with the already selected point is slope not 1
	3. if slope not 1 store the point , and repeat the process for next col 
****/
/**** here the solution is on the 8 X 8 matrix , but it can be modify for the n X n matrix ****/

struct line
{
  int x, y ;
};
typedef struct line line ;  // rown is varing
int validate(int i,int j ,int inc , int row[MAX],int col[MAX],line * cord)
{
  int k , l , m ;
	if(row[i] == 0 && col[j] == 0)
	{
		for(k = 1 ; k  <  inc ; k++)
		{
			if(abs(cord[k].x - i) == abs(cord[k].y - j))
				return 0 ;   			
		}
		return 1 ;
	}
	else
	return 0 ;
}


int nqueen(int rown,int coln, int inc , int size,int valid[][MAX],int row[MAX],int col[MAX],line *cord)
{
    int i , j ,l;
    if(inc == size)
	return 1 ;			
   
    if(inc == 1) // this will only occured single time
	{
		cord[1].x         = rown ;
		cord[1].y         = coln ;
		valid[rown][coln] = 1 ;
		row[rown]         = 1 ;
		col[coln]         = 1 ;
	return nqueen(rown,coln + 1,inc + 1,size ,valid,row,col,cord) ;
	}
	
    if(rown >= 1 && rown <size && coln >= 1&& coln < size && valid[rown][coln] == 0)
	{
		
		for(l = 1 ; l < size ; l++)
		{ 
			if(validate(l,coln,inc,row,col,cord))
			{
				valid[l][coln] = 1 ;
				row[l]         = 1 ;
				col[coln]      = 1 ;	
				cord[inc].x    = l ;
				cord[inc].y    = coln ;
				if(nqueen(l,coln + 1,inc + 1,size ,valid,row,col,cord))
					return 1 ;
				valid[l][coln] = 0 ;
				row[l]         = 0 ;
				col[coln]      = 0 ;	
				cord[inc].x    = 0 ;
				cord[inc].y    = 0 ;		
		        }
		}
	}
	return 0 ;
}


void  print(int valid[][MAX],int size)
{
	int j , i ;
	putchar('\n');
	for(i= 1 ; i < size ; i++)
		{
			for(j = 1 ; j < size ; j++)
				  {printf(" %d  " , valid[i][j] ) ;}
			putchar('\n');
			putchar('\n');
		}
	
}
void flush(int valid[][MAX],int row[MAX],int col[MAX],line * cord)
{
	int i , j ;
	for(i = 0 ; i <MAX ; i++)
		{
			for(j = 0 ; j < MAX ; j++)
				valid[i][j] =  0 ;
			row[i] = 0 ;
			col[i] = 0 ;
			cord[i].x = 0 ;
			cord[i].y = 0 ;
		}
}
int main()
{
	int valid[MAX][MAX] = {0} ;
	int row[MAX] = {0} ;
	int col[MAX] = {0} ;
	int i,j ;
	line cord[MAX] = {0} ;

	j = 1 ;
	i = 1 ;
	for(i = 1 ; i < 9 ; i++)
	{
		nqueen(i,j,1,9,valid,row,col,cord) ;
		print(valid,9);
		flush(valid,row,col,cord) ;  // data flush 
	}

	return 0 ;
}
