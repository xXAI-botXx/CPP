#include <iostream>

// enum -> enumeration
enum PermissionLevel {
    STUDENT,
    TUTOR,
    INSTRUCTOR,
    ADMIN
};


/* you can also set the given int value by yourself
enum PermissionLevel {
    STUDENT = 1,
    TUTOR = 2,
    INSTRUCTOR = 3,
    ADMIN = 4,
};
*/

int main(){
    PermissionLevel pl_giuliano = PermissionLevel::STUDENT;
    std::cout << pl_giuliano << std::endl;

    switch(pl_giuliano) {
        case PermissionLevel::STUDENT: {
            std::cout << "Hello student" << std::endl;
            break;
        }
        // ...
        default: {
            std::cout << "Hello Unkown" << std::endl;
        }
    }

    return 0;
}






