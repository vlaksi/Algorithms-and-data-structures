
"""
    Test for our implementation of stack.
"""

from queue import Queue

if __name__ == "__main__":

    ourQueue = Queue()
    ourQueue.enqueue("A")
    ourQueue.enqueue("B")
    ourQueue.enqueue("C")
    print(ourQueue)
    print("Peek is: " + ourQueue.peek())

    # after processing one element [ first one ]
    ourQueue.dequeue()
    print(ourQueue)

    print("Now peek is: " + ourQueue.peek())

