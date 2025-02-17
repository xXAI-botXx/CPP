#include <iostream>

int main() {
    int age_1 = 14;
    int age_2 = 21;

    /*
    int older_age;
    if (age_1 > age_2) {
        older_age = age_1;
    } else {
        older_age = age_2;
    }
    */

    //                BOOL-EXPR   ? TRUE  : FALSE
    int older_age = age_1 > age_2 ? age_1 : age_2;
    
    return 0;
}



