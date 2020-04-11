/* Merge sort in C */
#include <stdio.h>
#include <stdlib.h>

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int l,r,a;

	// l - to mark the index of left subarray (L)
	// r - to mark the index of right sub-raay (R)
	// a - to mark the index of merged subarray (A)
	l = 0; r = 0; a =0;

	while(l < leftCount && r < rightCount) {
		if(L[l]  < R[r]) A[a++] = L[l++];       // we inc our index, and put
		else A[a++] = R[r++];                   // element from L or R to A array
	}   // after this, we iterated through one of array(L or R) and he doesn't
        // have more element, so we now iterete to the end of the second array
	while(l < leftCount) A[a++] = L[l++];
	while(r < rightCount) A[a++] = R[r++];
}

// Recursive function to sort an array of integers. 
void mergeSort(int *A,int n) {

    int mid,i, *L, *R;
	if(n < 2) return;                           // base condition. If the array has less than two element, do nothing. 

    mid = n/2;                                  // find the mid index. 

    // create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 

    for(i = 0;i<mid;i++) L[i] = A[i];           // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i];       // creating right subarray

    mergeSort(L,mid);                           // sorting the left subarray
	mergeSort(R,n-mid);                         // sorting the right subarray
	merge(A,L,mid,R,n-mid);                     // Merging L and R into A as sorted list.

    free(L);                                    // clean memory, when we do not need more arrays
    free(R);
}


int main() {
	/* Code to test the MergeSort function. */
	
	int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers. 
	int i,numberOfElements;

    // finding number of elements in array as size of complete array in bytes divided by size of integer in bytes. 
	// This won't work if array is passed to the function because array
	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g  
	numberOfElements = sizeof(A)/sizeof(A[0]); 


    //printing all elements in the array wheb its not sorted.
    printf("\t----------- Not sorted array A ------------\n\t\t");
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
    printf("\n\t-------------------------------------------\n");

    // Calling merge sort to sort the array. 
	mergeSort(A,numberOfElements);

	//printing all elements in the array once its sorted.
    printf("\n\n\t---------- Now is sorted array A ----------\n\t\t");
	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
    printf("\n\t-------------------------------------------\n");
	
    return 0;

}