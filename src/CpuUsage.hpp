#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class CpuUsage {
private:
    unsigned long long lastTotalUser = 0, lastTotalUserLow = 0, 
                       lastTotalSys = 0, lastTotalIdle = 0;
public:
    CpuUsage();

    double getCurrentValue();
    void init();
};
