#pragma once
#include <cstdint>

class Sensor {
public:
    explicit Sensor(uint32_t seed = 12345);
    float read(); // °C
private:
    uint32_t state_;
};
