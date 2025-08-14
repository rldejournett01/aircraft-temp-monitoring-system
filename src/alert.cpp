#include "alert.hpp"
#include <iostream>

void Alert::trigger(float temp_c) {
    std::cout << "ALERT: High temperature detected (" << temp_c << " °C)\n";
}
