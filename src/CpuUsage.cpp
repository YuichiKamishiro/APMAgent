#include "CpuUsage.hpp"


CpuUsage::CpuUsage() {
    init();
}

double CpuUsage::getCurrentValue() {
    double percent;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    std::ifstream file("/proc/stat");
    if (!file.is_open()) {
        std::cerr << "Error opening /proc/stat" << std::endl;
        return -1.0; // Indicate error
    }

    std::string line;
    std::getline(file, line);
    std::istringstream ss(line);
    std::string cpu;
    ss >> cpu; // Skip the first token ("cpu")
    ss >> totalUser >> totalUserLow >> totalSys >> totalIdle;

    // Overflow detection
    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
        totalSys < lastTotalSys || totalIdle < lastTotalIdle) {
        percent = -1.0; // Indicate overflow
    } else {
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) +
                (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    // Update last values
    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    return percent;
}
void CpuUsage::init() {
    std::ifstream file("/proc/stat");
    if (!file.is_open()) {
        std::cerr << "Error opening /proc/stat" << std::endl;
        return; // Initialization failed
    }

    std::string line;
    std::getline(file, line);
    std::istringstream ss(line);
    std::string cpu;
    ss >> cpu; // Skip the first token ("cpu")
    ss >> lastTotalUser >> lastTotalUserLow >> lastTotalSys >> lastTotalIdle;

    file.close();
}