#include <iostream>

// Name
//     description
//     size or amount of values

// 1 Byte = 8 Bit => 2^8 = 256 possible Values
// 2 Byte = 16 Bit => 2^16 =~ 65000 possible Values
// 4 Byte = 32 Bit => 2^32 =~ 4.000.000.000 possible Values
// ...

// Attention: The value range can vary depend on the base system (32/64 Bit Systeme).

/*
 * ### Fundamental Data Types in C++ ###
 *
 * 1. **char**
 *    - Size: Typically 1 byte (8 bits)
 *    - Range: -128 to 127 (signed), 0 to 255 (unsigned)
 *    - Description: Represents a single character. Used for text processing.
 *
 * 2. **int**
 *    - Size: Typically 4 bytes (32 bits)
 *    - Range: -2,147,483,648 to 2,147,483,647 (signed), 0 to 4,294,967,295 (unsigned)
 *    - Description: The most commonly used integer type. Default for integer literals.
 *
 * 3. **short**
 *    - Size: At least 2 bytes (16 bits)
 *    - Range: -32,768 to 32,767 (signed), 0 to 65,535 (unsigned)
 *    - Description: A smaller integer type, used to save memory.
 *
 * 4. **long**
 *    - Size: At least 4 bytes (32 bits), often 8 bytes (64 bits) on modern systems
 *    - Range: -2,147,483,648 to 2,147,483,647 (32-bit signed), larger for 64-bit
 *    - Description: Used when a wider range than int is required.
 *
 * 5. **long long**
 *    - Size: At least 8 bytes (64 bits)
 *    - Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (signed), 0 to 18,446,744,073,709,551,615 (unsigned)
 *    - Description: For even larger numbers than long.
 *
 * 6. **float**
 *    - Size: Typically 4 bytes (32 bits)
 *    - Precision: About 7 decimal digits
 *    - Range: ~1.2e-38 to 3.4e+38
 *    - Description: Single precision floating-point. Used for saving space when less precision is acceptable.
 *
 * 7. **double**
 *    - Size: Typically 8 bytes (64 bits)
 *    - Precision: About 15-16 decimal digits
 *    - Range: ~2.2e-308 to 1.8e+308
 *    - Description: Double precision floating-point. Standard for floating-point calculations.
 *
 * 8. **long double**
 *    - Size: At least as large as double, often larger
 *    - Precision: Typically more precision than double, depending on the implementation
 *    - Description: Extended precision floating-point. Used when very high precision is required.
 *
 * 9. **bool**
 *    - Size: Typically 1 byte
 *    - Values: true or false
 *    - Description: Represents Boolean logic values. Used for conditions and logical operations.
 *
 * 10. **wchar_t**
 *     - Size: Platform-dependent (often 2 or 4 bytes)
 *     - Description: Represents wide characters, used for international character sets (like Unicode).
 *
 * 11. **char16_t**
 *     - Size: 2 bytes
 *     - Description: Used for UTF-16 character encoding.
 *
 * 12. **char32_t**
 *     - Size: 4 bytes
 *     - Description: Used for UTF-32 character encoding.
 */

// ASCII: 48 = 0, 65 = A, 97 = a


int main(){

    // Boolean
    //     Binary Value
    //     1 Byte
    bool is_running = true;
    bool should_rain = false;

    // Char
    //     Single letter/string value (-> it is just a numerical type)
    //     1 Byte
    char kind = 'A';
    char other_char = 230;
    std::cout << kind << " ASCII-Number:" << (int)kind << std::endl;
    kind += 10;
    std::cout << kind << " ASCII-Number:" << (int)kind << std::endl;

    // Short
    //     Small number value
    //     2 Byte
    //     -32768 - 32767 (signed)
    //     0 - 65535 (unsigned)
    short level = 300;
    short short_1 = -32768;
    unsigned short short_2 = 65535;

    // Integer
    //     Number value
    //     4 Byte
    //     -2147483648 - 2147483647 (signed)
    //     0 - 4294967295 (unsigned)
    int my_int = 34567;
    int my_int_2 = 1'000'000'000;   // the ' can be used as visiual help
    int my_small_int = -2147483648;
    unsigned int my_big_int = 4294967295;

    // Long Long
    //     Big number value
    //     8 Byte
    //     On 64 bit systems:
    //     -9223372036854775808 - 9223372036854775807 (signed)
    //     0 - 18446744073709551615 (unsigned)
    //     On 32 bit systems:
    //     -2147483648 - 2147483647 (signed)
    //     0 - 4294967295 (unsigned)
    long long my_long = 234;
    long long my_long_2 = 1'000'000'000LL;   // you can use L to show that it is a long long
    long long my_long_3 = -2147483648;
    unsigned long long my_big_long = 18446744073709551614ULL;    // use ULL to make sure it is an unsigned long long

    // Float
    //     Float number value
    //     4 Byte
    //     1.2e-38 - 3.4e+38 (for positive values)
    //     -3.4e+38 - -1.2e-38 (for negative values)
    float my_float_1 = 23.45;
    float my_float_2 = 3.567f;    // you can use f to show that it is a float value
    float my_float_3 = 1.23e4f;   // scientific notation (1.23 x 10^4)

    // Double
    //     Big float number value
    //     8 Byte
    //     2.2e-308 - 2.2e+308 (for positive values)
    //     -2.2e+308 - -2.2e-308 (for negative values)
    double pi = 3.141592653589793;
    double negative = -123.456;
    double scientific = 1.23e-4;


    // Fixed Datatype
    //     depending on our system it chooses the right datatype to make sure the amount of bit
    std::uint8_t unsigned_int_8 = 255;
    std::uint16_t unsigned_int_16 = 65535;
    std::uint32_t unsigned_int_32 = 4294967295;
    // std::uint64_t unsigned_int_64 = 18446744073709551615;

    std::int8_t signed_int_8 = 127;
    std::int16_t signed_int_16 = 32767;
    std::int32_t signed_int_32 = 2147483647;
    std::int64_t signed_int_64 = 9.223372036854775e+18;


    return 0;
}


