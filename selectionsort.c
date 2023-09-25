 //Selection sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int *arr,int *size);

int main()
{
    clock_t start, end;
    double time;
    printf("-----SELECTION SORT--------\n");
    int size, arr[500000], num;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        num = (rand()%10000);
        arr[i] = num;
    }
    start = clock();
    selectionSort(arr,&size);
    end = clock();
    printf("\nSORTED ARRAY\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n\n");
    time=((double)(end-start)*1000) / CLOCKS_PER_SEC;
    printf("Time=%lf mili", time);
}

void swap(int *first,int *second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second=temp;
}

void selectionSort(int *arr,int *size)
{
    int temp,counter=0;
    while (counter<*size)
    {
        for (int i = counter; i < *size; i++)
        {
            if(arr[counter]>arr[i])
            {
                temp=arr[counter];
                arr[counter]=arr[i];
                arr[i]=temp;
            }
        }
        counter++;
    }
}
