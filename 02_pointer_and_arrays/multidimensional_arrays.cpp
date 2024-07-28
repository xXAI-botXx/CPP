#include <iostream>

int main(){
    
    // 1d Array (Vector)
    int arr_1[3] = {1, 2, 3};

    // 2d Array (Matrix)
    int arr_2[3][2] = {1, 2, 3, 4, 5, 6};
    // or better:
    int arr_3[3][2] = {
                        {1, 2}, 
                        {3, 4}, 
                        {5, 6}
                        };
   
    std::cout << arr_3[0][1] << std::endl;

    // iterate over a 2d array
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "array[" << i << "][" << j << "] = " << arr_3[i][j] << std::endl;
        }
    }

    // calc sum
    int nrows = 4;
    int ncols = 2;
    std::uint32_t weights[nrows][ncols] = {{1,2}, {2,3}, {4,5}, {6,7}};
    std::uint32_t col_sum[ncols]{};
    std::uint32_t row_sum[nrows]{};

    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            col_sum[j] += weights[i][j];
            row_sum[i] += weights[i][j];
        }
    } 

    std::cout << "\nCol Sum:\n";
    for (int i = 0; i < ncols; ++i) {
        std::cout << col_sum[i] << std::endl;
    }

    std::cout << "\nRow Sum:\n";
    for (int i = 0; i < nrows; ++i) {
        std::cout << row_sum[i] << std::endl;
    }
    
    return 0;
}



