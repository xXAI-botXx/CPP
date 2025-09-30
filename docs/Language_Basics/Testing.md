[go back](../../README.md)

# Testing

Testing is essential in order to make sure that your code works and this can be done automatically.

Contents
- <a href="#catch_">Testing via Catch2</a>



<br><br>

---
<h3><a name='catch_'>Testing via Catch2</a></h3>

One of the easiest and best testing methods with C++ is the [Catch 2](https://github.com/catchorg/Catch2/releases). It is super simple.

1. Go to https://github.com/catchorg/Catch2/releases/tag/v2.13.9 and download the latest .hpp file from the version **v2** (only the hpp file)
2. Add the .hpp into your project
3. Add testing code into a new test.cpp file
4. Compile your test file:
    ```
    g++ -std=c++17 tests.cpp -o tests
    ```
    Run:
    ```
    ./tests
    ```

That's it. Let's look at the tests.cpp:

```cpp
// test head
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// import code to test
// -> #include "your_file.h"
// lets define some code here for this example, but commonly you just want to include your code
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// start testing

TEST_CASE("Addition works", "[math]") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
    REQUIRE(add(0, 0) == 0);
}

TEST_CASE("Multiplication works", "[math]") {
    REQUIRE(multiply(2, 3) == 6);
    REQUIRE(multiply(5, 0) == 0);
    REQUIRE(multiply(-2, 3) == -6);
}

TEST_CASE("Failing test example", "[fail]") {
    REQUIRE(add(1, 1) == 2);  // This will pass
    // REQUIRE(add(1, 1) == 3);  // Uncomment to see failure

```





