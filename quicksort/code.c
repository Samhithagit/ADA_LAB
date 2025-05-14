#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main()
{
    int i, n, a[MAX], ch;
    clock_t start, end;
    
    srand(time(NULL)); // Initialize random seed

    do
    {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        // Generate random array
        for (i = 0; i < n; i++)
            a[i] = rand() % 200;

        // Display the generated array
        printf("The random generated array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");

        start = clock();
        
        // Sort the array using quicksort
        quicksort(a, 0, n - 1);

        end = clock();

        // Display the sorted array
        printf("\nThe sorted array elements are:\n");
        for (i = 0; i < n; i++)
            printf("%d\n", a[i]);

        // Calculate and display the time taken
        printf("Time taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\nDo you wish to continue (0/1)? ");
        scanf("%d", &ch);

    } while (ch);

    return 0;
}

void quicksort(int a[], int low, int high)
{
    int mid;
    
    if (low < high)
    {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int key, i, j, temp, k;
    key = a[low];
    i = low + 1;
    j = high;

    while (i <= j)
    {
        while (i <= high && key >= a[i])
            i = i + 1;
        
        while (key < a[j])
            j = j - 1;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            k = a[j];
            a[j] = a[low];
            a[low] = k;
        }
    }

    return j;
}
