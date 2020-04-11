<h1 align = "center"> Quick sort </h1>

Like ***merge-sort***, this algorithm is also based on the ***divide-and-conquer paradigm***, but it uses this technique in a somewhat opposite manner, as all the hard work is done *before the recursive calls*. <br><br>

Despite this slow worst-case running time,quicksort is often the ***best practical choice*** for sorting because it is remarkably efﬁcient on the average: its expected running time is O(n * log(n)), and the constant factors hidden in the O(n * log(n)) notation are quite small. It also has the advantage of ***sorting in place***, and it works well even in virtual-memory environments.

## High-Level Description of Quick-Sort
The quick-sort algorithm sorts a sequence S using a simple recursive approach. The main idea is to apply the ***divide-and-conquer*** technique, whereby we divide S into subsequences, recur to sort each subsequence, and then combine the sorted subsequences by a simple concatenation. <br><br> 
In particular, the quick-sort algorithm consists of the following three steps : 
  1. ***Divide***: If S has at least two elements (nothing needs to be done if S has zero or one element), select a speciﬁc element x from S, which is called the ***pivot***. As is common practice, choose the pivot x to be the ***last element in S***. Remove all the elements from S and put them into three sequences: 
      - ***L***, storing the elements in S ***less*** than x 
      - ***E***, storing the elements in S ***equal*** to x ( if the elements of S are distinct, then E holds just one element— the pivot itself. )
      - ***G***, storing the elements in S ***greater*** than x 
  2. ***Conquer***: Recursively ***sort sequences*** L and G. 
  3. ***Combine***:  Put back the elements into S inorder by ﬁrst inserting the elements of L, then those of E, and ﬁnally those of G.



### Quick sort animation
<p align="center">

  <img  src="https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif">

</p>

### Runtime: O(n*log(n)) average, O(n^2) worst case. Memory: O(log(n)) . 

In quick sort, we **pick** a random **element**(i use most right element) and ***partition*** the array, such that all numbers that are ***less*** than the partitioning element come ***before*** all elements that are ***greater*** than it. The partitioning can be performed efficiently through a series of swaps.
<br><br>
If we repeatedly partition the array (and its sub-arrays) around an element, the array will eventually become sorted. However, as the ***partitioned element is not guaranteed to be the median*** (or anywhere near the median), our sorting could be very slow. This is the reason for the O(n^2) worst case runtime. 




### Quick sort Partition animation
<p align="center">

  <img  src="https://thumbs.gfycat.com/PleasantCloseEyelashpitviper-size_restricted.gif">

</p>


If you want you can watch [video-explanation](https://www.youtube.com/watch?v=COk73cpQbFQ&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=7) about quick-sort algorithm.


