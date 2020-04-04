
"""
    Test for our implementation of stack.
"""

from stack import Stack

if __name__ == "__main__":

    ourStack = Stack()
    ourStack.push("A")
    ourStack.push("B")
    ourStack.push("C")
    print(ourStack)

    # after remove one element from top
    # last element which is added now is removed
    ourStack.pop()
    print(ourStack)

    # give us top of stack
    print(ourStack.peek())

