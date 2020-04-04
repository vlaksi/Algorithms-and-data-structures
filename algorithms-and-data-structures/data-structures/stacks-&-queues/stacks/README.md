<h1 align = "center"> Stacks </h1>

## Implementing a Stack

The stack data structure is precisely what it sounds like: a stack of data. In certain types of problems, it can be favorable to store data in a stack rather than in an array. A stack uses **LIFO** (***last-in first-out***) ordering. That is, as in a stack of dinner plates, the most recent item added to the stack is the first item to be removed. 
<br><br>

### It uses the following operations: 
  - **pop()**: Remove the top item from the stack. 
  - **push(item)**: Add an item to the top of the stack. 
  - **peek()**: Return the top of the stack. 
  - **isEmpty()**: Return true if and only if the stack is empty. 

<br><br>
Unlike an array, a stack does not offer constant-time access to the ith item. However, it does allow constanttime adds and removes, as it doesn't require shifting elements around. 


## Utility

One case where stacks are often useful is in certain ***recursive algorithms***. Sometimes you need to push temporary data onto a stack as you recurse, but then remove them as you *backtrack* (for example, because the recursive check failed). A stack offers an intuitive way to do this. <br><br>
A stack can also be used to implement a ***recursive algorithm iteratively***.

## Visualization

<p align="center">
  <img src="https://user-images.githubusercontent.com/45834270/78458537-748ee700-76b2-11ea-8987-c60ae326a2ad.png">
</p>
