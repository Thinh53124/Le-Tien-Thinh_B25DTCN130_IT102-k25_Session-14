#include <stdio.h>
void Ham(int number,int array[100]){
	int i;
	for (i=0;i<number;i++){
		printf("\narray[%d]:%d\n",i,array[i]);
	}
}
int main () {
	int number;
	int i;
	int array [100];
	printf("nhap phan tu mang:");
	scanf("%d",&number);
	for(i=0;i<number;i++){
		printf("array[%d]",i);
		scanf("%d",&array[i]);
	}
	printf("mang khi in ra la:");
	Ham(number,array);

}
