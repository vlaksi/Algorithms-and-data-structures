/* Iterative implementation of BinarySearch */
#include <stdio.h>

/*
    param:
    A - our array for searching
    n - size of array A
    x - element which we want to find

    return: index of element x in array A ( if it's found)
*/
int binarySearch(int A[], int n, int x)
{

    int low = 0, high = n - 1;              // low, mid, high represent index of array
    while (low <= high)
    {
        int mid = low + (high - low) / 2;   // (low+high) may overflow, because of that we do not use simple "(low+high)/2" to get mid
        
        if (x == A[mid]) return mid;        // found X, return (exit)
        else if(x < A[mid]) high = mid-1;   // X lies before mid
        else low = mid + 1;                 // X lies after mid
    
    }

    return -1;                              // X is not found so return -1
}

int main()
{
    int A[] = { 2, 4, 5, 7, 9, 13, 19, 29};
    printf("Enter a number: ");
    int x; scanf("%d", &x);

    int index = binarySearch(A, 8,x);

    (index != -1) ? printf("Number %d is at index %d", x, index) : printf("Number %d not found", x);

}