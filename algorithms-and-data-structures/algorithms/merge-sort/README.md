<h1 align = "center"> Merge sort </h1>

## Divide-and-Conquer
Merge-sort and quick-sort, use **recursion** in an algorithmic *design pattern* called ***divide-and-conquer***. The divide-and-conquer pattern consists of the following three steps:
  1. ***Divide***: Divide the input data into two or more **disjoint subsets**. 
  2. ***Conquer***: Recursively **solve the subproblems** associated with the subsets. 
  3. ***Combine***: Take the solutions to the subproblems and **merge them** into a solution to the original problem
  

## Using Divide-and-Conquer for Sorting

To sort a sequence S with n elements using the three divide-and-conquer steps, the merge-sort algorithm proceeds as follows:
  1. ***Divide***: If S has zero or one element, return S immediately; it is already sorted. Otherwise (S has at least two elements), remove all the elements from S and put them into **two sequences, S1 and S2,** each containing about half of the elements of S; that is,S1 contains the ﬁrst n/2 elements of S, and S2 contains the remaining n/2 elements. 
  2. ***Conquer***: ***Recursively*** **sort** sequences *S1 and S2*. 
  3. ***Combine***: Put back the elements into S by **merging** the sorted sequences S1 and S2 into a sorted sequence. 


### Runtime: O( n log (n) ) | Memory: Depends. 
Merge sort ***divides the array in hal***f, ***sorts each*** of those ***halve***s, and then ***merges them*** back together. Each of those halves has the same sorting algorithm applied to it. Eventually, you are merging just two singleelement arrays. It is the "merge" part that does all the heavy lifting.

<br><br><br>

### Example 1

![Screenshot_1](https://user-images.githubusercontent.com/45834270/79042153-9b3ea780-7bf5-11ea-84b8-ae16bebba559.png)


### Example 2
<p align="center">

  <img  src="https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif">

</p>
