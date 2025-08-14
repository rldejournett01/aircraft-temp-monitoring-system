#pragma once
#include "sensor.hpp"
#include "logger.hpp"
#include "alert.hpp"
#include <cstdint>

struct Config {
    float threshold_c = 27.0f;
    int period_ms = 1000;
    int iterations = 0; // 0 = infinite
    uint32_t seed = 12345;
};

class Controller {
public:
    explicit Controller(const Config &cfg);
    int run(); // 0 on success, non-zero on fatal error
private:
    Config cfg_;
    Sensor sensor_;
    Logger logger_;
    Alert alert_;

    bool should_alert(float temp) const { return temp > cfg_.threshold_c; } // LLR-3
};
