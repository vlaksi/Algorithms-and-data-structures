<h1 align = "center"> Trees </h1>

## Types of Trees 

A nice way to understand a tree is with a recursive explanation. A tree is a data structure composed of nodes. 
  - Each tree has a root node. 
  - The root node has zero or more child nodes. 
  - Each child node has zero or more child nodes, and so on

## Trees vs. Binary Trees vs. Binary Search Tree 
A binary tree is a tree in which each node has up to two children. Not all trees are binary trees. A binary search tree is a binary tree in which every node fits a specific ordering property: all left descendents <= n < all right descendents. This must be true for each node n. 
<br><br>
Note that this inequality must be true for all of a node's descendents, not just its immediate children. The following tree on the left below is a binary search tree. The tree on the right is not, since 12 is to the left of 8. 

<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76126937-b881c400-6000-11ea-9fb3-bff888df13ca.png">

</p>

## Complete Binary Trees 
A complete binary tree is a binary tree in which every level of the tree is fully filled, except for perhaps the last level. To the extent that the last level is filled, it is filled left to right. 
<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76127215-7016d600-6001-11ea-826b-cbebd3b40db4.png">

</p>

## Full Binary Trees 
A full binary tree is a binary tree in which every node has either zero or two children. That is, no nodes have only one child. 
<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76127304-a0f70b00-6001-11ea-81fa-941643355ed8.png">

</p>

<h1 align = "center"> Binary Tree Traversal </h1>

Prior to your interview, you should be comfortable implementing in-order, post-order, and pre-order traversal. The most common of these is ***in-order traversal***. 

## In-order Traversal
In-order traversal means to "visit" (often, print) the **left** branch, then the **current** node, and finally, the **right** branch. Typically, for *binary search tree* , we can retrieve all the data in sorted order using *in-order traversal*. 
  ```sh
1 void inOrderTraversal(TreeNode node) { 
2   if (node != null) { 
3     inOrderTraversal(node.left); 
4     visit(node);
5     inOrderTraversal(node.right); 
6   } 
7 } 
```
When performed on a *binary search tree*, it visits the nodes in ascending order (hence the name "**in-order**"). 


## Pre-order Traversal
Pre-order traversal is to visit the **root** first. Then traverse the **left** subtree. Finally, traverse the **right** subtree. Pre-order traversal visits the **current** node **before** its **child** nodes (hence the name "pre-order"). 
  ```sh
1 void preOrderTraversal(TreeNode node) { 
2   if (node != null) { 
3     visit (node); 
4     preOrderTraversal(node.left); 
5     preOrderTraversal(node.right); 
6   } 
7 } 
```
In a pre-order traversal, the root is always the first node visited.


## Post-order Traversal
Post-order traversal is to traverse the **left** subtree first. Then traverse the **right** subtree. Finally, visit the **root**. Post-order traversal visits the **current** node **after** its **child** nodes (hence the name "post-order"). 
  ```sh
1 void postOrderTraversal(TreeNode node) { 
2   if (node != null) { 
3     postOrderTraversal(node.left);
4     postOrderTraversal(node.right); 
5     visit(node);
6   } 
7 } 
```
In a post-order traversal, the root is always the last node visited




## Tries (Prefix Trees) 
A trie is a variant of an n-ary tree in which ***characters*** are stored at each node. Each path down the tree may represent a word. The * nodes (sometimes called "null nodes") are often used to indicate complete words. For example, the fact that there is a * node under MANY indicates that MANY is a complete word. The existence of the MA path indicates there are words that start with MA. <br><br>
The actual implementation of these * nodes might be a special type of child (such as a TerminatingTrieNode, which inherits from TrieNode). Or, we could use just a boolean flag terminates within the "parent" node. <br><br>
A node in a trie could have anywhere from 1 through ALPHABET_SIZE + 1 children (or, 0 through ALPHABET_SIZE if a boolean flag is used instead of a * node). 
<p align="center">

  <img width="600" height="175" src="https://user-images.githubusercontent.com/45834270/76141120-9c623f00-6061-11ea-8aad-dbba455c2b03.png">

</p>
