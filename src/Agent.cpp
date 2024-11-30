#include "Agent.hpp"

void Agent::getCpuUsage() {
    std::cout << "Usage:" << cpuUsage.getCurrentValue();
}