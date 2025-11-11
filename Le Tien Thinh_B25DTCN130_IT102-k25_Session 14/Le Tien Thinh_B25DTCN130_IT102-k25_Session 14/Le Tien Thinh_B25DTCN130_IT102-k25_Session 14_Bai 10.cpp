#include <stdio.h>

void inputArray(int arr[], int *n);
void outputArray(int arr[], int n);
void insertElement(int arr[], int *n, int pos, int value);
void editElement(int arr[], int n, int pos, int value);
void deleteElement(int arr[], int *n, int pos);
void sortAscending(int arr[], int n);
void sortDescending(int arr[], int n);
int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int n, int x);

int main() {
    int arr[100];
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
                inputArray(arr, &n);
                break;

            case 2:
                outputArray(arr, n);
                break;

            case 3: {
                int pos, value;
                printf("Nhap vi tri can chen: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can chen: ");
                scanf("%d", &value);
                insertElement(arr, &n, pos, value);
                break;
            }

            case 4: {
                int pos, value;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                editElement(arr, n, pos, value);
                break;
            }

            case 5: {
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            }

            case 6: {
                char option;
                printf("\n--- MENU SAP XEP ---\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Chon: ");
                scanf(" %c", &option);
                if (option == 'a') sortDescending(arr, n);
                else if (option == 'b') sortAscending(arr, n);
                else printf("Lua chon khong hop le!\n");
                break;
            }

            case 7: {
                char option;
                int x, result;

                printf("\n--- MENU TIM KIEM ---\n");
                printf("a. Tuyen tinh\n");
                printf("b. Nhi phan\n");
                printf("Chon: ");
                scanf(" %c", &option);

                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);

                if (option == 'a') {
                    result = linearSearch(arr, n, x);
                } else if (option == 'b') {
                    result = binarySearch(arr, n, x);
                } else {
                    printf("Lua chon khong hop le!\n");
                    break;
                }

                if (result == -1)
                    printf("Khong tim thay %d trong mang!\n", x);
                else
                    printf("Tim thay %d tai vi tri %d\n", x, result);
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

void inputArray(int arr[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void outputArray(int arr[], int n) {
    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void editElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    arr[pos] = value;
}

void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    printf("Da sap xep tang dan!\n");
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    printf("Da sap xep giam dan!\n");
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x) return i;
    return -1;
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
