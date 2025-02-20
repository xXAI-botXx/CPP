<h1><a name="top">C++</a></h1>

This project contains knowledge about the C++ language.
An amazing programming langauge which is most likely preferred for software developement, rendering/graphical applications and compute intense applications. Through the long history and the near to the C language there are some legacy ways to use C++ and modern ways to use C++.<br>
I always found that C++ code is much prettier and more logical and gives the programmer more structure to hold on comapred to other programming languages but of course you pay with flexibility compared to languages like python or julia.<br>
This is project tries to catch the basics of C++ as well as some most interesting parts, like game programming, graphics rendering and general GPU calculations.

May use it as a reference ❤️


### Content:

- <h4><a href="#basics_">Basics</a></h4>
- <h4><a href="./docs/Game.md">Gaming</a></h4>
- <h4><a href="./docs/OpenGL.md">OpenGL</a></h4>
- <h4><a href="./docs/Vulkan.md">Vulkan</a></h4>
- <h4><a href="#installation_">Installation of GNU Compiler Collection</a></h4>
- <h4><a href="#runcppcode">Run C++ Code with GNU</a></h4>
- <h4><a href="#cmake_">CMake</a></h4>
- <h4><a href="#ide_">Using an IDE</a></h4>

<br><br>

<img src="./cover.jpeg"></img>






---
<h3><a href="#top" name="basics_">Basics</a></h3>

This part contains the most essential knowledge about C++.

<a name="bascis_top_">Contents:</a>
- <a href="#basics_stack_and_heap_">Stack and Heap</a>
- <a href="#basics_datatypes_">Datatypes</a>
- <a href="#basics_flow_structures_">Flow Structures</a>
- <a href="#basics_value_categories_">Value Categories</a>
- <a href="#basics_variable modifier_">Variable Modifiers</a>
- <a href="#basics_pointers_">Pointers</a>
- <a href="#basics_references_">References</a>
- <a href="#basics_arrays_">Arrays</a>
- <a href="#basics_templates_">Templates</a>
- <a href="#basics_namespaces_">Namespaces and Headerfiles</a>
- <a href="#basics_std_">Standard Library</a>
- <a href="#basics_classes_">Classes</a>
- <a href="#basics_best_practises_">Best Practises</a>
- <a href="#basics_examples_">Examples</a>




It follows some keyconcepts to keep in mind when working with C++.

<a name="basics_stack_and_heap_" href="#bascis_top_">^</a><br>
**Stack and Heap**<br>
In C++ there are 2 main storage types which should be known. One is the stack, a small memory where all local variables/values get stacked. The stack defines variables/values just in a local area, called scope. For example a function call creates a new scope on the stack and the variables are only avaiable on this scope. If the function call finsihes than the scope closes and the memory of these variables get free again.<br>
The heap is the other storage type, it provides much more storage capacities and have no scopes (there is no stacking). But the variables and values here does not delete themselfs, so the programmer have to delete the values here if they are not used anymore. Else a memory leak occur, where the taken memory accumulates and on some point the heap overflows and the program crashes.<br>
The heap always need pointer to its values and the programmer can decide which objects to createw where. Int values for example can be created in the stack or in the heap. The 'new' key shows when something is created in the heap and the 'delete' / 'delete[]' is for releasing/freeing memory.<br>
More about how to create variables where comes in a next chapter.<br>
'Dynamic allocation' refers to variables which lay in the heap because they are dynamic managed in the heap by the programmer and not bound to the scope/program flow. 'Static allocation' (or automatic allocation) refers to variables which are created in the stack. They are static because they are bound to it's scope/program flow.

<br><br>

<a name="basics_datatypes_" href="#bascis_top_">^</a><br>
**Datatypes**<br>
Basic Data Types
- bool → Boolean (true or false)
- char → Character (1 byte)
- int → Integer (4 bytes, platform-dependent)
- float → Floating-point number (4 bytes)
- double → Double-precision floating-point number (8 bytes)
- void → Represents "no type" (used for functions with no return value)

Integer Variants
- short → Short integer (2 bytes)
- long → Long integer (at least 4 bytes)
- long long → Longer integer (at least 8 bytes)
- unsigned → Unsigned version (positive numbers only)

Floating-Point Variants
- long double → Extended-precision floating-point number

Derived Data Types
- pointer → Stores memory addresses (int*, char*, etc.)
- reference → Alias to another variable (int&)
- array → Collection of elements of the same type (int arr[10];)
- function → Defined return type and parameters (int func(int x);)

User-Defined Data Types
- struct → Custom data structure
- class → Object-oriented data structure
- union → Memory-sharing structure
- enum → Enumeration of constant values
- typedef / using → Define custom type aliases

(Standard Library Types -> STD)<br>
STD Integer-Types (with fixed bit width over all OS)
- std::int8_t → 8-bit signed integer
- std::uint8_t → 8-bit unsigned integer
- std::int16_t → 16-bit signed integer
- std::uint16_t → 16-bit unsigned integer
- std::int32_t → 32-bit signed integer
- std::uint32_t → 32-bit unsigned integer
- std::int64_t → 64-bit signed integer
- std::uint64_t → 64-bit unsigned integer

STD Helper-Types
- std::size_t → Unsigned integer for memory sizes (e.g. sizeof(), array indices)
- std::ptrdiff_t → Signed integer, difference between two pointers
- std::nullptr_t → Type for nullptr

STD Character-Types
- std::byte → Raw data byte (from C++17, no direct numeric type)
- std::char_traits<char> → Character handling (used internally by std::string)
- std::wchar_t → Wide character type for Unicode
- std::char16_t, std::char32_t → Unicode types for UTF-16/UTF-32

STD Container-Types
- std::string → Dynamic string
- std::vector<T> → Dynamic array
- std::array<T, N> → Fixed size static array
- std::list<T> → Double linked list
- std::map<K, V> → Associative array (key-value pairs)
- std::unordered_map<K, V> → Hashmap for quick access
- std::set<T> → Set with unique elements
- std::queue<T> → FIFO queue

STD SmartPointers-Types
- std::unique_ptr<T> → Unique ownership (no delete necessary)
- std::shared_ptr<T> → Shared ownership with reference counting
- std::weak_ptr<T> → Weak pointer (prevents cycle problems)

STD Threading-Types
- std::thread → Start threads
- std::mutex → Locks resources to threads
- std::atomic<T> → Thread-safe atomic operations


<br><br>

<a name="basics_flow_structures_" href="#bascis_top_">^</a><br>
**Flow Structures**<br>
Conditional Statements
- if → Executes a block if a condition is true
- if-else → Executes one block if true, another if false
- else if → Multiple conditions in sequence
- switch-case → Multi-way branching based on a single value
- ?: (Ternary Operator) → Short inline conditional

Loops
- for → Loop with an initializer, condition, and increment
- while → Loop that runs while a condition is true
- do-while → Like while, but runs at least once

Jump Statements
- break → Exits a loop or switch statement
- continue → Skips to the next loop iteration
- return → Exits from a function
- goto → Jumps to a labeled statement (rarely used)

Exception Handling
- try → Defines a block of code to test for exceptions
- catch → Handles exceptions thrown by throw
- throw → Throws an exception

Others
- Range-based for (for (auto x : collection))
- Lambda expressions (used for inline logic)
- Coroutines (co_await, co_yield, co_return in C++20)

<br><br>

<a name="basics_value_categories_" href="#bascis_top_">^</a><br>
**Value Categories**<br>
Lvalues are values which are stored/connected with a variable.<br>
Values which are just passed by as a parameter and therfore have no memory location are called rvalues.<br>
Glvalues (Generalized Lvalues) are all values which have an address.<br>
Xvalues are expriting values which are about to destroy.<br>
And Prvalues which are rvalues which have a memory address.

<br><br>

<a name="basics_variable modifier_" href="#bascis_top_">^</a><br>
**Variable Modifier**<br>
Variables can be 'const' -> constant, means the value is not allowed to change. This is 
const (Constant Variable)

- const
	- The value cannot be changed after initialization.
	- Used for defining constants and preventing modifications to function parameters.
	- Helps avoid unintended side effects.
	- Efficient for references since they don’t require additional memory allocation.
	- Useful for constants which value never should get changed in the program or for function parameters, to make sure that the passed reference is not changed and does so not lead to unwanted sideeffects -> why we want unchangable references? because references are most lowest at resource consuming.

- volatile
    - Tells the compiler that the variable can be changed at any time (e.g., by hardware or another thread).
    - Prevents compiler optimizations that assume the value won’t change unexpectedly.

- mutable
	- Allows modification of a variable inside a const object.
    - Typically used with const class methods to modify specific members.

- static
    - Inside a function: Retains its value across function calls.
    - Inside a class: Shared among all instances (i.e., belongs to the class, not an object).
    At global scope: Limits visibility to the current translation unit (file).

- extern
    - Declares a global variable defined in another file or translation unit.
    - Used for sharing variables across multiple files.

- register (Deprecated)
    - Suggested storing the variable in a CPU register for fast access.
    - Modern compilers optimize this automatically, making it obsolete.

- thread_local
    - Creates a variable that is unique to each thread.
    - Useful for thread-safe programming without explicit locking.

<br><br>

<a name="basics_pointers_" href="#bascis_top_">^</a><br>
**Pointers**<br>
Pointers are variables pointing to another memory address. A pointer have a own memory adress and the value saved is the memory address where the pointer points to.<br>
Pointer are important to use the heap efficiently.<br>
Pointer are declared with a \* and need to get a memory address, which can be provided with a & before the target variable.
```c++
int i = 36;
int* pointer_i = &i;
```

- \*pointer_name -> returnes the value of the pointed address.
- &pointer_name -> returns the memory address of the pointer
- pointer_name -> returns the memory address where it points to
```c++
int* p = new int{12};
*p = 8;    // *pointer_name returnes the value of the pointed address
&p;    // &pointer_name returns the memory address of the pointer
p;   // pointer_name returns the memory address where it points to
```

Pointers can also point to nothing:
```c++
#include <iostream>
#include <cstdint>

template <typename T>
// reference on a pointer is needed to get the real memory address and don't create a new pointer
void print_pointer(T*& pointer_i){
	if(pointer_i != nullptr){
		std::cout << "Your pointer points to " << pointer_i;
	    std::cout << " with the value -> " << *pointer_i;
	    std::cout << " pointer memory asdress -> " << &pointer_i;
	    std::cout << std::endl;
	} else {
		std::cout << "Your pointer points to nothing!";
		std::cout << " pointer memory asdress -> " << &pointer_i;
		std::cout << std::endl;
	}
}

int main() {
	int* pointer_i = nullptr;
	auto* pointer_i2 = new std::int32_t{20};
	
	print_pointer(pointer_i);
	print_pointer(pointer_i2);
	
	delete pointer_i;
	delete pointer_i2;
}
```
Important: 'const' makes not the pointer constant but it's value address.



<br><br>

<a name="basics_references_" href="#bascis_top_">^</a><br>
**References**<br>
References is a C++ feature which is not avaiable in C. References are variables which refer to another variable. The following example shows 2 variables which both have the same value and changes on both variables impact the value of the other variable. Notice that references are written with a & after the datatyp.
```c++
int i = 42;
int& r = i;
```
Helpful are references for example mutable functions, where the function changes its input/parameter values without returning something (a function with sideeffect). All parameter/input values are new values/variables in C++ -> even objects! This can be changed with references or pointer. (Notice that a pointer will also be created new but points to the same memory address and therefore works.<br>
Key difference to pointer: references can't have/refer to no value (easier handling) and need less ressources than pointer, because the reference is just another name for the same variable, and the pointer need a own memory address and the value is the memory address where it points to.<br>


<br><br>

<a name="basics_arrays_" href="#bascis_top_">^</a><br>
**Arrays**<br>
Arrays is a collection of n elements of the same datatype. An array can be thought as a primitive form of an list.<br>
Create and acces an array:
```c++
int arr_1[5] = {23, 4, -1, 34, 4};
int arr_2[5];
arr_2[0] = 12;

// heap allocated array
int* arr_3 = new int[5]{23, 4, -1, 34, 4};
```
Most important: arrays does not check for boundary and so can a wrong index cause memory corruption.<br>
An array is just a pointer to a memory address and is an old datatyp which should be replaced with newer versions of C++, but before we see these lets understand the access over the brackets.<br>
The number in the bracket by creating the array is from type size_t and defines how much memory/elements must be saved for the array. <br>
The number passed in the brackets during accessing an element just tells the compiler how much to count upwards to come to the element. So the arr variables points to one memory address and just adds a number to access another element, which is probably the reason, why an array can only keep values from the same datatyp.<br>
arr_1[0] == *(arr_1 + 0\*data_typ_size) -> arr_1 just returns the target memory address, though it is a pointer.

In modern C++ the old C-Style array is not the only option. The standard library also provides an array type and also vector and list types.
 - std::array -> constant array  (#include <array>)
 - std::vector -> dynamic array  (#include <vector>)
 - std::string -> dynamic char array  (#include <string>)
 
 std::array has a fixed size but provides some usefule methods:
 - size() -> Returns the number of elements (fixed at compile-time).
 - .at(index) -> Accesses an element with bounds checking. Throws exception if out of range.
 - .fill() -> Sets all elements to value.
 - .front() -> Returns the first element.
 - .back() -> Returns the last element.
 - .data() -> Returns a pointer to the first element (useful for C-style functions).
 ```c++
 #include <array>
 
 int main() {
 	std::array<int, 5> arr;
 	arr.fill(0);
 }
 ```
 
 The dynamic array (std::vector) is also a very useful datatype. The vector is a list, with no fixed size.
 ```c++
 #include <vector>
 
 int main(){
 	std::vector<int> vec = {1, 2};
 	vec.push_back(3);	// add an element
 }
 ```
Methods for Accesss:
 - .at(i) -> Access element (with bounds check)
 - .front() -> Returns the first element.
 - .back() -> Returns the last element.
 - .data() -> Returns a pointer to the first element (useful for C-style functions).
 
 Methods for modifying:
 - .push_back(x) -> Adds an value to the vector
 - .insert(pos, x) -> Adds an element on the given position
 - .pop_back() -> Remove last element
 - .erase(pos) -> Remove element at position
 - .clear() -> Remove all elements
 
 Methods for Size & Capacity
 - .size() -> Returns the number of elements
 - .capacity() -> Returns the allocated memory size
 - .resize(n) -> Resizes to n elements
 - .shrink_to_fit() -> Reduces capacity to match size
 - .reserve(n) -> Allocates memory for at least n elements (prevents reallocation overhead)
 
 Methods for Iterators:
 - .begin() -> Iterator to the first element
 - .end() -> Iterator to one past the last element
 - .rbegin() -> Reverse iterator (last element)
 - .rend() -> Reverse iterator (before first)
 
 Methods for Utility:
 - .empty() -> Returns true if vector is empty
 - .swap(otherVec) -> Swaps contents with another vector
 - .assign(n, x) -> Assigns n copies of x
 
 ```c++
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Basic Access
    std::cout << vec[2] << std::endl;  // Direct access (no bounds check)
    std::cout << vec.at(2) << std::endl; // Safe access (with bounds check)

    // Adding Elements
    vec.push_back(6);   // Adds 6 at the end
    vec.insert(vec.begin() + 2, 99); // Inserts 99 at index 2

    // Removing Elements
    vec.pop_back();    // Removes last element
    vec.erase(vec.begin() + 1); // Removes element at index 1

    // Size and Capacity
    std::cout << "Size: " << vec.size() << std::endl; // Number of elements
    std::cout << "Capacity: " << vec.capacity() << std::endl; // Memory allocated

    // Iterating Over Elements
    for (int num : vec) {
        std::cout << num << " ";  // Prints all elements
    }

    return 0;
}
 ```
 
 Lastly lets see methods of the string datatype.
 
 Methods for Accesss:
 - .at(i) -> Access element (with bounds check)
 - .front() -> Returns the first element.
 - .back() -> Returns the last element.
 - .data() -> Returns a pointer to the first element (useful for C-style functions).
 
 Methods for modifying:
 - .append(x) -> Adds an value to the string
 - .insert(pos, x) -> Adds an element on the given position
 - .erase(pos) -> Remove element at position
 - .replace(pos, len, x) -> Replace len chars from pos with x
 - .clear() -> Remove all elements
 
 Methods for searching and finding:
 - .find(x) -> Finds x (returns index or std::string::npos if not found)
 - .rfind(x) -> Finds last occurrence of x
 - .find_first_of(x) -> Finds first occurrence of any char in x
 - .find_last_of(x) -> Finds last occurrence of any char in x
 - .find_first_not_of(x) -> Finds first character not in x
 - .find_last_not_of(x) -> Finds last character not in x
 
 Methods for Extracting & Manipulating Substrings:
 - .substr(pos, len) -> Extract substring
 - .compare(x) -> Compare with another string (==, >, <)
 - .c_str() -> Convert to C-style string (const char*)
 
 Methods for Size & Capacity:
 - .length() -> Returns the number of characters
 - .size() -> Same as .length()
 - .capacity() -> Returns allocated memory size
 - .shrink_to_fit() -> Reduces capacity to fit size
 - .reserve(n) -> Allocates memory for n characters (prevents reallocations)
 
 Methods for Checking & Comparing:
 - .empty() -> Returns true if string is empty
 - str == x -> Checks equality
 - str != x -> Checks inequality
 
 Functions of String Module:
 - std::to_string(num) -> Converts number to string
 - std::stoi(str) -> Converts string to int
 - std::stof(str) -> Converts string to float
 - std::stod(str) -> Converts string to double
 
 
 ```c++
 #include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";

    // Accessing Characters
    std::cout << str[0] << std::endl;   // H (no bounds check)
    std::cout << str.at(1) << std::endl; // e (with bounds check)

    // Modifying String
    str.append("!!!");   // Adds "!!!" at the end
    str.insert(5, " C++"); // Inserts " C++" at index 5
    str.erase(5, 4);      // Removes 4 characters starting from index 5

    // Searching
    size_t pos = str.find("World"); // Finds "World" (returns index)
    size_t notFound = str.find("XYZ"); // Returns std::string::npos

    // Extracting Substring
    std::string sub = str.substr(7, 5); // "World"

    // Conversion
    std::string numStr = std::to_string(123); // Converts 123 -> "123"

    // Checking Length
    std::cout << "Length: " << str.length() << std::endl;

    return 0;
}
 ```
 
 
 <a name="basics_collections_" href="#bascis_top_">^</a><br>
**Collections**<br>
 We previously saw some important collections like the **Vector**. Here are some more.
 
 A **linked list** is a collection of pointers. So every element can be in another place in the memory.
 
 ```c++
 #include <list>
 std::list<int> my_list;
 my_list.push_back(4);
 my_list.push_back(6);
 my_list.push_back(8);
 ms_list.push_front(2);
 ```
 
 Another collection is the **Queue** which works with the FIFO (first in, first out). It is like a queue on a icecream shop.
 
 ```c++
 #include <queue>
 std::queue<int> my_q;
 my_q.push(10);
 my_q.push(20);
 my_q.front();    // returns the current first obj/data in the queue but does not remove it
 my_q.pop();    // return and remove first elem in the queue
 ```
 
 The opposite is the **Stack**. It works with the LIFO priciple (last in, first out). The last element which got added will be the first which get out from the stack. Like a stack of papers on a table of a busy worker in the 80s.
 
 ```c++
 #include <stack>
 std::stack<int> my_stack;
 my_stack.push(10);
 my_stack.push(20);
 my_stack.top();    // only return the current first elem
 my_stack.pop();    // returns and removes the first (last added) elem
 ```
 
 Most performant data structures are the maps and hash maps. The difference is that maps are ordered and hash maps using hashing to allow unordered lists. They work with a key which lead to a value...like a dictionary.
 
 ```c++
 #include <map>
 std::map<int,std::string> months;
 months.emplace(1, "Januray");
 months.emplace(2, "February");
 
 std::cout << month[2];
 ```
 
 Hash-maps:
 ```c++
 #include <unoredered_map>
 std::unordered_map<int, std:.string> months;
 months.emplace(1, "Januray");
 months.emplace(2, "February");
 
 std::cout << month[2];
 ```
 
 Important for collections is to itterate over them and this is sometimes not easy possible. For that we can use **Iterator** which are objects which help to traverse the object.
 
 ```c++
 std::list<int> numbers; 
 numbers.emplace_back(2); 
 numbers.emplace_back(4); 
 numbers.emplace_back(6); 
 
 for (std::list<int>::iterator iter = numbers.begin();    iter != numbers.end();    ++iter) {
 	std::cout << *iter << std::endl; 
 }
 ```
 
 For maps:
 ```c++
 // Get an iterator to the element with the key 2 
 std::map<int, std::string> iter = months.find(2); 
 
 if (iter != months.end()) // This is only true if found {
 	std::cout << iter->first << std::endl; // Outputs 2
 	std::cout << iter->second << std::endl; // Outputs February
 }
 ```
 
 
 

<br><br>

<a name="basics_templates_" href="#bascis_top_">^</a><br>
**Templates**<br>
...


<br><br>

<a name="basics_namespaces_" href="#bascis_top_">^</a><br>
**Namespaces and Header Files**<br>
Namespaces are scopes in which are given variable names and function names set/available. <br>
You can also defining your own namespaces:
```c++
namespace my_namespace{
	// define here classes, functions, variables and more ...
}
```
Then the structures and variables are usable under the namespace name -> my_namespace::my_func();

If you want to use a another namespace / another library, you can import namespaces from the standard library (std) or from your own namespaces or external libraries.<br>
using the std namespace is direct available by:
```c++
#inculde <iostream>
// there are more namespaces in std!
...
```
External libraries or own code import need a header file (.h or .hpp).
These files define what the namespace contains. Notice that both the usage file and the defining file have to import the header file.
See this example:
compute.cpp:
```c++
#include "compute.h"

namespace math_utils {
    double computeArea(double radius) {
        return PI * radius * radius;  // Use the constant
    }
}
```

compute.h:
```c++
#pragma once    // stopps double imports

namespace math_utils {
    constexpr double PI = 3.14159265358979;  // Constant definition
    double computeArea(double radius);      // Function declaration
}
```

main.cpp:
```c++
#include <iostream>
#include "compute.h"

int main() {
    double radius = 5.0;
    double area = math_utils::computeArea(radius);  // Call function

    std::cout << "Circle with radius " << radius << " has area: " << area << std::endl;
    std::cout << "Using constant PI: " << math_utils::PI << std::endl;
    
    return 0;
}
```

Definitions inside the header file can be used also in the file which is linked to it! Example Game.h:
```c++
#pragma once

#include <cstdint>

// some definitions which can be directly used from linked file!
struct Coordinate {
   std::uint32_t x;
   std::uint32_t y;
};

enum class ConsoleInput {
   INVALID,
   LEFT,
   RIGHT,
   UP,
   DOWN
};


// functions defined by the linked Game.cpp file

void print_field(const Coordinate& player_position);
bool is_finish(const Coordinate& player_position);
void execute_move(Coordinate& player_position, const char move);
void play_game();
```

You can also import all names from a namespace with:
```c++
using namespace std;
```

But this is not recommended!

Also a unnamed namespace is only available for the current file -> so like a private variables, functions, ...
```c++
namespace{
auto my_private_int = 45;
//...
}

std::cout << my_private_int;
```

Overall namespaces give you easy control to what to export and what not and can be used differently and flexible.

Last notice: If you want to have one namespace with multiple libraries, like the std, then you can simply write a .cpp and a .h file for every lib and in the .h file you write the variables and functions to import inside a namespace and name this namespace like you want to name your lib.<br>
The opposite approach is also possible, that in the header file is no namespace but in the .cpp file you wrap everything inside your lib name namespace.<br>
It is also possible to have multiple header files from one file, so you could also create multiple namespaces from one file.<br>
As you might see, there are many possible ways how to implement your code. Namespaces are just a logic which can be used very flexible.

<br><br>

<a name="basics_std_" href="#bascis_top_">^</a><br>
**Standard Library (STD):**
It follows a overview about most namespaces of std, you can search online if you are interesting in one of them.<br>
Notice that all of these libraries are in the std namespace but get first loaded/imported if the specific lib is imported. This is practically done by defining different header files (for every lib one header file). 

Input/Output & Streams
- \<iostream\> – Standard I/O (cin, cout, cerr)
- \<fstream\> – File input/output streams
- \<sstream\> – String stream manipulation

Containers & Data Structures
- \<vector\> – Dynamic array (fast random access)
- \<array\> – Fixed-size array wrapper
- \<deque\> – Double-ended queue
- \<list\> – Doubly linked list
- \<forward_list\> – Singly linked list
- \<map\> – Sorted associative key-value container (RB-tree)
- \<unordered_map\> – Unordered key-value container (hash table)
- \<set\> – Sorted unique collection (RB-tree)
- \<unordered_set\> – Unordered unique collection (hash table)
- \<stack\> – LIFO stack
- \<queue\> – FIFO queue
- \<priority_queue\> – Heap-based priority queue
- \<tuple\> – Fixed-size heterogeneous collection

Algorithms & Utility Functions
- \<algorithm\> – Sorting, searching, min/max, transformations
- \<numeric\> – Numeric operations (accumulate, inner_product)
- \<functional\> – Function objects, lambda utilities
- \<utility\> – std::pair, std::move, std::forward, etc.
- \<ranges\> (C++20) – Range-based algorithms

Strings & Localization
- \<string\> – std::string, std::wstring
- \<string_view\> (C++17) – Non-owning string reference
- \<charconv\> (C++17) – Fast number-to-string conversion
- \<locale\> – Localization utilities
- \<codecvt\> (Deprecated in C++17) – Unicode conversions

Memory Management
- \<memory\> – Smart pointers (std::unique_ptr, std::shared_ptr)
- \<scoped_allocator\> – Memory allocation policies
- \<new\> – Low-level memory allocation (operator new)

Concurrency & Parallelism
- \<thread\> – Thread management
- \<mutex\> – Mutual exclusion locks
- \<shared_mutex\> (C++17) – Shared/read-write mutex
- \<atomic\> – Atomic operations (lock-free programming)
- \<condition_variable\> – Thread synchronization
- \<future\> – Asynchronous execution (std::async, std::promise)
- \<stop_token\> (C++20) – Stopping threads gracefully

Time & Date
- \<chrono\> – Time utilities (C++11)
- \<ctime\> – C-style time functions

Type information & Reflection
- \<type_traits\> – Type checking and manipulation (std::is_same, std::enable_if)
- \<typeinfo\> – Runtime type information (RTTI, typeid)
- \<concepts\> (C++20) – Constraints for templates

Math & Randomization
- \<cmath\> – Standard math functions (sin, cos, sqrt)
- \<random\> – Pseudo-random number generation
- \<numbers\> (C++20) – Mathematical constants like π and e

Filesystem & OS Interaction
- \<filesystem\> (C++17) – File and directory operations
- \<system_error\> – Error codes and exceptions
- \<cstdlib\> – C-style utilities (malloc, rand, exit)

Error Handling
- \<exception\> – Base exception classes
- \<stdexcept\> – Common exceptions (std::runtime_error, std::out_of_range)
- \<cassert\> – Debugging assertions
- \<cerrno\> – C-style error handling (errno)

Regular Expressions
- \<regex\> – Regular expressions

Networking
- \<net\> – Networking library

Coroutines
- \<coroutine\> – Coroutine support

<br><br>

<a name="basics_classes_" href="#bascis_top_">^</a><br>
**Classes**<br>
In object oritented programming, classes describe a class of which objects can be created. They get created in the heap with the new keyword, which calls the constructor method of the class. The destructor method will be called when the object is delected.<br>
Classes/Objects have the advantage of creating own data structures with well isolated methods.<br>
Passing an object to a function can be very ressource harming, due to the fact that functions always create a copy of the parameter. An common used practise is to pass an object with as **const reference** (const ClassName& var_name), this makes sure that the object can't get changed and it is the real object (not an copy).<br>
The access to attributes and functions is normally an '.' but if your object is an pointer than you need an '->' for accessing the variables and functions of your object.

Example class:
```c++
class Complex{
public:
	// Constructor
	Complex(float real, float imaginary)
	:mReal(real) ,mImaginary(imaginary) {    // efficient init listing
	// ...
	}
	
	void Negate() {
		// ...
	}
	
private:
	float mReal;
	float mImaginary;
};

Complex* c = new Complex(1.0f, 2.0f);

c->Negate();
```

Let's watch another example with destructor:

```c++
class AwesomeArray {
public:
	// Constructor
	AwesomeArray(int size):mSize(size){
		this.mArray = nullptr;
		this.mArray = new int[mSize];
	}
	// Destructor
	~AwesomeArray(){
		delete[] this.mArray 
	}
	
	// MEthods
	int& at(int index){
		return this.mArray[index];
	}

private:
	int mSize;
	int* mArray;
}
```

With this-> you can access an objects attributes and functions. If not setted the compiler will take a local attribute with this name and if there is no then taking the attribute from the class.

There are also copy constructors which takes one object from the same class and gives a new object with the same values. C++ creates a copy method automatically but in case you use pointer you should write it by yourself, because the pointers will still reference to the same object -> calles shallow copy.<br>
Self declared deep copy constructor:

```c++
class AwesomeArray{
public:
	//...
	
	AwesomeArray(const AwesomeArray& other_obj) {
		mSize = other_obj.mSize;
		mArray = new int[mSize];
		for (int i=0; i < mSize; ++i){
			mArray[i] = other_obj.mArray[i];
		}
	}
}
```

Classes which handle dynamic allocated data (pointer, arrays, ...) should always define a destructor, copy constructor and  assignment operator. -> **rule of three**

Assignment operator are methods which define the behaviour if common signes like the + are used with the object. Here an example with the + sign. Notice that it have an + after the method name (our target sign) and it has the keyword 'friend' which defines that it can be used without an object (standalone).

```c++
friend Complex operator+(const Compley& a, Complex& b){
	return Complex(a.mReal + b.mReal, a.mImaginary+b.Imaginary);
}

Compley result = c1+c2;
```

There is also operator== for example. You can overload / define a behaviour for most likely any sign using the operator method. For example the stream lib from std does this with the \>\> signs to connect outputs.


<br><br>

<a name="basics_best_practises_" href="#bascis_top_">^</a><br>
**Best Practises**

Parameters:
- Pass non-basic data types as reference, const, reference or pointer(s) -> to avoid making a copy
- Pass a variable always with a const if the function should not change it
- ...




<br><br>

<a name="basics_examples_" href="#bascis_top_">^</a><br>
**Examples**<br>
It follows some example cpp files.

- [Hello World](./00_hello_world/main.cpp)
- Variables, Datatypes and Logic
  - [Variables](./src/basics/01_variables_datatypes_logic/variables.cpp)
  - [Data Types](./src/basics/01_variables_datatypes_logic/datatypes.cpp)
  - [User Input](./src/basics/01_variables_datatypes_logic/user_input.cpp)
  - [If Else](./src/basics/01_variables_datatypes_logic/if_else.cpp)
  - [Ternary](./src/basics/01_variables_datatypes_logic/ternary_operator.cpp)
  - [For Loops](./src/basics/01_variables_datatypes_logic/for_loop.cpp)
  - [While Loops](./src/basics/01_variables_datatypes_logic/while_loop.cpp)
  - [Functions](./src/basics/01_variables_datatypes_logic/functions.cpp)
  - [Recursion](./src/basics/01_variables_datatypes_logic/recursion.cpp)
  - [Overloaded Funtions](./src/basics/01_variables_datatypes_logic/function_overloading.cpp)
  - [Templates](./src/basics/01_variables_datatypes_logic/template.cpp)
  - [Pre and Post Increment](./src/basics/01_variables_datatypes_logic/post_and_pre_increment.cpp)
  - [Constant Variables](./src/basics/01_variables_datatypes_logic/const.cpp)
  - [Static Local Variables](./src/basics/01_variables_datatypes_logic/static_local_var.cpp)
  - [Casting](./src/basics/01_variables_datatypes_logic/casting.cpp)
  - [Auto Keyword](./src/basics/01_variables_datatypes_logic/auto_keyword.cpp)
- Arrays, Pointer and References
  - [Arrays](./src/basics/02_pointer_and_arrays/arrays.cpp)
  - [Strings](./src/basics/02_pointer_and_arrays/string.cpp)
  - [Multidimensionale Arrays](./src/basics/02_pointer_and_arrays/multidimensional_arrays.cpp)
  - [Arrays in C++ Style](./src/basics/02_pointer_and_arrays/arrays_cpp_style.cpp)
  - [Pointer](./src/basics/02_pointer_and_arrays/pointer.cpp)
  - [Heap in C Style](./src/basics/02_pointer_and_arrays/heap_c_style.cpp)
  - [Nullpointers](./src/basics/02_pointer_and_arrays/nullpointers.cpp)
  - [Pointer Arrays](./src/basics/02_pointer_and_arrays/pointer_arrays.cpp)
  - [References](./src/basics/02_pointer_and_arrays/references.cpp)
  - [Argc and Argv](./src/basics/02_pointer_and_arrays/argc_argv.cpp)
- Enums, Structs and Namespaces
    - [Enum and Switch (C-Style)](./src/basics/03_enum_structs_and_namespaces/Enum_and_Switch.cpp)
    - [Enum Class](./src/basics/03_enum_structs_and_namespaces/Enum_Class.cpp)
    - [Structures](./src/basics/03_enum_structs_and_namespaces/Struct.cpp)
    - [Namespaces](./src/basics/03_enum_structs_and_namespaces/Namespaces.cpp)
- ...



Games/Projects:
- [Guessing Game](./games/guessing_game/)
- [Game 1](./games/computer_game_1/)
- [Game 2](./games/computer_game_2/)
- ...





---
<h3><a href="#top" name="installation_">Installation of GNU Compiler Collection</a></h3>

Most used compiler is the GNU Compiler Collection (GCC). It is used to compile cpp code to executable code.

<!--
- Download a C++ Compiler in **Windows**:
    - https://cygwin.com/install.html
    - make sure to install following extension (use the search bar，choose a version and click that it should get download):
        - cygwin-devel
        - gcc-g++
        - gcc-core
        - make
        - cmake
        - gdb
        - git
        - python39
        - autoconf
        - automake
        - libtool
        - ninja
        - xorg-server
		- libX11-devel
		- libXext-devel
		- libXrandr-devel
		- libXrender-devel
		- libXcursor-devel
		- libXinerama-devel
		- libXi-devel
		- libXss-devel
		- libgcc1
		- libstdc++6
    - Add cygwin to the system path variables. Then you can use the normal cmd or Powershell or the terminal in Visual Studio Code.<br>To do so，you have to search/open the system-variables (environment variables). There you search the entry "Path", there should be already some paths. To these paths you add the path of Cygwin bin folder, probably: **C:\cygwin64\bin** <br>And now it should work. Maybe a restart is requirement, if it doesn't works.
    
    - Testing (in Cygwin and or normal terminal): 
    ```terminal
    make --version
    gdb --version
    gcc --version
    g++ --version
    ```
    
> You can download additional packages by running the setup file again. It will only install the new packages.

-->
    
- Download a C++ Compiler in **Windows**:
	- Download MinGW on: https://winlibs.com/
    - Unzipping in a path you like
    - Add MinGW to the system path variables. Then you can use the normal cmd or Powershell or the terminal in Visual Studio Code.<br>To do so，you have to search/open the system-variables (environment variables). There you search the entry "Path", there should be already some paths. To these paths you add the path of MinGW bin folder, probably: **C:\MinGW\bin** <br>And now it should work. Maybe a restart is requirement, if it doesn't works.
    - Download [Ninja](https://ninja-build.org/) -> download the win-zip file + also add the path to ninja.exe to the system path as decribed before




- Download a C++ Compiler in **Linux**:
    - Installation: 
    ```terminal
    sudo apt-get update
    sudo apt-get upgrade
    sudo apt-get install make
    sudo apt-get install gdb
    sudo apt-get install gcc
    sudo apt-get install g++
    sudo apt-get install git
    sudo apt-get install cmake
    sudo apt-get install autoconf
    sudo apt-get install automake
    sudo apt-get install libtool
    sudo apt-get install ninja
    ```
    - Testing: 
    ```terminal
    gdb --version
    gcc --version
    g++ --version
    ```



---
<h3><a href="#top" name="runcppcode">Run C++ Code (with g++)</a></h3>

The GNU Compiler Collection (GCC) is a standard compiler for c and c++ and here you see how to use it.



Most simple way to compile a C++ program with GCC is to create a **make** file and use make to compile your C++-Files (for this you can install cygwin in Windows to use make <a href="#installation_">see here</a>):
```terminal
# Compiler
CXX = g++  # Use this if you're using MinGW or Cygwin

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# List of source files
SRCS = main.cpp file1.cpp file2.cpp

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Name of the output executable
TARGET = my_program.exe

# Default target: build the executable
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

```

The Makefile is just a plain textfile without a file type ending. Just name the file "Makefile" and execute it with "mingw32-make" (or "make" if not on windows).



Another way is to type following in a terminal:
1. First you compile your program and create a executeable file:
    - ```terminal
      g++ main.cpp -o main
      ```
    - If you have multiple C++ Files you can do:
    ```terminal
    g++ -o main main.cpp game.cpp
    ```
    or:
    ```terminal
    g++ -c main.cpp
    g++ -c game.cpp
    g++ -o main main.o game.o
    ```
2. Then you can execute it:
    ```terminal
    ./main.exe
    ```
    Or in Linux:
    ```terminal
    ./main
    ```



> Hint:<br>Use the terminal and navigate with cd .. and cd 01_variables_datatypes_logic to the right folder.<br>You also can type 00 and then tab-key to use auto completion.



In Depth:
- assemble:
```terminal
g++ -S program.cpp
```
- compile:
```terminal
g++ -c program.cpp -o program.o
```
- build:
```terminal
g++ program.o -o program
```


> You can add a parameter at the beginning of every command to specify how much the code should be optimized. For debugging it is common to not optimize your code to can analyze your code.<br>For Debugging: g++ -O0 -g3 ...<br>For Release: g++ -O3 ...







---
<h3><a href='#top' name='cmake_'>Using CMake</a></h3>

In bigger project it is recommended to use CMake. It generates the Makefile and than uses the Makefile to build your application.

For installation on Windows:
1. Go to https://cmake.org/download/
2. Download the windows installer
3. execute it and make sure it added to the system variables

If it got not added to the system variables:
1. Open the system variables (environment variables/Umgebungsvaribalen)
2. go to global -> 'Path'
3. add a new entry with the path to your CMake bin folder


For installation on Linux:
```terminal
sudo apt update
sudo apt install cmake
cmake --version
```





---
<h3><a href='top' name='ide_'>Using an IDE</a></h3>

There are many IDEs for C++ out there. I recommend VSCode or for a few more features Eclipse.<br>
VSCode can be used right away (I recommend to use the Project Manager Extension) with maybe a C/C++ extension.<br>
For eclipse see this:


For installation on Windows:
1. Go to https://www.eclipse.org/downloads/
2. Download the windows installer for Eclipse desktop
3. Follow the instructions of the installer and make sure to choose C/C++ Developement.



For installation on Linux:
```terminal
sudo apt update
sudo apt install eclipse-cdt
```


> Important hint: If you want to use git and github, make sure to go to developer settings and to personal access tokens. There you can create a new token with a name and a password/token. This is needed from Eclipse to authentificate with your account and only so you can use eclipse with git/github. Your normal user name and password will not work.





---













