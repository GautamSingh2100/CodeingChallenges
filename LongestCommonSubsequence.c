#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ROW 100 
#define COL 100 

/**** table to store the LCS , PATH ***/
int LCS[ROW][COL] , PATH[ROW][COL] ;

/**** initialization of the array ****/
void initialize()
{
	int i , j ; 
	for(i = 0 ; i < ROW ; i++)
	{
		LCS[i][0] = 0 ;
		LCS[0][i] = 0 ;
	}
}

/**** returning the max two element ****/
int max (int num1 ,int num2 )
{
	return num1 > num2 ? num1 : num2 ;
}

/**** recursive solution of the longest subseq , returning the length of the common sub - seq       ****/
int longestCommonSubseq(char *str1 , char *str2) /*** no need to take the length of the str1 , '\0' ****/
{
	if(*str1 == '\0' || *str2 == '\0')
		return 0 ;

	if(*str1 == *str2)
	{
		return longestCommonSubseq( str1 + 1 , str2 + 1 )  + 1;
	}

	return max (longestCommonSubseq(str1 + 1 , str2 ) , longestCommonSubseq(str1 , str2 + 1)) ;
}

/**** displaying the LCS , recursively ****/
void displayLCS(char *str1 , char *str2 , int max , int lb ,int ub ,int *lock)
{
	if(lb < 0 || ub < 0  || LCS[lb][ub] == 0 || LCS[lb][ub] != max || lock[max] != 0 )
	{
		return ;
	}
		
	if(LCS[lb][ub] == max && str1[lb - 1] == str2[ub - 1])
	{
		displayLCS(str1 ,str2 , LCS[lb - 1][ub - 1] , lb - 1, ub -1 , lock ) ;
		lock[max] = -1 ;
		printf("%c" , str1[lb - 1])	 ;
	}
	else
	{
		displayLCS(str1 , str2 , max , lb - 1 , ub , lock) ;
		displayLCS(str1 , str2 , max , lb , ub -1  , lock) ;
	}
}

/**** display Matrix ****/
void display(int row , int col )
{
	int i , j ;
	for(i = 0 ; i <= row ; i++)
	{
		for(j = 0 ; j <= col ; j ++)
		{	
			printf(" %d " , LCS[i][j]) ;
		}
		
		printf("\n") ;
	}	

}
/**** LCS using DP *****/
void longestCommonSubseqDP(char *str1 , char *str2)
{
	int len1 = strlen(str1) ;  // act as the row
	int len2 = strlen(str2) ;  // act as the col 
	/*** initializing the table ****/
	initialize() ;

	int i , j ;
	for( i = 1 ; i <= len1 + 1 ; i++)
	{
		for( j  = 1 ; j <= len2  + 1; j++)
		{
			if(str1[i - 1] == str2[j -1])
			{	
				LCS[i][j] = LCS[i- 1][j - 1] + 1 ;
			}
			else
			{
				if(LCS[i - 1][j] < LCS[i][j - 1])
				{
					LCS[i][j] = LCS[i ][j - 1] ;
				}
				else
				{	
					LCS[i][j] = LCS[i - 1][j] ;
				}
			}
		}			
	}
}

int main()
{
	char str2[] =  "ABCDGH" , str1[] = "AEDHFR"  ; // length : 3.
	char str3[] =  "AGGTAB" , str4[] = "GXTXAYB" ; // length : 4.
	
	int *lock = (int *) calloc(sizeof(int) , ROW) ;
	int len1 = strlen(str1) ;
	int len2 = strlen(str2) ;

	printf(" %d " , longestCommonSubseq(str1 ,str2)) ;
	printf(" %d " , longestCommonSubseq(str3 ,str4)) ;

	/**** calcluating the LCS ****/
	longestCommonSubseqDP(str1 ,str2) ;
	displayLCS(str1 ,str2 , LCS[len1][len2] , len1 , len2 ,lock ) ;
	
	printf("\n");
	free(lock) ;
	lock = (int *) calloc(sizeof(int) , ROW) ;
	
	/**** calculating the LCS *****/
	longestCommonSubseqDP(str3 ,str4) ;
	displayLCS(str3 ,str4 , LCS[6][7] , 6 , 7 , lock) ;		
	return 0 ;
}
