#include <iostream>
#include <cstdint>
#include <string>

/**
 * Strutures can be used to bundle data which
 * should bind together and together representate an object/information.
 * A structure can consist of different datatypes like string, int and enums.
 * 
 * When using stucts as input parameters it is often recommended to use 
 * the reference (&) to save memory and not copy all the data.
 * 
 * Structs can be defined in C++ files or in c++-Header files.
 * 
 * To access the attributes/data you use the name with a point and then the name of the data.
 * var_name.data_name
 * Also when using a reference.
 * 
 * BUT if you have an pointer then you have to use an ->
 * var_name->data_name
 * 
 * This -> makes following: (*var_name).data_name 
 * So it gets the value of the pointer, which is an struct in this case and gets the attribute
 */

struct UserData {
    std::string name;
    std::uint32_t id;
};

// given as reference, not copy
void print_user(const UserData& user) {
    std::cout << "User-Name: " << user.name;
    std::cout << "\n    -> ID: " << user.id << std::endl;
}

// given as pointer to the struct
void print_user(const UserData* user) {
    std::cout << "User-Name: " << user->name;
    // now using the explicit writting:
    std::cout << "\n    -> ID: " << (*user).id << std::endl;
}

int main(){
    UserData peter = {"Peter", 2437};
    // UserData peter = UserData{"Peter", 2437};
    // auto peter = UserData{"Peter", 2437};

    std::cout << peter.name << std::endl;

    // it is also possible to declarate only and define later
    UserData hans;
    hans.name = "Hans";
    hans.id = 3636;

    // you can also use the parameter names (recommended)
    UserData giulia = {.name="Giulia", .id=45676};

    // UserData* giulia_pt = &giulia;
    // a structure can also be a pointer
    // with new it will be generated in heap and else in stack???
    UserData* gianna = new UserData{.name="Giannao", .id=45677};

    print_user(giulia);
    print_user(gianna);

    return 0;
}



