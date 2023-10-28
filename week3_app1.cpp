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

int i = 10; // global scope, it is static initialization. it is not in stack, not in heap.

struct Vector2d {int a; int b; };
// this func() is free.
Vector2d addVectors(Vector2d first, Vector2d second) { //they are cloned. it is pass by value.
    Vector2d result;
    result.a = first.a + second.a;
    result.b = first.b + second.b;
    return result;
}

//void initVector2d(Vector2d* v, int a, int b) { //pointer cloned
//    // pointers are very dangerous. we can change it with reference.
//    // pointers are primitive type.
//    v->a = a;
//    v->b = b;
//}
void initVector2d(Vector2d& v, int a, int b) { //reference
    // reference is higher level encapsulation of pointers.
    // references do not allow pointer arithmetic.


    v.a = a;
    v.b = b;
}

int main(int argc, char* argv[]) {
    // initialization of vector2d's are messy.
    // first 2d vector instance.
    Vector2d A;
    initVector2d(A, 5, 7); // memory address cloned.
    // A changed by pointer.

    // second 2d vector instance
    Vector2d B;
    B.a = -1;
    B.b = -3;

    // add 2d vectors
    Vector2d C = addVectors(A,B);

    return 0;
}
