#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void *MinHeapify(int arr[], int i, int n)
{
    int smallest = i;
    if ((2 * i + 1 < n) && arr[smallest] > arr[2 * i + 1])
        smallest = 2 * i + 1;
    if ((2 * i + 2 < n) && arr[smallest] > arr[2 * i + 2])
        smallest = 2 * i + 2;
    if (i != smallest)
    {
        swap(&arr[smallest], &arr[i]);
        MinHeapify(arr, smallest, n);
    }
}

void *MaxHeapify(int arr[], int i, int n)
{
    int largest = i;
    if ((2 * i + 1) < n && arr[2 * i + 1] > arr[largest])
        largest = 2 * i + 1;
    if ((2 * i + 1) < n && arr[2 * i + 2] > arr[largest])
        largest = 2 * i + 2;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        MaxHeapify(arr, largest, n);
    }
}

void *BuildMaxHeap(int arr[], int n)
{
    int i;
    for (i = n / 2; i >= 0; i--)
        MaxHeapify(arr, i, n);
}

void *BuildMinHeap(int arr[], int n)
{
    int i;
    for (i = n / 2; i >= 0; i--)
        MinHeapify(arr, i, n);
}

int CheckMax(int arr[], int i, int n)
{
    if (2 * i + 1 >= n)
        return 1;
    else if (2 *i + 2 == n && arr[i] >= arr[2 * i + 1])
        return 1;
    else if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2])
        return 1;
    else
        return 0;
}

int CheckMaxHeap(int arr[], int n)
{
    int i, f;
    for (i = 0; i < n; i++)
    {
        f = CheckMax(arr, i, n);
        if (f == 0)
        {
            return 0;
        }
    }
    if (f == 1)
        return 1;;
}

int CheckMin(int arr[], int i, int n)
{
    int flag = 0;
    if (2 * i + 1 >= n)
        return 1;
    else if (2 *i + 2 == n && arr[i] <= arr[2 * i + 1])
        return 1;
    else if (arr[i] <= arr[2 * i + 1] && arr[i] <= arr[2 * i + 2])
        return 1;
    else
        return 0;
}
int CheckMinHeap(int arr[], int n)
{
    int i, f;
    for (i = 0; i < n; i++)
    {
        f = CheckMin(arr, i, n);
        if (f == 0)
        {
            return 0;
        }
    }
    if (f == 1)
        return 1;;
}


int main()
{
    int i, n=0, arr[100], x, y;
    printf("Enter the elements :");
    do 
	{
        scanf("%d", &arr[n]);
        n=n+1;
    } while (getchar() != '\n' && n< 100);
	arr[n];
    x=CheckMaxHeap(arr, n);
    if(1==x)
    {
        printf("Given heap is a max-heap\n");
        BuildMinHeap(arr,n);
        printf("Min heap is: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        y=CheckMinHeap(arr,n);
        if(1==y)
        {
            printf("Given heap is a min-heap\n");
            BuildMaxHeap(arr,n);
            printf("Max heap is: ");
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
        }
        else
            printf("Given heap is neither min-heap nor max heap");
    }  
    return 0;
}