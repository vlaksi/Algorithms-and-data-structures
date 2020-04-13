<h1 align = "center"> Dynamic programming (DP) </h1>

Dynamic programming is mostly just a matter of taking a ***recursive algorithm*** and finding the ***overlapping subproblems*** (that is, the repeated calls). You then cache those results for future recursive calls. <br> <br>
Alternatively, you can study the pattern of the recursive calls and implement something iterative. You still "cache" previous work. 


###### A note on terminology: Some people call top-down dynamic programming "memoization" and only use "dynamic programming" to refer to bottom-up work. I do not make such a distinction here. I call both dynamic programming. 

<br>

One of the simplest examples of dynamic programming is computing the nth Fibonacci number. A good way to approach such a problem is often to ***implement it as a normal recursive*** solution, and then ***add the caching part***.

## Fibonacci Numbers 
Let's walk through an approach to compute the nth Fibonacci number. 
### Recursive 
```sh
1    int fibonacci(int i) { 
2      if (i == e) return e; 
3      if (i == 1) return 1; 
4      return fibonacci(i - 1) + fibonacci(i - 2); 
5    }

```


<p align="center">

  <img  src="https://user-images.githubusercontent.com/45834270/79155646-bf56e000-7dd1-11ea-93ca-c7b1a05230b3.png">

</p>

The root node has two children. Each of those children has two children (so four children total in the "grandchildren" level). Each of those grandchildren has two children, and so on. If we do this n times, we'll have roughly O(2^n) nodes. This gives us a runtime of roughly O(2^n). 

<p align="center">

  <img  src="https://user-images.githubusercontent.com/45834270/79155975-502dbb80-7dd2-11ea-937b-194ed49d1765.png">

</p>


### Top-Down Dynamic Programming (or Memoization)

Study the recursion tree. Where do you see identical nodes?  <br><br>

There are lots of identical nodes. For example, fib(3) appears twice and fib(2) appears three times. Why should we recompute these ***from scratch each time***?<br><br> 
In fact, when we call fib(n), we shouldn't have to do much more than O(n) calls, since there's only O(n) possible values we can throw at fib. Each time we compute fib(i), we should just ***cache this result and use it later***. <br><br>
This is exactly what ***memoization*** is. With just a small modification, we can tweak this function to run in O(n) time. We simply ***cache the results*** of fibonacci(i) between calls.

```sh

1   int fibonacci(int n) { 
2     return fibonacci(n, new int[n + 1]); 
3   } 
4 
5   int fibonacci(int i, int[] memo) { 
6     if (i == e || i == 1) return i; 
7 
8     if (memo[i] == e) { 
9       memo[i] = fibonacci(i - 1, memo) + fibonacci(i - 2, memo); 
10    } 
11    return memo[i]; 
12  } 

```

While the first recursive function may take over a minute to generate the 50th Fibonacci number on a typical computer, the dynamic programming method can generate the 10,OOOth Fibonacci number in just fractions of a millisecond. (Of course, with this exact code, the int would have overflowed very early on.) <br><br>
Now, if we draw the recursion tree, it looks something like this (the black boxes represent ***cached calls*** that returned immediately):

<p align="center">

  <img  src="https://user-images.githubusercontent.com/45834270/79156625-84ee4280-7dd3-11ea-9faf-055125e751d2.png">

</p>

How many nodes are in this tree now? We might notice that the tree now just shoots straight down, to a depth of roughly n. Each node of those nodes has one other child, resulting in roughly 2n children in the tree. This gives us a runtime of ***O(n)***. 


### Bottom-Up Dynamic Programming 
We can also take this approach and implement it with bottom-up dynamic programming. Think about doing the same things as the ***recursive memoized approach, but in reverse***.<br><br> 
First, we compute fib(1) and fib(0), which are already known from the base cases. Then we use those to compute fib(2). Then we use the prior answers to compute fib (3), then fib (4), and so on

```sh
1   int fibonacci(int n) { 
2     if (n == 0) return 0; 
3     else if (n == 1) return 1; 
4 
5     int[] memo new int[n]; 
6     memo[0] = 0; 
7     memo[l] = 1; 
8     for (int i = 2; i < n; i++) { 
9       memo[i] = memo[i - 1] + memo[i - 2]; 
10    } 
11    return memo[n - 1] + memo[n - 2]; 
12  }

```

If you really think about how this works, you only use memo [i] for memo [i+l] and memo [i+2]. You don't need it after that. Therefore, we can get rid of the memo table and just store a few variables. 

```sh
1     int fibonacci(int n) { 
2       if (n == 0) return 0; 
3       int a = 0; 
4       int b = 1; 
5       for (int i = 2; i < n; i++) { 
6         int c = a + b; 
7         a = b;
8         b = c;
9       } 
10      return a + b; 
11    } 
```

This is basically storing the results from the last two F ibonacci values into a and b. At each iteration, we compute the next value(c = a + b) and then move (b, c = a + b) into (a, b). This explanation might seem like overkill for such a simple problem, but truly understanding this process will make more difficult problems much easier.

<br><br>
If you want you can watch [video-explanation](https://www.youtube.com/watch?v=vYquumk4nWw) about DP and learn more about it.
