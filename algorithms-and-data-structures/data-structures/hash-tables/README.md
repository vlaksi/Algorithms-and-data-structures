<h1 align = "center"> Hash Tables </h1>
 
A hash table is a data structure that maps ***keys to values*** for highly efficient lookup. There are a number of ways of implementing this. Here, we will describe a simple but common implementation. <br><br>

In this simple implementation, we use an array of linked lists and a hash code function. To insert a key (which might be a string or essentially any other data type) and value, we do the following: 
  - First, ***compute the key's hash code***, which will usually be an int or long. Note that two different keys could have the ***same hash code***, as there may be an infinite number of keys and a finite number of ints. 
  - Then, ***map the hash code to an index in the array***. This could be done with something like hash (key) % array_length. Two different hash codes could, of course, *map to the same index*.
  - At this index, ***there is a linked list of keys and values***. Store the key and value in this index. We must use a linked list because of ***collisions***: you could have two different keys with the same hash code, or two different hash codes that map to the same index. 

<br>

To retrieve the value pair by its key, you repeat this process. ***Compute the hash code from the key, and then compute the index from the hash code***. Then, search through the linked list for the value with this key. 

<br>

If the number of collisions is very high, the worst case runtime is ***O(N)***, where N is the number of keys. However, we generally assume a good implementation that keeps collisions to a minimum, in which case the lookup time is a O(1)

<p align="center">

  <img src="https://user-images.githubusercontent.com/45834270/79167031-c805e100-7de6-11ea-9de0-8a0d58981c89.png">

</p>

Alternatively, we can implement the hash table with a balanced binary search tree. This gives us an O(logN) lookup time. The advantage of this is potentially using less space, since we no longer allocate a large array. We can also iterate through the keys in order, which can be useful sometimes.


<p align = "center">
  
  <img height=500px src="https://i.pinimg.com/originals/26/71/f5/2671f5ebb8358c5347b9d9e3c65b3d50.gif">
  
</p>
