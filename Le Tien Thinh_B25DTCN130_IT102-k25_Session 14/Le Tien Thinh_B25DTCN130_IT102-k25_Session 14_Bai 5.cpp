#include <stdio.h>
int factorial (int number){
	int sum = 1;
	int i;
	for(i=2;i<=number;i++){
		sum *=i;
	}
	return sum;
}

int main () {
	int sum=1,number;
	int i;
	printf("nhap vao gia tri cua n:");
	scanf("%d",&number);
	for(i=2;i<=number;i++){
		sum *=i;
	}
	printf("Gia thua cua so do la: %d\n",sum);
	printf("=> %d! = %d",number,sum);
}
