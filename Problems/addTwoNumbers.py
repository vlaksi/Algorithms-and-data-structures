"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Author for this solutions: Vaxi
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        glava = ListNode(0)
        
        p = l1                                  # pokazivaci kroz liste
        q = l2
        trenutni = glava
        prenos = 0
        
        while( p is not None or q is not None): # trcimo sve dok imamo nekog sa ciframa
            x = p.val if p is not None else 0
            y = q.val if q is not None else 0
            suma = x + y + prenos
            prenos = suma / 10                  # 1 - ako ima prenosa tj suma > od 10
            trenutni.next = ListNode(suma % 10)
            trenutni = trenutni.next
            if p is not None:
                p = p.next
            if q is not None:
                q = q.next
        if prenos > 0:
            trenutni.next = ListNode(prenos)    # desio se overflow i imamo novi elemenet
            
        return glava.next
            
        