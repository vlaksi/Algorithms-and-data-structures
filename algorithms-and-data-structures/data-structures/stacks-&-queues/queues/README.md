<h1 align = "center"> Queue </h1>

## Implementing a Queue 
A queue implements FIFO (first-in first-out) ordering. As in a line or queue at a ticket stand, items are removed from the data structure in the same order that they are added.

### It uses the operations: 
  - **enqueue(item)**: Add an item to the end(back) of the list.
  - **dequeue()**: Remove the first item in the list. 
  - **peek()**: Return the top of the queue. 
  - **isEmpty()** : Return true if and only ifthe queue is empty. 
  
## Utility
One place where queues are often used is in ***breadth-first search*** or in ***implementing a cache***. <br><br>In breadth-first search, for example, we used a queue to store a list of the nodes that we need to process. Each time we process a node, we add its adjacent nodes to the back of the queue. This allows us to process nodes in the order in which they are viewed. 

## Visualization

<p align="center">
  <img height=360px src="https://user-images.githubusercontent.com/45834270/78498989-3e06aa00-774e-11ea-876a-562ec8d161db.png">
</p>