<h1 align = "center"> Bit manipulation </h1>

## Bit Manipulation By Hand 

If you're rusty on bit manipulation, try the following exercises by hand. The items in the third column can be solved manually or with "tricks" (described below). For simplicity, assume that these are four-bit numbers. 
If you get confused, work them through as a base 10 number. You can then apply the same process to a binary number. <br>Remember that ***^ indicates an XOR, and ~ is a NOT (negation)***. 

<p align = "center">
  <img src="https://user-images.githubusercontent.com/45834270/79168322-e4574d00-7de9-11ea-95d0-02dfa4262544.png">
</p>

The tricks in Column 3 are as follows: 
  1. 0110 + 0110 is equivalent to 0110 * 2, which is equivalent to shifting 0110 left by 1. 
  2. 0100 equals 4, and multiplying by 4 is just left shifting by 2. So we shift 0011 left by 2 to get 1100. 
  3. Think about this operation bit by bit. If you XOR a bit with its own negated value, you will always get 1. 
      - Therefore, the solution to a^(~a) will be a sequence of 1 s. 
  4. ~0 is a sequence of 1s, so ~0 <<  2 is 1s followed by two Os. ANDing that with another value will clear the last two bits of the value. 
  
<br>
If you didn't see these tricks immediately, think about them logically. 

## Bit Facts and Tricks 

The following expressions are useful in bit manipulation. Don't just memorize them, though; think deeply about why each of these is true. We use "1s" and "Os" to indicate a sequence of 1s or Os, respectively.

<p align = "center">
  <img src="https://user-images.githubusercontent.com/45834270/79168746-f4236100-7dea-11ea-9289-7830f36149cd.png">
</p>

To understand these expressions, recall that these operations occur bit-by-bit, with what's happening on one bit never impacting the other bits. This means that if one of the above statements is true for a single bit, then it's true for a sequence of bits.


## Two's Complement and Negative Numbers 

Computers typically store integers in ***two's complement representation***. A positive number is represented as itself while a negative number is represented as the two's complement of its absolute value (with a ***1 in its sign bit to indicate that a negative value***). The two's complement of an N-bit number (where N is the number of bits used for the number, excluding the sign bit) is the complement of the number with respect to 2^N.
<br><br>
Let's look at the 4-bit integer - 3 as an example. If it's a 4-bit number, we have one bit for the sign and three bits for the value. We want the complement with respect to 2^3, which is 8. The complement of 3 (the absolute value of - 3) with respect to 8 is 5. 5 in binary is 101. Therefore, -3 in binary as a 4-bit number is 1101, with the first bit being the ***sign bit***.

<br><br>
Another way to look at this is that we invert the bits in the positive representation and then add 1. 3 is 011 in binary. Flip the bits to get 100, add 1 to get 101, then prepend the sign bit (1) to get 1101. 
In a four-bit integer, this would look like the following.

<p align = "center">
  <img src="https://user-images.githubusercontent.com/45834270/79169055-be32ac80-7deb-11ea-93bf-35a4e8c99d7f.png">
</p>

## Arithmetic vs. Logical Right Shift 
There are two types of right shift operators. The ***arithmetic right shift*** essentially ***divides by two***. The ***logical right*** shift does what we would ***visually see as shifting the bits***. This is best seen on a negative number. <br><br> In a logical right shift, we shift the bits and put a 0 in the most significant bit. It is indicated with a >>> operator. On an 8-bit integer (where the sign bit is the most Significant bit), this would look like the image below. The sign bit is indicated with a gray background. 

<p align = "center">
  <img src="https://user-images.githubusercontent.com/45834270/79169283-503ab500-7dec-11ea-87ef-1e6b8d867b1f.png">
</p>

In an arithmetic right shift, we shift values to the right but fill in the new bits with the value of the sign bit. This has the effect of (roughly) dividing by two. It is indicated by a >>  operator. 

<p align = "center">
  <img src="https://user-images.githubusercontent.com/45834270/79169342-7c563600-7dec-11ea-888e-fc73c335d61c.png">
</p>

<br><br>

## Common Bit Tasks: Getting and Setting 
The following operations are very important to know, but do not simply memorize them. Memorizing leads to mistakes that are impossible to recover from. Rather, understand how to implement these methods, so that you can implement these, and other, bit problems. 

### Get Bit 
This method shifts lover by i bits, creating a value that looks like 00010000. By performing an AND with num, we clear all bits other than the bit at bit i. Finally, we compare that to 0. If that new value is not zero, then bit i must have a 1. Otherwise, bit i is a 0.
```sh
1   boolean getBit(int num, int i) { 
2     return ((num & (1 << i)) != 0); 
3   }
```

### Set Bit 
SetBit shifts lover by i bits, creating a value like 0010000. By performing an OR with num, only the value at bit i will change. All other bits of the mask are zero and will not affect num. 
```sh
1   int setBit(int num, i nt i) { 
2     return num | (1 << i); 
3   }
```

### Clear Bit 
This method operates in almost the reverse of setBt . First, we create a number like 11101111 by creating the reverse of it (00010000) and negating it. Then, we perform an AND with num. This will clear the ith bit and leave the remainder unchanged. 
```sh
1   int clearBit(int num, int i) { 
2     int mask = ~(1 << i); 
3   return num & mask; 
4   } 
```
To clear all bits from the most significant bit through i (inclusive), we create a mask with a 1 at the ith bit (1 <<  i). Then, we subtract 1 from it, giving us a sequence of 0s followed by i 1s. We then AND our number with this mask to leave just the last i bits. 
```sh
1   int clearBitsMSBthroughI(int num, int i) { 
2     int mask = (1 << i) - 1; 
3     return num & mask; 
4   } 
```
To clear all bits from i through 0 (inclusive), we take a sequence of all 1s (which is -1) and shift it left by i + 1 bits. This gives us a sequence of 1 s (in the most significant bits) followed by i 0 bits. 
```sh
1   int clearBitslthrough0(int num, int i) { 
2     int mask = (-1 << (i + 1)); 
3     return num & mask; 
4   }
```

### Update Bit 
To set the ith bit to a value v, we first clear the bit at position i by using a mask that looks like 11101111. Then, we shift the intended value, v, left by i bits. This will create a number with bit i equal to v and all other bits equal to 0. Finally, we OR these two numbers, updating the ith bit if v is 1 and leaving it as 0 otherwise. 
```sh 
1   int updateBit(int num, int i, boolean bitIs1) { 
2     int value = bitIsl ? 1 : 0; 
3     int mask = ~(1 << i); 
4     return (num & mask) | (value << i); 
5   }
```
















