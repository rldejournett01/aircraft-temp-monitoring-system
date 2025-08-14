#pragma once
#include <string>

class Logger {
public:
    explicit Logger(const std::string &path);
    void write(double timestamp_sec, float temp_c, bool alert);
private:
    std::string path_;
};
