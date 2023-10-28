#include <iostream>

struct IntVector {
    /**
     * you can write here const to make size read-only.
     */
    int size;
    int* data;

    IntVector(int size, int* initial_values) : size(size), data(new int[size]){
        for(int i = 0; i<size;i++) {
            data[i] = initial_values[i];
        }
    }

    ~IntVector() {
        delete[] data;
    }

    void setIndex(int index, int value) {
        this->data[index] = value;
    }

    /**
     * this print method inside we can change size and data attributes. const is important.
     */
    void print() const
    {
        /**
         * const and reference is very important!
         */
        for(int i = 0; i < this->size; i++) {
            std::cout << this->data[i];
            if(i != this->size-1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }


};

// let's write print function. it will be free function because printing is not only for IntVector object.
void print(const IntVector& iv) {
    /**
     * const and reference is very important!
     */
    for(int i = 0; i < iv.size; i++) {
        std::cout << iv.data[i];
        if(i != iv.size-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    {
        int iv_values[10] = {1,2,3,4,5,6,7,8,9,10};
        IntVector iv = IntVector(10, &iv_values[0]);
        iv.data[2] = 5;
        iv.setIndex(0,10);
        iv.setIndex(1,25);
        iv.setIndex(2,5);
//        iv.print();
        print(iv);
    }

    return 0;
}