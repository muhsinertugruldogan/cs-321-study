/**
 *
 *
 */



#include <iostream>

struct IntVector {
    int size;
    int* data;

    IntVector(int size) : size(size), data(new int(size)) {  }

    void setIndex(int index, int value) {
//above two lines are same with this->
//        IntVector& iv = *this;
//        iv.data[index] = value;

        this->data[index] = value;
    }

    ~IntVector() {
        delete[] data;
    }

};

int main(int argc, char* argv[]) {
    {   // you can control lifecycle of iv.
        IntVector iv = IntVector(10); // this structure store data and size in stack memory.
        iv.data[2] = 5;
//        setIndex(iv,2,5);
        iv.setIndex(2,5);

    }
    // out of iv it deleted.

    //C has malloc and free for dynamic memory handling
    //malloc returns void pointer because malloc does not know type of variable.
    //    int* ptr = (int *)malloc(sizeof (int)* 100);
//    ptr[0] = 1;
//    *(ptr + 0);
//    //above 2 lines are do same job.
//
//    ptr[100] = 2; // out of bounds
//
//    //above 3 lines are the same
//    ptr[-1] = 3; // out of bounds
//    *(ptr + (-1)) = 0;
//    *((-1) + ptr) = 0;
//    1[ptr] = 0;
//
//    free(ptr);
//
//    // C++ ancient way
//    int* ptr2 = new int[100];
//    //...
//    delete[] ptr2;
//
//    int* value = new int;
//    delete value;





    return 0;
}