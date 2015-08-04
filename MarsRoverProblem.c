#include <stdio.h>
#include <stdlib.h>


/**** x is Row and y is col , ****/
/**** direction calculation x1 - x , y1 - y ****/
void marsRover(char *path , int x, int y , int x1 ,int y1)
{
	if(*path == '\0')
	{
		/**** print the final state of the rover ****/
		if((y1 - y) == 1 && (x1 - x) == 0) /**** north direction ***/
		{	
			printf(" X : %d   Y: %d   %c " , x ,y , 'N');
		}
		else if((y1 - y) == -1 && (x1 - x) == 0) /**** south direction ****/
		{
			printf(" X : %d   Y: %d   %c " , x ,y , 'S');
		}
		else if((y1 - y) == 0 && (x1 - x) == 1)	/**** East direction ****/	
		{
			printf(" X : %d   Y: %d   %c " , x ,y , 'E');	
		}
		else if((y1 - y) == 0 && (x1 - x) == -1) /**** west Direction ****/
		{
			printf(" X : %d   Y: %d   %c " , x ,y , 'W');
		}
		return ;
	}

	if(*path == 'R')
	{
		/**** print the final state of the rover ****/
		if((y1 - y) == 1 && (x1 - x) == 0) /**** north direction ***/
		{	
			marsRover(path + 1 , x, y , x + 1, y ) ;
		}
		else if((y1 - y) == -1 && (x1 - x) == 0) /**** south direction ****/
		{
			marsRover(path + 1 , x, y , x - 1 , y ) ;
		}
		else if((y1 - y) == 0 && (x1 - x) == 1)	/**** East direction ****/	
		{
			marsRover(path + 1 , x, y , x , y - 1) ;
		}
		else if((y1 - y) == 0 && (x1 - x) == -1) /**** west Direction ****/
		{
			marsRover(path + 1 , x, y , x , y +1) ;
		}	
	}
	else if(*path == 'L')
	{
		/**** print the final state of the rover ****/
		if((y1 - y) == 1 && (x1 - x) == 0) /**** north direction ***/
		{	
			marsRover(path + 1 , x, y , x - 1, y ) ;
		}
		else if((y1 - y) == -1 && (x1 - x) == 0) /**** south direction ****/
		{
			marsRover(path + 1 , x, y , x + 1 , y ) ;
		}
		else if((y1 - y) == 0 && (x1 - x) == 1)	/**** East direction ****/	
		{
			marsRover(path + 1 , x, y , x , y + 1) ;
		}
		else if((y1 - y) == 0 && (x1 - x) == -1) /**** west Direction ****/
		{
			marsRover(path + 1 , x, y , x , y - 1) ;
		}	
	}
	else if(*path == 'M')
	{
		/**** print the final state of the rover ****/
		if((y1 - y) == 1 && (x1 - x) == 0) /**** north direction ***/
		{	
			marsRover(path + 1 , x , y + 1 , x1 , y1 + 1 ) ;
		}
		else if((y1 - y) == -1 && (x1 - x) == 0) /**** south direction ****/
		{
			marsRover(path + 1 , x, y - 1 , x , y1 -1 ) ;
		}
		else if((y1 - y) == 0 && (x1 - x) == 1)	/**** East direction ****/	
		{
			marsRover(path + 1 , x + 1, y , x1 + 1 , y1) ;
		}
		else if((y1 - y) == 0 && (x1 - x) == -1) /**** west Direction ****/
		{
			marsRover(path + 1 , x - 1, y , x1 -1 , y1) ;
		}		
	}
}


int main()
{
/***
5 5
1 2 N
LMLMLMLMM
3 3 E
MMRMMR****/

	marsRover("LLLLLLLRRRRRRRRLLLLRRRMMMLLML" , 1 , 2 , 1 , 3) ;
	
	printf("\n\n") ;
	
	marsRover("" , 3 , 3 , 4 , 3) ;
}

