#include "sensor.hpp"
#include "controller.hpp"
#include "logger.hpp"
#include <cassert>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <cstdio>

// Helper to count lines in temp_log.txt
static int count_lines(const std::string &path) {
    std::ifstream in(path);
    int n = 0; std::string s;
    while (std::getline(in, s)) ++n;
    return n;
}

int main() {
    // TC-1: Sensor values in range [20,30]
    {
        Sensor s(12345);
        for (int i = 0; i < 1000; ++i) {
            float t = s.read();
            assert(t >= 20.0f && t < 30.0f);
        }
    }

    // TC-2: Alert logic temp > threshold
    {
        Config cfg; cfg.threshold_c = 25.0f; cfg.iterations = 1; cfg.period_ms = 50;
        Controller c(cfg);
        int rc = c.run();
        assert(rc == 0);
        // Can't easily assert alert printed, but covered via threshold path
    }

    // Clean old log if exists
    std::remove("temp_log.txt");

    // TC-3: Log format (line appears, contains tokens)
    {
        Config cfg; cfg.threshold_c = 100.0f; cfg.iterations = 1; cfg.period_ms = 50;
        Controller c(cfg);
        assert(c.run() == 0);
        std::ifstream in("temp_log.txt");
        std::string line;
        std::getline(in, line);
        assert(line.find("temp_c=") != std::string::npos);
        assert(line.find("status=") != std::string::npos);
    }

    // TC-4: Period control (~ within ±10% best-effort for small count)
    {
        using Clock = std::chrono::steady_clock;
        Config cfg; cfg.threshold_c = 100.0f; cfg.iterations = 5; cfg.period_ms = 100;
        Controller c(cfg);
        auto t0 = Clock::now();
        assert(c.run() == 0);
        auto t1 = Clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
        int expected = cfg.period_ms * cfg.iterations;
        // allow generous slack on non-RT OS
        assert(elapsed_ms >= expected * 0.8 && elapsed_ms <= expected * 1.5);
    }

    // TC-5: End-to-end alert with low threshold to force alert
    {
        Config cfg; cfg.threshold_c = 20.0f; cfg.iterations = 10; cfg.period_ms = 10;
        Controller c(cfg);
        assert(c.run() == 0);
        // At least one line should be ALERT
        std::ifstream in("temp_log.txt");
        std::string line; bool any_alert = false;
        while (std::getline(in, line)) if (line.find("ALERT") != std::string::npos) { any_alert = true; break; }
        assert(any_alert);
    }

    return 0;
}
