#include <iostream>
#include <array>

template <std::size_t N, typename T>
void print_array(const std::array<T, N> arr) {
    // static_assert(std::is_arithmetic<T>::value, "T must be a numerical type");
    
    for (std::size_t i=0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(){
    std::array<std::int32_t, 5> arr_1 = {23, 4, -1, 34, 4};

    std::cout << arr_1[0] << std::endl;
    std::cout << arr_1[3] << std::endl;
    std::cout << arr_1[11] << std::endl;    // Dangerous, looks in another space!
    std::cout << std::endl;

    std::array<int, 2> arr_2;
    arr_2[0] = 0;

    std::array<float, 8> arr_3{};

    print_array(arr_1);
    print_array(arr_2);
    print_array(arr_3);

    return 0;
}



