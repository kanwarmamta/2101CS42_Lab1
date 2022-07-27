#include <stdio.h>

// Function to print an array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// Insertion sort Function
void insertion_sort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;
        // Comparing key value with each element on the left of it until an element smaller than it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
// function to swap the the position of two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort Function
void selection_sort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {

            // To sort in descending order, change > to < in this line.

            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // putting min number at required position
        swap(&array[min_idx], &array[step]);
    }
}
// Bubble Sort Function
void bubble_sort(int array[], int size)
{

    for (int step = 0; step < size - 1; ++step)
    {

        int swapped = 0;

        // loop to compare array elements
        for (int i = 0; i < size - step - 1; ++i)
        {

            // compare two array elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1])
            {

                // swapping
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = 1;
            }
        }

        // no swapping means the array is already sorted so no need for further comparison
        if (swapped == 0)
        {
            break;
        }
    }
}
// Merge Function for Merge Sorting
void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M, pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Merge Sort Function
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {

        // dividing array into two sub-arrays
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
// function to find the partition position
int partition(int array[], int low, int high)
{

    // selecting rightmost element as pivot
    int pivot = array[high];
    int i = (low - 1);
    // traverse each element of the array compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // swapping elements smaller than pivot by greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}
// Quick Sort Function
void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that elements smaller than pivot are on left of pivot elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quick_sort(array, low, pi - 1);

        // recursive call on the right of pivot
        quick_sort(array, pi + 1, high);
    }
}
int main(void)
{

    int n, i, j, temp, sort;
    int arr[100];
    int size = n / sizeof(arr[0]);
    // taking input values from user regarding array
    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // asking user about type of sorting to proceed
    printf(" Which type of sorting do you want to do?\n ");
    printf("Enter 1: Insertion Sort\n Enter 2: Selection Sort\n Enter 3:Bubble Sort\n Enter 4:Merge Sort\n Enter 5: Quick Sort\n");
    scanf("%d", &sort);

    printf("Unsorted Array\n");
    print_array(arr, n);
    switch (sort)
    {
    case 1:
        insertion_sort(arr, n);
        printf("Sorted array in ascending order through Insertion sort:\n");
        print_array(arr, n);
        break;
    case 2:
        selection_sort(arr, n);
        printf("Sorted array in Ascending Order through Selection Sort :\n");
        print_array(arr, n);
        break;
    case 3:
        bubble_sort(arr, n);
        printf("Sorted Array in Ascending Order through Bubble Sort:\n");
        print_array(arr, n);
        break;
    case 4:
        merge_sort(arr, 0, n - 1);
        printf("Sorted Array in Ascending Order through Merge Sort:\n");
        print_array(arr, n);
        break;
    case 5:
        quick_sort(arr, 0, n - 1);
        printf("Sorted Array in Ascending Order through Quick Sort:\n");
        print_array(arr, n);
        break;
    }

    return 0;
}
