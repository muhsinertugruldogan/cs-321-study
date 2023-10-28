#include <iostream>

int a = 5; // static initialization

struct IntVector {

    //counts how many intVector lives in memory.
//    static int countIntVector = 0;
//    We cannot initialize static variable in class.
    int size;
    int* data;

    IntVector(int size, int* initial_values) : size(size), data(new int[size]){
        for(int i = 0; i<size;i++)
            data[i] = initial_values[i];
        countIntVector++;
    }

    ~IntVector() {
        delete[] data;
        countIntVector--;
    }

    void setIndex(int index, int value) {
        this->data[index] = value;
    }

    void print() const
    {

        for(int i = 0; i < this->size; i++) {
            std::cout << this->data[i];
            if(i != this->size-1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
};

void print(const IntVector& iv) {
    static bool firstTime = true; //static extends variable lifecycle.

    if(firstTime) {
        std::cout<<"Hi there, I am free function print. That is prints an IntVector" << std::endl;
        firstTime = false;
    }

    for(int i = 0; i < iv.size; i++) {
        std::cout << iv.data[i];
        if(i != iv.size-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    {
        std::cout << IntVector::countIntVector << std::endl;
        int iv_values[10] = {1,2,3,4,5,6,7,8,9,10};
        IntVector iv = IntVector(10, &iv_values[0]);
        std::cout << IntVector::countIntVector << std::endl;

        IntVector iv2 = IntVector(5, &iv_values[0]);
        std::cout << IntVector::countIntVector << std::endl;


        iv.data[2] = 5;
        iv.setIndex(0,10);
        iv.setIndex(1,25);
        iv.setIndex(2,5);

        print(iv);
        print(iv);
        print(iv);
        iv.print();
    }

    std::cout << countIntVector << std::endl;
    return 0;
}