#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n)
{
    int key, j;
    for (int i=1; i<=n-1; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return;
}

int main()
{
    int arr[] = {3, 5, 7, 6, 1, 8, 2, 5};
    int n = sizeof(arr)/sizeof(int);

    // Dry Run
    // 0   1   2   3   4   5   6   7  --> Indices
    // 3 | 5   7   6   1   8   2   5  --> i = 1, key = 5, j = 0
    // arr[0] < key - No change

    // 3   5 | 7   6   1   8   2   5  --> i = 2, key = 7, j = 1
    // arr[1] < key - No change

    // 3   5   7 | 6   1   8   2   5  --> i = 3, key = 6, j = 2
    // arr[2] > key - arr[3] = arr[2]
    // 3   5   7 | 7   1   8   2   5  --> i = 3, key = 6, j = 1
    // arr[1] < key - No change
    // Exit from while loop
    // arr[2] = key

    // 3   5   6   7 | 1   8   2   5  --> i = 4, key = 1, j = 3
    // arr[3] > key - arr[4] = arr[3]
    // 3   5   6   7 | 7   8   2   5  --> i = 4, key = 1, j = 2
    // arr[2] > key - arr[3] = arr[2]
    // 3   5   6   6 | 7   8   2   5  --> i = 4, key = 1, j = 1
    // arr[1] > key - arr[2] = arr[1]
    // 3   5   5   6 | 7   8   2   5  --> i = 4, key = 1, j = 0
    // arr[0] > key - arr[1] = arr[0]
    // 3   3   5   6 | 7   8   2   5  --> i = 4, key = 1, j = -1
    // Exit from while loop
    // arr[0] = key

    // 1   3   5   6   7 | 8   2   5  --> i = 5, key = 8, j = 4
    // arr[4] < key - No change
    
    // 1   3   5   6   7   8 | 2   5  --> i = 6, key = 2, j = 5
    // arr[5] > key - arr[6] = arr[5]
    // 1   3   5   6   7   8 | 8   5  --> i = 6, key = 2, j = 4
    // arr[4] > key - arr[5] = arr[4]
    // 1   3   5   6   7   7 | 8   5  --> i = 6, key = 2, j = 3
    // arr[3] > key - arr[4] = arr[3]
    // 1   3   5   6   6   7 | 8   5  --> i = 6, key = 2, j = 2
    // arr[2] > key - arr[3] = arr[2]
    // 1   3   5   5   6   7 | 8   5  --> i = 6, key = 2, j = 1    
    // arr[1] > key - arr[2] == arr[1]
    // 1   3   3   5   6   7 | 8   5  --> i = 6, key = 2, j = 0    
    // arr[0] < key
    // Exit from while loop
    // arr[1] = key

    // 1   2   3   5   6   7   8 | 5  --> i = 7, key = 5, j = 6
    // arr[6] > key - arr[7] = arr[6]
    // 1   2   3   5   6   7   8 | 8  --> i = 7, key = 5, j = 5
    // arr[5] > key - arr[6] = arr[5]
    // 1   2   3   5   6   7   7 | 8  --> i = 7, key = 5, j = 4
    // arr[4] > key - arr[5] = arr[4]
    // 1   2   3   5   6   6   7 | 8  --> i = 7, key = 5, j = 3
    // arr[3] = key
    // Exit from while loop 
    // arr[4] = key

    // 1   2   3   5   5   6   7   8  --> Sorted Array  

    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    
    return 0;
}