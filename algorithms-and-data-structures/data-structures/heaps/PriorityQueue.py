class PriorityQueueBase:
    """Abstract base class for a priority queue."""
    class _Item:
        """Lightweight composite to store priority queue items."""
        __slots__ = '_key', '_value'

        def __init__(self, k, v):
            self._key = k
            self._value = v

        def __lt__(self, other):
            return self._key < other._key # compare items based on their keys

    def isEmpty(self): # concrete method assuming abstract len
        """Return True if the priority queue is empty."""
        return len(self) == 0



"""
    UnsortedPriorityQueue
"""

class UnsortedPriorityQueue(PriorityQueueBase): # base class deﬁnes Item
    """ A min-oriented priority queue implemented with an unsorted list."""

    def _find_min(self):        # nonpublic utility
        """ Return position of item with minimum key. """
        if self.isEmpty():      # isEmpty inherited from base class
            raise Empty("Priority queue is empty")
        