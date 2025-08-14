#include "controller.hpp"
#include <chrono>
#include <thread>
#include <cmath>
#include <stdexcept>

using Clock = std::chrono::steady_clock;

Controller::Controller(const Config &cfg)
    : cfg_(cfg), sensor_(cfg.seed), logger_("temp_log.txt") {}

int Controller::run() {
    auto start = Clock::now();
    auto next = start;
    int count = 0;
    while (cfg_.iterations == 0 || count < cfg_.iterations) {
        auto now = Clock::now();
        double ts = std::chrono::duration<double>(now.time_since_epoch()).count();

        float temp = sensor_.read();
        bool is_alert = should_alert(temp);
        try {
            logger_.write(ts, temp, is_alert); // LLR-4
        } catch (...) {
            return 1; // LLR-6
        }
        if (is_alert) alert_.trigger(temp); // HLR-2

        // Period control (best-effort) LLR-5
        next += std::chrono::milliseconds(cfg_.period_ms);
        auto sleep_dur = next - Clock::now();
        if (sleep_dur.count() > 0) std::this_thread::sleep_for(sleep_dur);
        ++count;
    }
    return 0; // LLR-6
}
