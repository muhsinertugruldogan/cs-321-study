/**
 * Stack - heap memory: CPU does not understand this higher level encapsulation.
 * They are our inventions.
 * each functions has it own stack spaces.
 * main functions stack is always there as long as program is running.
 * big objects stands at heap memory.
 * value semantics: you are controlling the real thing, objects.
 * reference semantics: everything access through pointers.
 * Functions does not known by CPU. They are just emory locations and program jumps to them.
 *
 *global/local scope:
 *OS rents, not sell.
 *new keyword demands enough bytes from operating system.
 *  int* p_i = new int; // it returns beginning address of 4 bytes array that stores integer.
 *   p_i++; // it increments memory address 4 bytes.
 *   p_i[0]++; //you have the value of int that pointing by p_i and increments it.
 *   *(p_i)++; // increments the value referencing by p_i.
 *   int k = p_i[1]++; // increments next integer and copying it another integer.
 *   int* p_k = &k; // address of operator.
 *    // what is variable, where is it, is it a pointer or value itself. These questions are important.
 *
 */

/**
 * :: -> go up
 * free functions:
 * method -> function under a class.
 * ::i; // takes global i
 * i; // if name of 'i' become different, this statement takes global i. else, it takes local i.
 * // there are 2 different variable with name i. global and local scope i's.
 * primitive types: CPU knows that. CPU can understand their type
 *
 */
#include <iostream>

int i = 10;

struct Vector2d {
    int a;
    int b;

    Vector2d() : a(0), b(0) { // it is more speedy version of constructor.
    }
    Vector2d(int a_, int b_) : a(a_), b(b_){
    }


    Vector2d addVectors(const Vector2d& second) { // why we remember function name? we can overload operator.
        Vector2d result;

        result.a = this-> a + second.a;
        result.b = this-> b + second.b;
        return result;
        // copy it to object inside.
    }

    Vector2d operator+(const Vector2d& right) { // why we remember function name? we can overload operator.
        Vector2d result; // there is no default constructor. So, there is an error. It is default constructor.

        result.a = this->a + right.a;
        result.b = this->b + right.b;
        return result;
        // copy it to object inside.
    }
};


void func() {
    Vector2d A(5,7);

    Vector2d B(-1,3);

    Vector2d C = A+B;
}

int main(int argc, char* argv[]) {
    func();


    return 0;
}
