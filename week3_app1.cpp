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
 *
 *
 */
#include <iostream>

int i = 10; // global scope, it is static initialization. it is not in stack, not in heap.


// this func() is free.
void func(int l) { // l is copy of main method i. i is cloned.
    int i = 3;

}

int main(int argc, char* argv[]) {

    int i = 100; // value itself, not post-it.
    func(i);
    std::cout << ::i;

    // first 2d vector instance.
    int a = 5;
    int b = 7;

    // second 2d vector instance
    int m = -1;
    int n = -3;

    // add 2d vectors
    int y = a+m;
    int z = b+n;

    return 0;
}
