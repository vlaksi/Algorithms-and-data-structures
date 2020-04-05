"""
    Queue data structure. FIFO
    We use python list to create queue.
"""


class Queue():
    def __init__(self):
        self.items = []

    # overide __str__ magic method
    def __str__(self):
        ret = "\n------- QUEUE -------\n"

        for element in self.items:
            ret += "\t\t" + str(element) + "\n"

        ret += "---------------------"
        return ret

    # add element to the end of queue
    def enqueue(self, item):
        self.items.append(item)

    # remove the first item in the queue
    def dequeue(self):
        return self.items.pop(0)

    def isEmpty(self):
        return self.items == []

    # return the top of the queue
    def peek(self):
        if not self.isEmpty():
            return self.items[0]

    def getQueue(self):
        return self.items