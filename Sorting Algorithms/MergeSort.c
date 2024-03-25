#include <stdio.h>
#include <stdlib.h>

void takearray(int *arr, int size)
{
    if(arr==NULL)
    {
        return;
    }

    int i=0;
    for(i=0;i<size;i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d",arr+i);
    }
}

void printArray(int *arr, int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        printf(" %d ", arr[i]);
    }
}

void merge(int *arr, int low, int mid, int high)
{
	int n = high-low+1, k=0;
	int A[n];
	int left=low, right = mid+1;


	while(left<=mid && right<=high)
	{
		if(arr[left]<=arr[right])
		{
			A[k]=arr[left];
			k++;
			left++;
		}
		else
		{
			A[k]=arr[right];
			k++;
			right++;
		}
	}

	while(left<=mid)
	{
		A[k]=arr[left];
		left++;
		k++;
	}
	while (right<=high)
	{
		A[k]=arr[right];
		right++;
		k++;
	}

	for(int i=low;i<=high;i++)
	{
		arr[i]=A[i-low];
	}
	

}

void mergesort(int *arr, int low, int high)
{
    int mid;
    if(low<high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int *array = (int*)malloc(sizeof(int)*10);
    takearray(array,10);
    printf("\n");
    mergesort(array,0,9);
    printArray(array,10);
	return 0;
}