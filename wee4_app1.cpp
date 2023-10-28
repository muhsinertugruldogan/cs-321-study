/**
 *
 *
 */



#include <iostream>

struct intVector {
    int size;
    int* data;



};

int main(int argc, char* argv[]) {
    //C has malloc and free for dynamic memory handling
    //malloc returns void pointer because malloc does not know type of variable.
    int* ptr = (int *)malloc(sizeof (int)* 100);
    ptr[0] = 1;
    *(ptr + 0);
    //above 2 lines are do same job.

    ptr[100] = 2; // out of bounds

    //above 3 lines are the same
    ptr[-1] = 3; // out of bounds
    *(ptr + (-1)) = 0;
    *((-1) + ptr) = 0;
    1[ptr] = 0;

    free(ptr);

    // C++ ancient way
    int* ptr2 = new int[100];
    //...
    delete[] ptr2;

    int* value = new int;
    delete value;


    return 0;
}