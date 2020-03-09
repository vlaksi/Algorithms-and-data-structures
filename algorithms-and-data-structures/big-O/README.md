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
