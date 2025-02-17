#include <iostream>

// vriable-name rules:
// - can't start with a number
// - can't contain whitespaces
// - must be unique

int main(){

    // declaration + initialization
    std::cout << "Declaration and Initialization:\n" << std::endl;

    int age;    // declaration
    int age_2 = 23;   // declaration + initialization
    int age_3;   // declaration
    age_3 = 79;    // initialization

    float weight;
    float weight_2 = 56.3;    // 56.3f

    std::cout << "age 1:" << age << "(without initialization)\nage 2:" << age_2 << "\nage 3:" << age_3 << std::endl;
    std::cout << "weight 1:" << weight << "(without initialization)\nweight 2:" << weight_2 << std::endl << std::endl;

    // calculation
    int number_1 = 2;
    int number_2 = 3;
    std::cout << "Calculation:\n    - number 1 = " << number_1 << "\n    - number 2 = "<< number_2 << std::endl;
    std::cout << "addition:" << number_1+number_2 << std::endl;
    std::cout << "substraction:" << number_1-number_2 << std::endl;
    std::cout << "multiplication:" << number_1*number_2 << std::endl;
    std::cout << "divion:" << number_1/number_2 << std::endl;

    return 0;
}

