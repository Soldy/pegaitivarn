
#ifndef __PAI_HWMON_CPUFREQ
#define __PAI_HWMON_CPUFREQ
#include <set>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace pai_cpufreq {
namespace fs = std::filesystem;
struct Unit {
    std::string name;
    std::string path;
    double freq;
    std::string readed;
};
class Reader{
    std::string hwmDir (int &serial){
        return (
            "/sys/devices/system/cpu/cpufreq/policy"+
            std::to_string(serial)+
            "/"
        );
    };
    std::vector<Unit> units;
    std::string hwmFreqFile(
      int &serial
    ){
        return (
            this->hwmDir(serial)+
            "/scaling_cur_freq"
        );
    };
    void add(int &serial){
        Unit next;
        next.path = this->hwmFreqFile(serial);
        next.name = next.path;
        this->units.push_back(next);
    };
    bool hwmDirCheck(int &serial){
        if(fs::exists(this->hwmFreqFile(serial)))
            return true;
        return false;
    };
    void read(int &serial){
        std::string readed;
        std::ifstream freq_file;
        freq_file.open(this->units[serial].path);
        std::getline(freq_file, readed);
        this->units[serial].freq = (std::stod(readed) / 1000.00);
        this->units[serial].readed = readed;
        freq_file.close();
    };
  public:
    void discovery(){
        this->discovery(256);
    };
    void discovery(int end){
        for (int i{0}; i < end; i++){
            if(fs::exists(this->hwmDir(i))){
                if(this->hwmDirCheck(i))
                    this->add(
                      i
                    );
            } else {
                break;
            }
        }
    };
    void refresh(){
        for (int i{0}; i < (int)this->units.size(); i++)
            this->read(i);
    };
    Unit get(int elem){
        Unit freq;
        if(
            elem < 0 ||
            (size_t)elem >= this->units.size()
        )
            return freq;
        freq = this->units[elem];
        return freq;
    };
    std::vector<double> freq(int elem){
        std::vector<double> freqs;
        if(
            elem < 0 ||
            elem >= (int)this->units.size()
        )
            return freqs;
        freqs.push_back(this->units[elem].freq);
        return freqs;
    };
    std::vector<double> freqAll(){
        std::vector<double> freqs;
        for (const Unit& unit : this->units)
            freqs.push_back(unit.freq);
        return freqs;
    };

};
}
#endif
