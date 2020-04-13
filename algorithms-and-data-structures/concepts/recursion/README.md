<h1 align = "center"> Recursion </h1>

While there are a large number of recursive problems, many follow *similar patterns*. A good hint that a problem is recursive is that it can be built off of ***subproblems***<br><br> 
When you hear a problem beginning with the following statements, it's often (though not always) a good candidate for recursion: "Design an algorithm to compute the nth ...", "Write code to list the first n ... ", "Implement a method to compute all..", and so on. And because of that the more problems you do, the easier it will be to recognize recursive problems. 

<p align="center">

  <img  src="https://upload.wikimedia.org/wikipedia/commons/1/1a/Fibonacci_call_tree_5.gif">

</p>



## How to Approach 
Recursive solutions, by definition, are built off of ***solutions to subproblems***. Many times, this will mean simply to compute f(n) by adding something, removing something, or otherwise changing the solution for f(n-1). In other cases, you might solve the problem for the ***first hal***f of the data set, then the ***second half***, and then ***merge*** those results. <br><br>
There are many ways you might divide a problem into subproblems. Three of the most common approaches to develop an algorithm are ***bottom-up, top-down, and half-and-half***. 

### Bottom-Up Approach 

The bottom-up approach is often the most intuitive. We start with knowing how to solve the problem for ***a simple case***, like a list with only one element. Then we figure out how to solve the problem for ***two elements***, then for ***three elements***, and ***so on***. The key here is to think about how you can build the solution for ***one case off of the previous case*** (or multiple previous cases). 

### Top-Down Approach 
The top-down approach can be more complex since it's less concrete. But sometimes, it's the best way to think about the problem. 
In these problems, we think about how we can ***divide the problem*** for case N ***into subproblems***. 
Be careful of overlap between the cases. 

### Half-and-Half Approach 
In addition to top-down and bottom-up approaches, it's often effective to ***divide the data set in half***. 
For example, ***binary search*** works with a "half-and-half" approach. When we look for an element in a sorted array, we first figure out which half of the array contains the value. Then we recurse and search for it in that half. <br><br>
***Merge sort*** is also a "half-and-half" approach. We sort each half of the array and then merge together the sorted halves

<br>

## Recursive vs. lterative Solutions 

Recursive algorithms can be very space inefficient. Each recursive call adds a new layer to the stack, which means that if your algorithm recurses to a depth of n, it uses at least O(n) memory. For this reason, it's often better to implement a recursive algorithm iteratively. <br><br>

***All recursive algorithms can be implemented iteratively***, although sometimes the code to do so is much more complex. Before diving into recursive code, ask yourself how hard it would be to implement it iteratively, and discuss the tradeoffs with yourself.
