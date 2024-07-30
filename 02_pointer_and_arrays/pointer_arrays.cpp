#include <iostream>
#include <array>

// there is also a better C++ alternative, but for now we lern the basic

int main(){
    constexpr auto arr_size = std::size_t{2};
    // std::array<std::int32_t, arr_size> arr_1 = {1, 2};

    // Heap Allocation
    auto* arr_1 = new std::int32_t[arr_size];

    for (std::size_t i=0; i < arr_size; i++) {
        arr_1[i] = i*2;
    }

    for (std::size_t i=0; i < arr_size; i++) {
        std::cout << arr_1[i] << std::endl;
    }

    // don't forget the [] when you delete the array memory
    delete[] arr_1;

    return 0;
}



