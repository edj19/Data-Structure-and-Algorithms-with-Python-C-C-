#include<stdio.h>

int main()
{
	int x;

	// scanf("%d",&x);
	x = 13425;
	int mask = 1;
	int t=x;
	while(t>9){
		t /=10;
		mask *=10;
	}
	printf("mask=%d\n",mask );
	do{
		int d = x/mask;
		printf("%d",d );
		if(mask>9){
			printf(" ");
		}
		x %= mask;
		mask /=10;
	}while(mask>0);
	printf("\n");
	/*
	13452/10000 ->1
	13425%10000 ->3425
	10000/10    ->1000
	3425/1000   ->3
	3245%1000   ->425
	1000/10     ->100
	425/100    ->4
	425%100     ->25
	100/10     ->10
	25/10      ->2
	25%10      ->5
	10/10     ->1
	5/1        ->5
	5%1        ->5
	1/10       ->0
	*/
	/* Solution 1 没有考虑边界条件
	int t=0;
	do{
		int d=x%10;
		t = t*10+d;
		x /=10;
	}while(x>0);
	printf("t=%d\n",t );
	x = t;
	do{
		int d=x%10;
		printf("%d",d );
		if(x>=10){
			printf(" ");
		}
		x /=10;
	}while(x>0);
	printf("\n");
*/

	return 0;
}