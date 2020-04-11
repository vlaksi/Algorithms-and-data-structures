/* 
    Quick Sort implementation in C++  
    I am using most right element of array like pivot.
*/

#include <iostream>

using namespace std;

int partition(int *A, int start, int end){
    int pivot = A[end];
    int partitionIndex = start;             // set partition index as start initially

    for(int i = start; i < end; i++){
        if(A[i] <= pivot){
            swap(A[i], A[partitionIndex]);  // swap if element is lesser than pivot
            partitionIndex++;
        }
    }

    swap(A[partitionIndex], A[end]);        // swap pivot with element at partition index
    return partitionIndex;
}

int quickSort(int *A, int start, int end){
    if(start < end){
        int partitionIndex = partition(A, start, end);  // calling partition
        
        quickSort(A, start, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, end);
    }
    
}


int main(){
    
    int A[] = {7, 6, 5, 4, 3, 2, 1, 10, 0};
    
    //printing all elements in the array wheb its not sorted.
	cout << "\n\t----------- Not sorted array A ------------\n\t\t    ";
	for (int i = 0; i < 8; i++)
		cout << A[i] <<" ";
	cout << "\n\t-------------------------------------------\n";

    quickSort(A, 0, 7);


    //printing all elements in the array once its sorted.
    cout << "\t----------- Now sorted array A ------------\n\t\t    ";
	for (int i = 0; i < 8; i++)
		cout << A[i] <<" ";
	cout << "\n\t-------------------------------------------\n\n";

}