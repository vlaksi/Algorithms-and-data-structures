<h1 align = "center"> Breadth-First Search </h1>

## Breadth-First Search (BFS) 

The main tripping point is the (**false**) assumption that BFS is recursive. It's not. Instead, it uses a **queue(FIFO)**. 
In BFS, node a visits ***each of a's neighbors before*** visiting any of their neighbors. You can think of this as searching level by level out from A.
```sh
1   void search(Node root) { 
2     Queue queue = new Queue(); 
3     root.marked = true; 
4     queue.enqueue(root);        // Add to the end of queue 
5 
6     while (!queue.isEmpty()) { 
7       Node r = queue.dequeue(); // Remove from the front of the queue 
8       visit(r); 
9       foreach (Node n in r.adjacent) { 
10          if (n.marked == false) { 
11            n.marked = true; 
12            queue.enqueue(n); 
13          } 
14      } 
15    } 
16 }
```
The key thing to remember is the use of the ***queue***.

### DFS & BFS animation
<p align="center">

  <img  src="https://miro.medium.com/max/1280/0*miG6xdyYzdvrB67S.gif">

</p>
