#include "stdio.h"
int cmpCount=0;
int partition(int arr[], int start, int end)
{
    int pivot = arr[end]; // 选择最后一个元素作为基准
    int i = start - 1;
    int j = start;
    while (j < end)
    {
        cmpCount=cmpCount+1;
        if (arr[j] < pivot)
        {
            i = i + 1;
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j = j + 1;
    }

    // 将基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 2] = arr[end];
    arr[end] = temp;

    return i + 1; // 返回基准元素的最终位置
}

int qsort(int arr[] , int start, int end)
{
    if (start < end)
    {
        int pivotIndex =  partition(arr, start, end);
        qsort(arr, start, pivotIndex - 1);
        qsort(arr, pivotIndex + 1, end);
    }
}

int main()
{
    int arr[]  = { 100000,99, 0, 98, 1, 97, 2, 96, 3, 1 };
    int arrLength=10;
    int end = arrLength - 1;
    
    qsort(arr, 0, end);
    printf("sorted array:");
    for(int i=0;i<arrLength;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("cmpCount:%d\n",cmpCount);
}