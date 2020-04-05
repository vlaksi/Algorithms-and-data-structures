"""
    Stack data struture. LIFO 
    We use python list to create Stack.
"""


class Stack():
    def __init__(self):
        self.items = []

    # override of toString method
    def __str__(self):
        ret = "\n------- STACK -------\n"
        # we go from back of list and print elements
        for element in reversed(self.items):
            ret += "\t\t" + str(element) +"\n"
        ret += "---------------------"
        return ret

    # add element to top of stack
    def push(self,item):
        self.items.append(item)

    # remove element from top of stack
    def pop(self):
        return self.items.pop()

    def isEmpty(self):
        return self.items == []

    # it give us element from the top of stack
    def peek(self):
        if not self.isEmpty():
            return self.items[-1]

    def getStack(self):
        return self.items

