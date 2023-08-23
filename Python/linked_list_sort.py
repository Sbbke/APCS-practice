class Node:
    def __init__(self, data=None):
        """
        Initialize the node with data and next pointer as None
        """
        self.data = data
        self.next = None

def swapNodes(head_ref, currX, currY, prevY) :
 
    # make 'currY' as new head
    head_ref = currY
 
    # adjust links
    prevY.next = currX
 
    # Swap next pointers
    temp = currY.next                                    
    currY.next = currX.next
    currX.next = temp             
    return head_ref                                                                                                                                                                             
         
def printList(node):
    """
    Function to print the linked list starting from the provided node
    """
    # Iterate until node is NOT NULL
    while node:
        # Print the data
        print(node.data, end=' ')
        # Go to the next node
        node = node.next
 
def sortList(head):
    """
    Function to sort the linked list consisting of 0s and 1s
    """
    # Base case
    if not head or not head.next:
        return
 
    nums = []
    temp = head
 
    # Storing value of node into vector
    while temp:
        nums.append(temp.data)
        # Update the temp node
        temp = temp.next
 
    # sorting the nums array
    nums.sort()
 
    temp = head
    i = 0
 
    # traversing the linked list
    while i < len(nums):
        # updating value to nums[i]
        temp.data = nums[i]
        # point temp to next node and increment i
        temp = temp.next
        i += 1
 
def push(head, new_data):
    """
    Add a new node with provided data to the front of the linked list
    """
    new_node = Node(new_data)
    # Link the old list of the new node
    new_node.next = head
    return new_node
 
# Driver code
if __name__ == '__main__':
    # pushing values
    head = None
    head = push(head, 0)
    head = push(head, 1)
    head = push(head, 0)
    head = push(head, 1)
    head = push(head, 1)
    head = push(head, 1)
    head = push(head, 1)
    head = push(head, 1)
    head = push(head, 0)
    # printing linked list before and after sorting
    print("Linked List (before sorting) : ", end=' ')
    printList(head)
    sortList(head)
    print("\nLinked List (after sorting)  : ", end=' ')
    printList(head)