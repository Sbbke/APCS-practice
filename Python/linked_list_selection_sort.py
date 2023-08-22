class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
 
# function to swap nodes 'currX' and 'currY' in a
# linked list without swapping data
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
 
# function to sort the linked list using
# recursive selection sort technique
def recurSelectionSort( head) :
 
    # if there is only a single node
    if (head.next == None) :
        return head
 
    # 'min' - pointer to store the node having
    # minimum data value
    min = head
 
    # 'beforeMin' - pointer to store node previous
    # to 'min' node
    beforeMin = None
    ptr = head
     
    # traverse the list till the last node
    while ( ptr.next != None ) :
     
        # if true, then update 'min' and 'beforeMin'
        if (ptr.next.data < min.data) :
         
            min = ptr.next
            beforeMin = ptr
             
        ptr = ptr.next
     
    # if 'min' and 'head' are not same,
    # swap the head node with the 'min' node
    if (min != head) :
        head = swapNodes(head, head, min, beforeMin)
 
    # recursively sort the remaining list
    head.next = recurSelectionSort(head.next)
 
    return head
 
# function to sort the given linked list
def sort( head_ref) :
 
    # if list is empty
    if ((head_ref) == None) :
        return None
 
    # sort the list using recursive selection
    # sort technique
    head_ref = recurSelectionSort(head_ref)
    return head_ref
 
# function to insert a node at the
# beginning of the linked list
def push( head_ref, new_data) :
 
    # allocate node
    new_node = Node(0)
 
    # put in the data
    new_node.data = new_data
 
    # link the old list to the new node
    new_node.next = (head_ref)
 
    # move the head to point to the new node
    (head_ref) = new_node
    return head_ref
 
# function to print the linked list
def printList( head) :
 
    while (head != None) :
     
        print( head.data ,end = " ")
        head = head.next
     
# Driver code
head = None
 
# create linked list 10.12.8.4.6
head = push(head, 6)
head = push(head, 4)
head = push(head, 8)
head = push(head, 12)
head = push(head, 10)
 
print( "Linked list before sorting:")
printList(head)
 
# sort the linked list
head = sort(head)
 
print( "\nLinked list after sorting:")
printList(head)