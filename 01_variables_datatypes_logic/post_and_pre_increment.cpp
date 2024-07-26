#include <iostream>

// using namespace std;    -> don't use that, this will probably cause issues

/**
 * Post Increment = i++
 * Pre Increment = ++i
 * 
 * Different: The Pre Increment will be executed directly and the post increment will be executed after the line
 * Most likely pre increment leads to the right behaviour
 */

int number_print(int i) {
    std::cout << i << std::endl;
}

int main(){
    int i = 0;
    number_print(i);

    number_print(i++);

    number_print(++i);

    return 0;
}


