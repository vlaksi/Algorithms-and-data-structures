<h1 align = "center"> Depth-First Search </h1>

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

<br><br>

### DFS & BFS animation
<p align="center">

  <img  src="https://miro.medium.com/max/1280/0*miG6xdyYzdvrB67S.gif">

</p>
