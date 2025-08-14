#include "sensor.hpp"
#include <random>

// Simple deterministic LCG for reproducibility across platforms
static inline uint32_t lcg(uint32_t &s) {
    s = s * 1664525u + 1013904223u;
    return s;
}

Sensor::Sensor(uint32_t seed) : state_(seed) {}

float Sensor::read() {
    // Map LCG to [20.0, 30.0] °C
    uint32_t r = lcg(state_) >> 8;
    float unit = (r % 10000) / 10000.0f; // [0,1)
    return 20.0f + unit * 10.0f;
}
