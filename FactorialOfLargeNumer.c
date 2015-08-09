/*** this program will calculate the factorail of large number ****/
#include <stdio.h>

void printFactorial(int len) ;

/**** nearly perfect size of the F will be : n * log10(10) ***/
/**** just for the sec of simplicity taking MAX ****/
#define MAX 1000
int F[MAX] = {1} ;

void initialize()
{
    int  i = 0 ; 
	for(i = MAX - 1 ; i >=0 ; i --)
		F[i] = 1 ;
}
/**** calculate the factorial of small number ****/
int factorial(int n)
{
	int i , j , len = 1  , rem = 0 ;
	int temp  ;
	/*** initializ ing th table ****/
	initialize() ;
	/***** Calculating  the factoriall for each number ****/
	for(i = 1 ; i <= n ; i++)
	{
		rem = 0 ;
		for(j = 0 ; j < len ; j++  )
		{
			temp = (F[j] * i + rem)  % 10 ;
			rem  = (F[j] * i + rem)  / 10 ;
			F[j] = temp ;
		}
		if(rem != 0)
		{
			while(rem)
			{
				F[j] = rem % 10 ;
				rem  = rem / 10 ;
				j++ ;				
			}		
			len = j  ;
		}
	}
	
	return len ;
		
}

/**** displaying the value as big-endian ****/
void printFactorial(int len) 
{
	int  i = 0 ; 
	for(i = len - 1  ; i >= 0 ; i --)
		printf("%d" , F[i]) ;
		
	
}
int main()
{
    int N  , T , i; 
    /**** enter the number ****/	
    //printf("Enter the number of test cases") ;
    scanf("%d" ,&T) ;
    for(i = 0 ; i < T ; i++)
    {
        ///printf("ENter the Number : \n" ) ;
        scanf("%d" , &N) ;
        if(N == 0)
        printf("%d\n" , 1 ) ;
        else
        {
          int len = factorial(N) ;
          printFactorial(len) ;
          printf("\n") ;
        }
    }
    return 0;
}
