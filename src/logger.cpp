#include "logger.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

static std::string iso8601_now(double ts) {
    std::time_t t = static_cast<std::time_t>(ts);
    std::tm tm{};
#ifdef _WIN32
    gmtime_s(&tm, &t);
#else
    gmtime_r(&t, &tm);
#endif
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%SZ", &tm);
    return std::string(buf);
}

Logger::Logger(const std::string &path) : path_(path) {}

void Logger::write(double timestamp_sec, float temp_c, bool alert) {
    std::ofstream out(path_, std::ios::app);
    if (!out) throw std::runtime_error("Failed to open log file");
    out << iso8601_now(timestamp_sec) << ", temp_c=" << std::fixed << std::setprecision(2)
        << temp_c << ", status=" << (alert ? "ALERT" : "OK") << "\n";
}
