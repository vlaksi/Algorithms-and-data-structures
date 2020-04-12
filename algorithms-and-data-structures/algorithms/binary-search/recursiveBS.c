/* Recursive implementation of BinarySearch */
#include <stdio.h>

/*
    param:
    A - our array/subarray for searching
    low -  index of begin of subarray A
    high - index of end of subbaray A

    return: index of element x in array A ( if it's found)
*/
int binarySearch(int A[], int low, int high,int x)
{
    if ( low > high) return -1;                 // base condition [condition when we break our recursion]
    
    int mid = low + (high - low)/2;             // (low+high) may overflow, because of that we do not use simple "(low+high)/2" to get mid

    if( x == A[mid] ) return mid;               // base condition
    else if( x < A[mid] ) return binarySearch(A, low, mid-1, x);
    else return binarySearch(A, mid+1, high, x);

}

int main()
{
    int A[] = { 2, 4, 5, 7, 9, 13, 19, 29};
    printf("Enter a number: ");
    int x; scanf("%d", &x);

    int index = binarySearch(A,0,8, x);

    (index != -1) ? printf("Number %d is at index %d", x, index) : printf("Number %d not found", x);

}