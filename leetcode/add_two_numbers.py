# Definition for singly-linked list.
from typing import Optional

def print_list(l):
    while l!=None:
        print(l.val)
        l = l.next

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:

    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:

        carry = 0
        ans_list = None
        last_node = None
        while l1 is not None and l2 is not None:
            digit_sum = l1.val + l2.val + carry
            if digit_sum > 9:
                carry = 1
                digit_sum = digit_sum % 10
            else:
                carry = 0

            if ans_list is None:
                ans_list = ListNode(digit_sum)
                last_node = ans_list
            else:
                ln = ListNode(digit_sum)
                last_node.next = ln
                last_node = ln

            l1 = l1.next
            l2 = l2.next

        while l1 is not None:
            digit_sum = l1.val + carry
            if digit_sum > 9:
                carry = 1
                digit_sum = digit_sum % 10
            else:
                carry = 0

            if ans_list is None:
                ans_list = ListNode(digit_sum)
                last_node = ans_list
            else:
                ln = ListNode(digit_sum)
                last_node.next = ln
                last_node = ln

            l1 = l1.next

        while l2 is not None:
            digit_sum = l2.val + carry
            if digit_sum > 9:
                carry = 1
                digit_sum = digit_sum % 10
            else:
                carry = 0

            if ans_list is None:
                ans_list = ListNode(digit_sum)
                last_node = ans_list
            else:
                ln = ListNode(digit_sum)
                last_node.next = ln
                last_node = ln

            l2 = l2.next

        if carry == 1:
            if ans_list is None:
                ans_list = ListNode(carry)
                last_node = ans_list
            else:
                ln = ListNode(carry)
                last_node.next = ln
                last_node = ln

        return ans_list

def create_list(l):

    start_node = None 
    last_node = None 

    first_time = True
    for item in l:
        ln = ListNode(item)
        if first_time:
            start_node = ln 
            last_node = ln 
            first_time = False
        else:
            last_node.next = ln 
            last_node = ln 
    return start_node

if __name__=="__main__":
    s = Solution()
    l1 = create_list([2,4,3])
    l2 = create_list([5,6,4])
    result = s.addTwoNumbers(l1,l2)

    while result!=None:
        print(result.val)
        result = result.next


