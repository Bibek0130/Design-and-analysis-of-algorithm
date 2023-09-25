//Randomized quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {

        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition_r(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;

    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_r(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, x, result;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n], randNum;
    for (int i = 0; i < n; i++)
    {
        randNum = rand() % n;
        arr[i] = randNum;
    }
    clock_t start, end;
    start = clock();
    int num = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, num - 1);
    end = clock();
    printf("\nTime=%lf millisec\n",
           ((double)(end - start)*1000) / CLOCKS_PER_SEC);
    return 0;
}
