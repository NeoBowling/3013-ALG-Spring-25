## BST Delete Method
### Daniel Granados
### Description:

This is an addition to the program thats being worked in class. I was tasked to add a delete method to our binary search tree code. I added the neccessary syntax to utilize this method, there are 4 cases; the first is if the value being delete can't be found in the tree. The second case is if the root doesn't have a child. The third case is if the root only have one child. The last case is if the root has two children. I added a helper function: "findMin" and its purpose is to find a suitable replacement value to maintain the properties of a binary search tree.

### Files 
|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | main.cpp        | This is the product after I added the changes to the BST starter code   |
|   2   | changes.cpp     | This is just a file to highlight the findmin and delete method better |

### Example of how findmin works 
Before deleting 50
```
        50
       /  \
     30    70
    /  \   /  \
   20  40 60  80

```
To Delete 50; (has two children).
- Find the in-order successor, which is the smallest node in the right subtree → findMin(70) returns 60.
- Replace 50 with 60.
##### This is the end result: 
```
        60
       /  \
     30    70
    /  \     \
   20  40    80

```
