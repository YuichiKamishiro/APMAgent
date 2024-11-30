#pragma once
#include "CpuUsage.hpp"


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Agent {
private:
    CpuUsage cpuUsage;
public:
    void init();
    void stop();
    void getCpuUsage();
};