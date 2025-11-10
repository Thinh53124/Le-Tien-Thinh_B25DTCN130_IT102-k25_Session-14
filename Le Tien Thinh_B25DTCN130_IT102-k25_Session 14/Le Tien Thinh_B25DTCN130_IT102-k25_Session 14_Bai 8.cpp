#include <stdio.h>

int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n && n != 0)
        return 1;
    else
        return 0;
}

void perfectnumber(int array[], int number) {
    int found = 0;
    printf("Cac so hoan hao trong mang la: ");

    for (int i = 0; i < number; i++) {
        if (isPerfect(array[i])) {
            printf("%d ", array[i]);
            found = 1;
        }
    }

    if (!found)
        printf("Khong co so hoan hao nao trong mang.");
    printf("\n");
}

int main() {
    int array[100];
    int number;

    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    perfectnumber(array, number);
    return 0;
}
