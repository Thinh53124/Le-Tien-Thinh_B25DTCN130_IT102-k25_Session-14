
#include <stdio.h>
int ucln(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main() {
    int x , y ;  
    int kq;
    printf("nhap so x:");
    scanf("%d",&x);
    printf("nhap so y:");
    scanf("%d",&y);
    kq = ucln(x, y);  
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", x, y, kq);
    return 0;
}
