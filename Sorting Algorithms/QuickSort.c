#include <stdio.h>
#include <stdlib.h>

void takearray(int *arr, int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        printf("Element[%d]: ",i);
        scanf("%d",arr+i);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pivot(int arr[], int low, int high)
{
    int piv = arr[low], i=low, j=high;
    while (i<j) // when i>j or i==j it would mean the array is of unit length which means it is always sorted. 
    {
        while (arr[i]<=piv && i<=high-1)
        {
            i++;
        }
        while(arr[j]>piv && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int piv=pivot(arr,low,high);
        quickSort(arr,low,piv-1);
        quickSort(arr,piv+1,high); 
    }
    else
    {
        return;
    }
}

void printArray(int arr[], int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size=8;
    int *arr = (int*)malloc(sizeof(int)*size);
    takearray(arr,size);
    quickSort(arr,0,size-1);
    printArray(arr,size);
    return 0;
}