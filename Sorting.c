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
    
    return 0;
}
