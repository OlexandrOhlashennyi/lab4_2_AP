#include <stdio.h>
#include <stdlib.h>
#define N 10

bool check_min_recursive(double*, double*);
void delete_recursive(double*, double*, int*, int, int);
void deleterows(double[][N], int*, int, int);
void inp_matrix(double*, int*, int*, int);
void inp_matrix_elements(double*, int, int, int);
void inp_array_elements(double*, int);
void print_matrix(double*, int, int, int, const char[]);
void print_matrix_elements(double*, int, int, int);
void print_array_elements(double*, int);
void shift(double*, double*, int);

int counter;

int main() {
    system("chcp 1251"); system("cls");
    double matrix[N][N];
    int Rn, Cn;

    inp_matrix(*matrix, &Rn, &Cn, N);
    print_matrix(*matrix, Rn, Cn, N, "Введена");

    deleterows(matrix, &Rn, Cn, N);
    print_matrix(*matrix, Rn, Cn, N, "Відредагована");

    return 0;
}

void deleterows(double arr[][N], int *Rn, int Cn, int row_len) {
    delete_recursive(*arr, *(arr+*Rn-1), Rn, Cn, row_len);
}

void delete_recursive(double* first, double* ptr, int* Rn, int Cn, int row_len) {
    if (first > ptr) return;
    if (!check_min_recursive(ptr, ptr + Cn-1)) {
        shift(ptr, first + (*Rn)-- * row_len, row_len);
    }
    return delete_recursive(first, ptr - row_len, Rn, Cn, row_len);
}

bool check_min_recursive(double* ptr, double* last) {
    printf("%d\n", counter++);
    if (*ptr < *last) return 0;
    if (ptr == last) return 1;
    return check_min_recursive(ptr + 1, last);
}

void shift(double* arr, double* last, int row_len) {
    if (arr >= last) return;
    *arr = *(arr + row_len);
    return shift(arr+1, last, row_len);
}

void inp_matrix(double* arr, int* Rn, int* Cn, int n) {
    int i, j;
    printf("Введіть розмірність матриці(а,b < %d): ", n);
    scanf_s("%d%d", Rn, Cn);
    printf("Вводьте елементи матриці:\n");
    inp_matrix_elements(arr, *Rn, *Cn, n);
}

void inp_matrix_elements(double* arr, int Rn, int Cn, int n) {
    if (Rn == 0) return;
    inp_array_elements(arr, Cn);
    inp_matrix_elements(arr + n, Rn - 1, Cn, n);
}

void inp_array_elements(double* arr, int Cn) {
    if (Cn == 0) return;
    scanf_s("%lf", arr);
    inp_array_elements(arr+1, Cn-1);
}

void print_matrix(double* arr, int Rn, int Cn, int n, const char s[]) {
    printf("\n%s матриця:\n", s);
    print_matrix_elements(arr, Rn, Cn, n);
}

void print_matrix_elements(double* arr, int Rn, int Cn, int n) {
    if (Rn == 0) return;
    print_array_elements(arr, Cn);
    printf("\n");
    print_matrix_elements(arr + n, Rn - 1, Cn, n);
}

void print_array_elements(double* arr, int Cn) {
    if (Cn == 0) return;
    printf("%6.2lf ", *arr);
    print_array_elements(arr + 1, Cn - 1);
}


/*4 3
2 3 1
5 6 9
1 2 3
9 8 4

3 4
1.26 65 4.7 2.99
2.54 47 5.1 1.7
15.56 4 7.6 9.3

5 5
4 5 6 8 7
9 5 6 4 1
1 5 6 7 2
3 5 7 9 1
1 5 9 5 3
*/