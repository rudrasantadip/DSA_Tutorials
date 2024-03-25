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

void printArray(int arr[], int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int size)
{
    int i=0,j;
    for(i=0;i<size;i++)
    {
        j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(&arr[j-1],&arr[j]);
            j--;
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int *arr=(int*)malloc(sizeof(int)*size);
    takearray(arr,size);
    selectionSort(arr,size);
    printArray(arr,size);


}