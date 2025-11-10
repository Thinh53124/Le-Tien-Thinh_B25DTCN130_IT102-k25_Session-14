#include <stdio.h>
void elementnumber(int number){
	int i;
	int isPrime = 0;
	for (i=2;i<=number-1;i++){
		if(number%i==0){
			isPrime = 1;
		}
	}
	if(isPrime == 0 && number != 1){
		printf("so %d la so nguyen to",number);
	}else{
		printf("so %d khong phai la so nguyen to",number);
	}
}

int main () {
	int number;
	int i;
	printf("Nhap mot so vao:");
	scanf("%d",&number);
	elementnumber(number);
}
