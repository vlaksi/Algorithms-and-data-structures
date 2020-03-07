<h1 align = "center"> Graphs </h1>

A tree is actually a type of graph, but not all graphs are trees. Simply put, a tree is a connected graph without cycles. A graph is simply a ***collection of nodes with edges between*** (*some of*) them. 
  - Graphs can be either ***directed*** (like the following graph) or ***undirected***. While *directed* edges are like a *one-way* street, *undirected* edges are like a *two-way* street. 
  - The graph might consist of multiple isolated subgraphs. lf there is a path between every pair of vertices, it is called a "connected graph" 
  - The graph can also have cycles (or not). An "acyclic graph" is one without cycles. 
In terms of programming, there are two common ways to represent a graph : **Adjacency List** and **Adjacency Matrices**

## Adjacency List 
This is the most common way to represent a graph. Every ***vertex*** (or node) stores a *list* of **adjacent vertices**. In an undirected graph, an edge like (a, b) would be stored twice: once in a's adjacent vertices and once in b's adjacent vertices. A simple class definition for a graph node could look essentially the same as a tree node. 

  ```sh
1   class Graph { 
2     public Node[] nodes; 
3   } 
4 
5   class Node { 
6     public String name; 
7     public Node [] children; 
8   }
```
The Graph class is used because, unlike in a tree, you can't necessarily reach all the nodes from a single node. 

## Adjacency Matrices 
An adjacency matrix is an NxN boolean matrix (where N is the number of nodes), where a **true** value at matrix[i][j] indicates an **edge** from node i to node j . (You can also use an integer matrix with Os and 1 s.) 
In an *undirected* graph, an adjacency matrix will be *symmetric*. In a directed graph, it will not (necessarily) be

<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76141710-3973a680-6067-11ea-8c0d-c08097179319.png">

</p>
The same graph algorithms that are used on adjacency lists (breadth-first search, etc.) can be performed with adjacency matrices, but they may be somewhat less efficient. In the adjacency list representation, you can easily iterate through the neighbors of a node. In the adjacency matrix representation, you will need to iterate through all the nodes to identify a node's neighbors. 


<h1 align = "center"> Graph Search </h1>

The two most common ways to search a graph are ***depth-first search*** and ***breadth-first search***. <br><br>
In ***depth-first search (DFS)***, we start at the ***root*** (or another arbitrarily selected node) and explore ***each branch completely*** before moving on to the next branch. That is, we go deep first (hence the name depthfirst search) before we go wide. <br><br>
In ***breadth-first search (BFS)***, we start at the ***root*** (or another arbitrarily selected node) and explore ***each neighbor*** before going on to any of their children. That is, we go wide (hence breadth-first search) before we go deep.
<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76141814-0d0c5a00-6068-11ea-975c-d19ae023eaa9.png">

</p>

Breadth-first search and depth-first search tend to be used in different scenarios. ***DFS*** is often preferred if we want to *visit* ***every node*** in the graph. Both will work just fine, but depth-first search is a bit simpler. However, if we want to find the ***shortest path*** (or just any path) ***between two nodes***, ***BFS*** is generally better

## Depth-First Search (DFS) 
In DFS, we *visit a node* A and then iterate through each of A's *neighbors*. When visiting a node B that is a neighbor of A, we visit all of B's neighbors before going on to A's other neighbors. That is, a exhaustively searches B's branch before any of its other neighbors. <br><br>
Note that pre-order and other forms of tree traversal are a form of DFS. The key difference is that when implementing this algorithm for a graph, we must check if the ***node has been visited***. If we don't, we risk getting stuck in an infinite loop. 
The pseudocode below implements DFS. 
```sh
1   void search(Node root) { 
2     if (root == null) return; 
3     visit(root); 
4     root.visited = true; 
5     for each (Node n in root.adjacent) { 
6       if (n.visited == false) { 
7         search(n); 
8       } 
9     } 
10  }
```

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
## Bidirectional Search 
Bidirectional search is used to find the ***shortest path*** between a *source* and *destination node*. It operates by essentially running ***two simultaneous breadth-first searches***, one from each node. When their searches collide, we have found a path. 

<p align="center">

  <img width="700" height="220" src="https://user-images.githubusercontent.com/45834270/76142104-c2d8a800-606a-11ea-80b2-48c6366b3e7c.png">

</p>


