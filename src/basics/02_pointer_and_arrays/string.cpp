#include <iostream>

/**
 * This function checks the length of a string/char arry.
 */
int size_of_string(const char input_string[]) {
    int size = 0;
    while (true) {
        if (input_string[size] == '\0') {
            break;
        }
        ++size;
    }
    return size;
}

int main(){
    
    // Hover over the text/String to see the datatype
    std::cout << "Hello World!" << std::endl;
    /**
     * You should see "const char[13]"
     * So: A string is a constant array of chars
     * It is 13 and not 12 because all Strings have an invisible \0 at the end, 
     * so that the compiler knows where the string ends
     */

    // you could also create a String like following...but nobody does this
    // const is optional
    const char my_name[] = {'t', 'o', 't', 'o', '\0'}; 
    std::cout << my_name << "  Length: " << size_of_string(my_name)<< std::endl;

    const char my_gf_name[] = "yanyan";
    std::cout << my_gf_name << "  Length: " << size_of_string(my_gf_name) << std::endl;

    // iterate over a string
    for (int i = 0; i < std::size(my_name)-1; ++i) {
        std::cout << "char[" << i << "]: " << my_name[i] << "\n";
    }

    for (int i = 0; i < sizeof(my_gf_name)-1; ++i) {
        std::cout << "char[" << i << "]: " << my_gf_name[i] << "\n";
    }

    return 0;
}



