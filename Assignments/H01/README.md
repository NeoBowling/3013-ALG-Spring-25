## AVL Trees notation
### Daniel Granados
### Description:

#### Inserting the following values in order:

10, 20, 30, 15, 25, 5, 35, 27

```
    10
     \
     20
       \
       30
```
- Inbalance happens, we do a RR rotation to fix the tree
```
      20
     /  \
   10    30
```
- we continue to add values until the tree is unbalanced
```
      20
     /  \
   10    30
        /
      15
        \
         25
```
Inbalance happens, 
