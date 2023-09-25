//merge sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 500000
int a[MAX];
void merge_sort(int a[],int low,int high);
void merge(int a[],int low,int high,int mid);
int main()
{
	int n,i,randNum;
	double time,start,end;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		randNum=(rand()%1000);
		a[i]=randNum;
		printf("%d \t",a[i]);
	}
	start=clock();
	merge_sort(a,0,n-1);
	end=clock();
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
	time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
	printf("\nTime=%lf milli seconds",time);
}
void merge(int a[],int low,int high ,int mid)
{
	int i=low,j=mid+1,k,temp[500000];
	for (k=low;k<=high;k++)
	{
		if(i>mid)
		{
			temp[k]=a[j];
			j++;
		}
		else if(j>high)
		{
			temp[k]=a[i];
			i++;
		}
		else if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
		}
		else
		{
			temp[k]=a[j];
			j++;
		}
	}
	for(k=low;k<=high;k++)
	{
		a[k]=temp[k];
	}
}
void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high,mid);
	}
}
