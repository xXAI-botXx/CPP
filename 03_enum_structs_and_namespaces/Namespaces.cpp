#include<iostream>

/**
 * Namespaces defines a seperatated area, where definitions are only in this namespace.
 * This is useful to split data.
 * Moreover the same namespace can be used and added more data in multiple files, not only one.
 * 
 * So the programmer can decide whether he seperates the data over different files (without namespace)
 * or using namespace to seperate data.
 * Depending on the project both can be a good choice.
 */

namespace VHC {

    enum class VehicleType{
        TRAIN,
        PLANE,
        CAR,
    };

    struct Vehicle{
        int velocity;    // in km/h
        VehicleType vehicle_type;
    };

};


/**
 * A namespace without a name makes the content inside 
 * just visible for the current file (like the private keyword in Java)
 * 
 * An alternative is using static const, but the namespace way is better!
 */
namespace {

    int awesome_number = 164;

};

// using namespace VHC;

int main() {
    auto train_1 = VHC::Vehicle{.velocity=120, .vehicle_type=VHC::VehicleType::TRAIN};

    return 0;
}


