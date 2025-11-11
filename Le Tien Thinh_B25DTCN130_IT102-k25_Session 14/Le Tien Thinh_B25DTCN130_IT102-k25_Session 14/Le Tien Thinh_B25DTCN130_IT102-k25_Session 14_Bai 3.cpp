#include <stdio.h>
int Tong(){
	int a,b;
	printf("Nhap so a:");
	scanf("%d",&a);
	printf("Nhap so b:");
	scanf("%d",&b);
	int sum = a + b;
	return sum;
}

int main (){
	int number;
	int a,b;
	int sum;
	sum = Tong();
	printf("ket qua cua phep tinh tong la:%d",sum);
}
