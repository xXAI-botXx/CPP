
[go back](../../README.md)


<h1><a href='top' name='own_cpp_lib_'>Own C++ Lib</a></h1>

If you want to create your own C++ library than you are here right. In following tutorial we think that our lib has the name tensor-rush, but you can change to the name you want.

1. Make a git project in github and make sure to click "Make README.md" + you can also directly add a License.md
2. Clone your repository to your local system
3. Open Visual Studio and create a new *Dynamische Bibliothek (DLL)* or *Statische Bibliothek (LIB)* -> dynamic if you have many external libraries else static should be fine + make sure to create the solution file outside of the project folder (uncheck the box) + the location should be the folder, where your git project was created/cloned to and the name should be same from the git and vs
4. create a *tensor-rush.hpp* with -> same name as your project:
    ```cpp
    #pragma once


    #ifdef TENSOR_RUSH_EXPORTS
    #define TENSOR_RUSH_API __declspec(dllexport)
    #else
    #define TENSOR_RUSH_API __declspec(dllimport)
    #endif


    class TENSOR_RUSH_API MeineKlasse {
    public:
        MeineKlasse();
        void sagHallo();
    };
        ```
    5. create a *tensor-rush.cpp* with -> same name as your project:
        ```cpp
    #include "pch.h"
    #include "tensor-rush.hpp"

    #include <iostream>

    MeineKlasse::MeineKlasse() {}

    void MeineKlasse::sagHallo() {
        std::cout << "Hallo von der Bibliothek!" << std::endl;
    }
    ```
6. You also have to add the Export key, so go to ```right-click on the lib project > properties > C/C++ > Preprocessor > Preprocessordefinitions``` and add there *TENSOR_RUSH_EXPORTS*
7. With ```right-click on the project > build```, you can *build* it, which will create the .dll and .lib files 
8. Testing/running your lib
    1. Create a local test project inside of your top project by ```right-click on the project name > add > new project```  just named "test" and a normal empty C++ project. 
    2. You have to ```right-click on the test project > properties > C/C++ > General > Additional Include Directories``` and add the path to the folder, where the .hpp/.h files are.  
    3. You have to ```right-click on the test project > properties > Linker > General > Additional Librarydirectories``` and add the path to the folder, where the .dll and .lib files are.
    4. You have to ```right-click on the test project > properties > Linker > Input > Additional Dependencies``` and add all .lib names (here for example tensor-rush.lib)
    5. Now  you can try to use your lib.  Main.cpp:
        ```cpp
        #include <iostream>
        #include "meine_lib.hpp"

        int main() {
            MeineKlasse obj;
            obj.sagHallo();
            return 0;
        }
        ```
    6. To run the test, you have to click the small arrow next to the green running arrow button and choose *startproject configure* and choose there that the test should run if the button is clicked.
9. You can share your .h, .dll and .lib, so that other can use your library.


> Executable files and .lib / .dll files should be added not directly in your git repo, else it should be added in releases, because you don't want to track the executable and lib files.<br>You may want to create a release folder witht the right


It is often recommended to create a folder structure, so that your code is well structured. In Visual Studio you can do that as virtual, so the real files are in all the same place and the project solution file saves which file is in which virtual folder. Example substructure:
```
tensor-rush/
│── include/                  # header files
│   ├── tensor-rush.h         # main header
│   ├── core/
│   │   ├── log.h             # Logging-Functions
│   │   ├── math.h            # Math-Functions
│   ├── utils/
│   │   ├── file_io.h         # File Operations
│   │   ├── string_utils.h    # String-Utilities
│
│── src/                      # cpp files
│   ├── tensor-rush.cpp       # main implementation
│   ├── core/
│   │   ├── log.cpp
│   │   ├── math.cpp
│   ├── utils/
│   │   ├── file_io.cpp
│   │   ├── string_utils.cpp
│
│── lib/                      # external dll or lib files
│   ├── Vulkan.lib            
│   ├── OpenGL32.lib
│
│── tests/                    # Unit-Tests
│   ├── main_test.cpp
```

The tensor-rush.hpp is now the master headerfile, which includes every other available header file, so the user have to include only the tensor-rush.hpp.


Congratulations!!! You should be able now to make your own lib! 😇


