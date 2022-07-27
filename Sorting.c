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
    }

    return 0;
}
