#include <stdio.h>
void nhapMang(int a[], int *n);
void xuatMang(int a[], int n);
void themPhanTu(int a[], int *n, int vitri, int giatri);
void suaPhanTu(int a[], int n, int vitri, int giatri);
void xoaPhanTu(int a[], int *n, int vitri);
void sapXepTang(int a[], int n);
void sapXepGiam(int a[], int n);
int timKiemTuyenTinh(int a[], int n, int x);
int timKiemNhiPhan(int a[], int n, int x);

int main() {
    int a[100];
    int n = 0, choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap so phan tu va gia tri\n");
        printf("2. In ra cac phan tu\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(a, &n);
                break;
            case 2:
                xuatMang(a, n);
                break;
            case 3: {
                int vitri, giatri;
                printf("Nhap vi tri can chen: ");
                scanf("%d", &vitri);
                printf("Nhap gia tri can chen: ");
                scanf("%d", &giatri);
                themPhanTu(a, &n, vitri, giatri);
                break;
            }
            case 4: {
                int vitri, giatri;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &vitri);
                printf("Nhap gia tri moi: ");
                scanf("%d", &giatri);
                suaPhanTu(a, n, vitri, giatri);
                break;
            }
            case 5: {
                int vitri;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &vitri);
                xoaPhanTu(a, &n, vitri);
                break;
            }
            case 6: {
                char chon;
                printf("\n--- MENU SAP XEP ---\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Chon: ");
                scanf(" %c", &chon);
                if (chon == 'a') sapXepGiam(a, n);
                else if (chon == 'b') sapXepTang(a, n);
                else printf("Lua chon khong hop le!\n");
                break;
            }
            case 7: {
                char chon;
                int x, kq;
                printf("\n--- MENU TIM KIEM ---\n");
                printf("a. Tuyen tinh\n");
                printf("b. Nhi phan\n");
                printf("Chon: ");
                scanf(" %c", &chon);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);

                if (chon == 'a') {
                    kq = timKiemTuyenTinh(a, n, x);
                } else if (chon == 'b') {
                    kq = timKiemNhiPhan(a, n, x);
                } else {
                    printf("Lua chon khong hop le!\n");
                    break;
                }

                if (kq == -1)
                    printf("Khong tim thay %d trong mang!\n", x);
                else
                    printf("Tim thay %d tai vi tri %d\n", x, kq);
                break;
            }
            case 8:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 8);

    return 0;
}
void nhapMang(int a[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void themPhanTu(int a[], int *n, int vitri, int giatri) {
    if (vitri < 0 || vitri > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > vitri; i--)
        a[i] = a[i - 1];
    a[vitri] = giatri;
    (*n)++;
}

void suaPhanTu(int a[], int n, int vitri, int giatri) {
    if (vitri < 0 || vitri >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    a[vitri] = giatri;
}

void xoaPhanTu(int a[], int *n, int vitri) {
    if (vitri < 0 || vitri >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = vitri; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    printf("Da sap xep tang dan!\n");
}

void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    printf("Da sap xep giam dan!\n");
}

int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x) return i;
    return -1;
}

int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
