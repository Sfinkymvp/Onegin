#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int len = 10;
    int arr[len] = {1, -5, 2, 12, 1342, 9, 1292, -234, -34, 22};

    for (int i = len - 1; i > 0; i--) {
        int swap_count = 0;

        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
                swap_count++;
            }

        if (!swap_count)
            break;
    }

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
