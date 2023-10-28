#include <iostream>

int a = 5; // static initialization
int countTVector = 0;
template <typename T>
struct Vector {
    /**
     * struct starts with public.
     */
    //counts how many intVector lives in memory.
//    static int countIntVector = 0;
//    We cannot initialize static variable in class.
    int size;
    T* data;

    Vector(int size, T* initial_values) : size(size), data(new T[size]){
        for(int i = 0; i<size;i++)
            data[i] = initial_values[i];
        countTVector++;
    }

    ~Vector() {
        delete[] data;
        countTVector--;
    }

    void setIndex(int index, T value) {
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


template <typename T>
void print(const Vector<T>& iv) {
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
        std::cout << countTVector << std::endl;
        int iv_values[10] = {1,2,3,4,5,6,7,8,9,10};
        /**
         * initialization process, we repeat the type. Solution is auto keyword.
         */
        auto iv = Vector<int>(10, &iv_values[0]);
        std::cout << countTVector << std::endl;
        {
            auto iv2 = Vector<int>(5, &iv_values[0]);
            std::cout << countTVector << std::endl;
        }


        /**
         * iv and dv are all different classes. They are not related.
         */
        {
            double dv_values[5] = {1.1,2.2,3.3,4.4,5.5};
            auto dv = Vector<double>(5,&dv_values[0]); // this happens at compile time.
            std::cout << countTVector << std::endl;
            print(dv);
        }


        iv.data[2] = 5;
        iv.setIndex(0,10);
        iv.setIndex(1,25);
        iv.setIndex(2,5);

        print(iv);
        print(iv);
        print(iv);
        iv.print();
    }

    std::cout << countTVector << std::endl;
    return 0;
}