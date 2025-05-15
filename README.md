1)implementation=>(forming max heap ,inserting deleting ,heapify,printing)

2)heapsort=>using heapify 
                                        LETS CLEARLY SEE  NORMAL HEAP AND HEAP AFTER HEAPSORT(WHICH USES HEAPIFY TECHNIQUE)

                     
                      =>  Say we insert values:
                        50, 30, 20, 15, 10, 8, 16
                        

                                                              
                                                              
                                                              
                                                              
        EX-🌲 Suppose We Build a Max-Heap:                       1)heap  
                                              The Max-Heap might look like this:
       
               50
             /    \
           30      20
          /  \    /  \
        15  10  8   16
Stored in array as:
[50, 30, 20, 15, 10, 8, 16]



When you do print() of the heap array:
🖨️ Output = [50, 30, 20, 15, 10, 8, 16]                                           #see ouput
This is NOT sorted.
This only means heap property is satisfied: parent ≥ children.



                                                  2) HEAPSORT

✅ Now Do Heap Sort:
Heap sort repeatedly extracts the maximum and heapifies the rest.

Sorted array (ascending order):

🖨️ Output = [8, 10, 15, 16, 20, 30, 50]                                         #see ouput
This is sorted. The heap property is lost because the structure is flattened for sorting.


                         deletion in heap VS heapsort
Deletion in heap: Removes one element, keeps heap structure.
process =>
Remove 50 (root)
Move last element (25) to root
Heapify from root

Heapsort: Removes all elements in order, results in sorted array but destroys heap structure.


                          heapify
it is just a fn that maintain heap property of root node ,always bigger than its child node..applies on all its subnode also.
used in deletion fn ,when one element deleted heapify from root node(baap).

