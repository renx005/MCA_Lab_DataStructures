#include<stdio.h>
int a = 10;
int main()
{
	register int b = 5;
	printf("the value of b is %d\n",b);
	printf("The value of a is %d\n",a);
	display();
	return 0;
}
void display()
{
	int b = 7;
	printf("Inside the function\n"); 
	printf("The value of b is %d\n",b);
	printf("The value of a is %d\n",a);
}

