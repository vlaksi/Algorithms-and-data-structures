<h1 align = "center"> Memory(Stack vs Heap) </h1>

<br>

## Stack

Generally speaking, the Stack is a memory region within the program/process. This part of the memory gets allocated when a process is created. We use Stack for storing ***temporary data*** such as local variables of some function, environment variables which helps us to transition between the functions, etc. We interact with the stack using PUSH and POP instructions.
<br><br>

## Heap

The heap is used by C and C++ programmers to ***manually allocate new regions of process memory*** during program execution. Programmers ask the heap manager to allocate these regions of memory via calls to heap functions like **malloc**. These allocated regions of memory, or “allocations”, can then be used, modified or referenced by the programmer up until the programmer no longer needs it and returns the allocation back to the heap manager via a call to **free**.

<br>

## Visualize

<p align="center">

  <img  src="https://user-images.githubusercontent.com/45834270/79137702-7ee86980-7db3-11ea-87a8-a07c0ca0996e.png">

</p>

If you want you can watch [video-explanation](https://www.youtube.com/watch?v=_8-ht2AKyH4&t=332s) about Memory(Stack vs Heap) and learn more about it.
