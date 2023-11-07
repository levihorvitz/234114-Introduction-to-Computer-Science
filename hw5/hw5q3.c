#include <stdio.h>
#include <stdlib.h>

void PrintLength();

void PrintArray();

void PrintSum();

void PrintExist();

void PrintDoNotExist();

void max_sort(int a[], int n);

int index_of_max(int a[], int n);

void swap(int *n, int *d);

void sum_exist(int *array, int n, int sum);

//Main function, responsible for printing and calling functions
int main() {
    int lengh, x;
    PrintLength();
    scanf("%d", &lengh);
    int *array = malloc(lengh * sizeof(int));
    if (array == NULL) {
        return -1;
    }
    PrintArray();
    for (int i = 0; i < lengh; i++) {
        scanf("%d", &array[i]);
    }
    PrintSum();
    scanf("%d", &x);
    max_sort(array, lengh);
    sum_exist(array,lengh,x);
    return 0;
}

void PrintLength() {
    printf("Please enter length:\n");
}

void PrintArray() {
    printf("Please enter array:\n");
}

void PrintSum() {
    printf("Please enter sum:\n");
}

void PrintExist() {
    printf("Such elements do exist.");
}

void PrintDoNotExist() {
    printf("Such elements do not exist.");
}

//finding the maximum index
int index_of_max(int a[], int n) {
    int i, i_max = 0;
    for (i = 1; i < n; i++)
        if (a[i] > a[i_max])
            i_max = i;
    return i_max;
}

//Switching pointers
void swap(int *n, int *d) {
    int k = *n;
    *n = *d;
    *d = k;
}

//Sort an array by finding the maximum
void max_sort(int a[], int n) {
    if (n == 1)
        return;
    int i_max = index_of_max(a, n);
    swap(&a[n - 1], &a[i_max]);
    max_sort(a, n - 1);
}

//Checks whether the amount exists in the binary search method
void sum_exist(int *array, int n, int sum) {
    if (n < 3) {
        return;
    }
    int left = 0, right = n-1, index = left +1;
    while (left < right) {
        if (array[left] + array[right] >= sum) {
            right--;
            continue;
        }
        if (index == right) {
            left++;
            index = left + 1;
            continue;
        }
        if (array[left] + array[right] + array[index] < sum){
            index++;
        } else if (array[left] + array[right] + array[index] > sum) {
            left++;
            index = left + 1;
        } else {
            PrintExist();
            return;
        }
    }
    PrintDoNotExist();
}