#include <iostream>

/**
 * Memory-Types
 * Stack: Fast, but small
 * Heap: Slow, but big
 * Static: for static vars and funcs
 * ...
 * 
 * Important: The stack memory will be cleaned automatically, the heap have to be managed by the programmer.
 * 
 * new: creates new data in heap -> returns the memory address
 * delete: release data in heap
 * 
 * Pointers exist on the stack and can point to an address on the stack or the heap.
 * Pointers can also point to other pointers and can also be updated after initialization.
 */

int main(){
    // var on Stack
    int i = 1;
    int *pointer_0 = &i;
    std::cout << std::endl;
    std::cout << *pointer_0 << std::endl;   // value
    std::cout << &pointer_0 << std::endl;   // address of the pointer itself 
    std::cout << pointer_0 << std::endl;    // address of the pointed object/data

    // var on Heap with keyword "new"
    int *pointer_1 = new int;
    *pointer_1 = 42;

    std::cout << std::endl;
    std::cout << *pointer_1 << std::endl;
    std::cout << &pointer_1 << std::endl;
    std::cout << pointer_1 << std::endl;

    int *pointer_2 = new int{164};

    std::cout << std::endl;
    std::cout << *pointer_2 << std::endl;
    std::cout << &pointer_2 << std::endl;
    std::cout << pointer_2 << std::endl;

    // give space free -> deletes the data on the memory adress, not the pointer itself
    //     -> this memory space doesn't belongs no longer to our program, but the pointer still points to it 
    // delete pointer_0; // this is not in heap, so not possible to remove from stack
    delete pointer_1;
    delete pointer_2;

    // Let's see what the pointer is referencing now
    //    -> the pointer still exist, has the same address and points to the same address but the value is no longer the same
    //       the heap int variable is gone
    std::cout << std::endl;
    std::cout << *pointer_1 << std::endl;
    std::cout << &pointer_1 << std::endl;
    std::cout << pointer_1 << std::endl;

    // it's a good practise to set the pointer then to null -> avoid dangling pointers
    pointer_1 = nullptr;
    pointer_2 = nullptr;

    // ! Using a pointer after the deleting the heap-object the behaviour can be unexpected and should be never done.
    // ! Your program can be crash, a segfault is also possible and there are more bad things which can happen
    // ! In the best case your dead pointer will show you a "random" number or the number from before
    // ! ------------------------------------------------------------------------------------------------------------
    // ! So it is a good practise to set ded pointer to nullpointer to avoid harming your program

    return 0;
}


/*
Result:

1
0x7ffffcbf0
0x7ffffcbfc

42
0x7ffffcbe8
0xa00001db0

164
0x7ffffcbe0
0xa00001dd0

-77143736
0x7ffffcbe8
0xa00001db0
*/


