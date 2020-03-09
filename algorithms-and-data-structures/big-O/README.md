<h1 align = "center"> Big O </h1>

Big 0 time is the language and metric we use to describe the efficiency of algorithms. We need to know the difference between **Time Complexity** and **Space Complexity**<br><br>
## Time Complexity
Some of the most common one's runtimes are **O(log N),O(N log N), O(N), O(N^2) and O(2^N)**. There's no fixed list of possible runtimes, though. <br><br>

You can also have multiple variables in your runtime. For example, the time to paint a fence that's w meters wide and h meters high could be described as O( wh) .If you needed p layers of paint, then you could say that the time is O(whp).<br><br>
We will use big O in the way that industry tends to use it: By always trying to offer the tightest description of the runtime.

## Space Complexity
Time is not the only thing that matters in an algorithm. We might also care about the **amount of memoryor space**- required by an algorithm. <br>
Space complexity is a parallel concept to time complexity. If we need to create an array of size n, this will require O(n) space. If we need a two-dimensional array of size nxn, this will require O(n^2) space. *Stack space* in recursive calls counts, too. For example, code like this would take O(n) time and O(n) space.
```sh
1   int sum(int n) { 
2       if (n <= a) { 
3           return B; 
4       } 
5       return n + sum(n-1); 
6    } 
```
Each call adds a level to the stack.
```sh
1   sum(4) 
2       -> sum(3) 
3           -> sum(2) 
4               -> sum(l) 
5                   -> sum(0) 
```
Each of these calls is added to the call stack and takes up actual memory. 

However, just because you have n calls total doesn't mean it takes O(n) space. Consider the below function, which adds adjacent elements between 0 and n:
```sh
1   int pairSumSequence(int n) { /* Ex 2.*/ 
2       int sum = 0; 
3       for (int i = 0; i < n; i++) { 
4           sum += pairSum(i, i + l); 
5       } 
6       return sum; 
7    } 
8 
9   int pairSum(int a, int b) {
10      return a + b; 
11  }
```
There will be roughly O(n) calls to pairSum. However, those calls do not exist simultaneously on the ***call stack***, so you only need O(1) space.
<br><br>
### Common big O
The following graph depicts the rate of increase for some of the common big 0 times. 
<p align="center">

  <img width="700" height="301" src="https://user-images.githubusercontent.com/45834270/76262700-5e316f00-625d-11ea-8494-24a623173de3.png">

</p>

## Log N Runtimes
We commonly see O( log N) in runtimes. Where does this come from? Let's look at binary search as an example. In binary search, we are looking for an example x in an N-element sorted array. We first compare x to the midpoint of the array. If x == middle, then we return. If x < middle, then we search on the left side of the array. If x > middle, then we search on the right side of the array. 
```sh
  search 9 within {1, 5, 8, 9, 11, 13, 15, 19, 21}
    compare 9 to 11 -> smaller. 
    search 9 within {1, 5, 8, 9, 11} 
      compare 9 to 8 -> bigger 
      search 9 within {9, 11} 
        compare 9 to 9 
        return
```
We start off with an N-element array to search. Then, after a single step, we're down to N/2 elements. One more step, and we're down to X elements. We stop when we either find the value or we're down to just one element.<br>
The total runtime is then a matter of how many steps (dividing N by 2 each time) we can take until N becomes 1. 
<br><br>
When you see a problem where the number of elements in the problem space gets ***halved each time***, that will likely be a ***O(log N)*** runtime. <br><br>
This is the same reason why finding an element in a *balanced binary search tree* is *O(log N)*. With each comparison, we go either left or right. *Half the nodes* are on each side, so we cut the problem space in half each time.
<br>
What's the base of the log? The short answer is that it doesn't matter for big O because it is constant. 

## Recursive Runtimes 
Runtime of this code is not O(N^2) !
```sh
1   int f(int n) { 
2     if (n <= 1) { 
3       return 1; 
4     } 
5   return f(n - 1) + f(n - 1); 
6 }
```
Rather than making assumptions, let's derive the runtime by walking through the code. Suppose we call f (4). This calls f( 3) twice. Each of those calls to f (3) calls f( 2), until we get down to f (1).
<p align="center">

  <img width="700" height="200" src="https://user-images.githubusercontent.com/45834270/76264907-65f41200-6263-11ea-9002-49a6877391c5.png">

</p>

The tree will have **depth N**. Each node (Le., function call) has two children. Therefore, each level will have twice as many calls as the one above it. The number of nodes on each level is: 
<p align="center">

  <img width="700" height="200" src="https://user-images.githubusercontent.com/45834270/76265010-afdcf800-6263-11ea-92a4-6a06f3efb2b9.png">

</p>

<br>

When you have a **recursive function** that makes ***multiple calls***, the runtime will often (but **not always**) look like ***O(branches^depth)***, where branches is the number of times each recursive **call branches**. In this case, this gives us O(2^N) 

<br>

The ***space complexity*** of this algorithm will be O(N). Although we have O(2^N) nodes in the tree total, only *O(N) exist at any given time*. Therefore, we would only need to have O(N) memory available. 


