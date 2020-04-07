<h1 align = "center"> Heap </h1>

## Binary Heaps (Min-Heaps and Max-Heaps) 
We'll just discuss *min-heaps* here. Max-heaps are essentially equivalent, but the elements are in descending order rather than ascending order. A min-heap is a *complete binary tree* where each node is ***smaller*** than its *children*. The root, therefore, is the minimum element in the tree. We have two key operations on a min-heap: *insert and extract_min*.

### Insert 
When we insert into a min-heap, we always start by inserting the element at the bottom. We insert at the rightmost spot so as to maintain the complete tree property. 
Then, we "fix" the tree by swapping the new element with its parent, until we find an appropriate spot for the element. We essentially bubble up the minimum element. 
<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76140990-6a9ca880-6060-11ea-9bc9-5fc2b4728e84.png">

</p>
This takes 0 (log n) time, where n is the number of nodes in the heap. 


### Extract Minimum Element 

First, we remove the minimum element and *swap* it with the *last element* in the heap (the bottommost, rightmost element). Then, we bubble down this element, swapping it with one of its children until the minheap property is restored. <br><br>
Do we swap it with the left child or the right child? That depends on their values. There's no inherent ordering between the left and right element, but you'll need to take the smaller one in order to maintain the min-heap ordering. 
<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76141073-3675b780-6061-11ea-9645-a9a1ba204c7c.png">

</p>
