#include <iostream>

enum class PermissionLevel {
    STUDENT,
    TUTOR,
    INSTRUCTOR,
    ADMIN
};

enum class ServerPermissionLevel {
    STUDENT,
    TUTOR,
    INSTRUCTOR,
    ADMIN
};

int main(){
    PermissionLevel pl_giuliano = PermissionLevel::STUDENT;
    // auto pl_giuliano = PermissionLevel::STUDENT;

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





