#ifndef __PAI_HWMON_CPUUSAGE
#define __PAI_HWMON_CPUUSAGE
#include <vector>
#include <string>
#include <map>
#include <fstream>

namespace pai_cpuusage { 

double cpu_usage;
double last_all = 0;
double last_idle = 0;

void update(){
    std::string temp;
    std::string delim = " ";
    std::vector<double> data;
    int start = 0;
    size_t end = 0;
    double all = 0;
    std::ifstream file;
    file.open("/proc/stat");
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        end = line.find(delim);
        temp = line.substr(start, end - start);
        while (end != std::string::npos){
            start = end + delim.length();
            end = line.find(delim, start);
            temp = line.substr(start, end - start);
            if(temp.size() > 0){
                 data.push_back(std::stod(temp));
                 all += data[data.size()-1];
            }
        }
        file.close();
    }
    cpu_usage = 100-(((data[3]-last_idle)/(all-last_all))*100);
    last_all = all;
    last_idle = data[3];
};
}

#endif
