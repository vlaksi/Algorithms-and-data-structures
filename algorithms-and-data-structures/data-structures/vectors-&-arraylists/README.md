<h1 align = "center"> ArrayList & Resizable Array </h1>

In *some languages*, arrays (often called lists in this case) are ***automatically resizable***. The array or list will grow as you append items. In *other languages*, like Java, ***arrays are fixed length***. The size is defined when you create the array. <br><br>

When you need an array-like data structure that offers **dynamic resizing**, you would usually use an **ArrayList**. An ArrayList is an array that **resizes itself** as needed while still providing O(1) access. A typical implementation is that when the array is full, the array doubles in size. Each doubling takes O(n) time, but happens so rarely that its amortized insertion time is still O(1). 

<br>

```sh

1   ArrayList<String> merge(String[] wordsJ String[] more) { 
2     ArrayList<String> sentence = new ArrayList<String>(); 
3     for (String w : words) sentence.add(w);
4     for (String w : more) sentence.add(w); 
5     return sentence; 
6   }

```
<br><br>
## StringBuilder 

Imagine you were concatenating a list of strings, as shown below. What would the running time of this code be? For simplicity, assume that the strings are all the same length (call this x) and that there are n strings

```sh

1   String joinWords(String[] words) { 
2     String sentence = ""; 
3     for (String w : words) { 
4       sentence = sentence + w; 
5     } 
6     return sentence; 
7   }

```
On each concatenation, a new copy of the string is created, and the two strings are copied over, character by character. The first iteration requires us to copy x characters. The second iteration requires copying 2x characters. The third iteration requires 3x, and so on. The total time therefore is 0 (x + 2x + ... + nx). This reduces to **O(xn^2)**. 

<br>
StringBuilder can help you avoid this problem. StringBuilder simply creates a resizable array of all the strings, copying them back to a string only when necessary. 

<br>

```sh

1   String joinWords(String[] words) { 
2     StringBuilder sentence new StringBuilder(); 
3     for (String w : words) { 
4       sentence.append(w); 
5     } 
6     return sentence.toString(); 
7   } 

```





