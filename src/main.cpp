#include "controller.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static void usage(const char* prog) {
    std::cout << "Usage: " << prog << " [--threshold FLOAT] [--period_ms INT] [--iterations INT] [--seed UINT]\n";
}

int main(int argc, char** argv) {
    Config cfg{};
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        auto need = [&](int more){ if (i+more >= argc) { usage(argv[0]); return false; } return true; };
        if (arg == "--threshold") { if (!need(1)) return 2; cfg.threshold_c = std::stof(argv[++i]); }
        else if (arg == "--period_ms") { if (!need(1)) return 2; cfg.period_ms = std::stoi(argv[++i]); }
        else if (arg == "--iterations") { if (!need(1)) return 2; cfg.iterations = std::stoi(argv[++i]); }
        else if (arg == "--seed") { if (!need(1)) return 2; cfg.seed = static_cast<uint32_t>(std::stoul(argv[++i])); }
        else { usage(argv[0]); return 2; }
    }
    // Input validation LLR-7
    if (cfg.threshold_c < 0.0f || cfg.threshold_c > 100.0f) { std::cerr << "Invalid threshold\n"; return 2; }
    if (cfg.period_ms < 50 || cfg.period_ms > 10000) { std::cerr << "Invalid period_ms\n"; return 2; }
    if (cfg.iterations < 0) { std::cerr << "Invalid iterations\n"; return 2; }

    Controller c(cfg);
    return c.run();
}
