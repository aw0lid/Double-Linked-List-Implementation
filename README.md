# Doubly Linked List Implementation in C++

This is a generic (template-based) implementation of a **Doubly Linked List** in C++.  
The class `clsDbLinkedList` supports basic and advanced operations on the list, such as:

- Adding nodes at the beginning, end, before or after a specific item
- Deleting nodes from the beginning, end, or by specific value
- Searching for nodes by value
- Updating node values by index
- Accessing nodes and values by index
- Clearing the entire list
- Reversing the list order
- Retrieving the size of the list

### Features:
- Fully templated to support any data type
- Proper memory management with destructor to avoid memory leaks
- Internal `Node` class storing pointers to previous and next nodes for bidirectional traversal
- Safety checks for empty list and invalid indexes

### Use case:
This implementation is intended for educational purposes to demonstrate how a doubly linked list works internally and how to manipulate it efficiently in C++.
