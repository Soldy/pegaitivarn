#ifndef __PAI_HWMON_BATTERY
#define __PAI_HWMON_BATTERY
#include <set>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace pai_battery { 
namespace fs = std::filesystem;

class Reader{
  private:
    std::map<int, double> charges;
    std::vector<int> batteries;
    std::map<int, double> fulls;
    std::string batDir (int &serial){
        return (
            "/sys/class/power_supply/BAT"+
            std::to_string(serial)
        );
    };
    std::string batFull(int &serial){
        return (
            this->batDir(serial)+
            "/charge_full"
        );
    };
    std::string batNow(int &serial){
        return (
            this->batDir(serial)+
            "/charge_now"
        );
    };
    bool batDirCheck(int &serial){
        if(
             fs::exists(this->batNow(serial))&&
             fs::exists(this->batFull(serial))
        )
            return true;
        return false;
    };
    void add(int serial){
       this->batteries.push_back(serial); 
       this->readFull(serial);
    };
    void readFull(int &serial){
        std::string readed;
        std::ifstream full_file;
        full_file.open(this->batFull(serial));
        std::getline(full_file, readed);
        this->fulls[serial] = std::stod(readed);
        full_file.close();
    };
  public:
    void discovery(){
        this->discovery(256);
    };
    void discovery(int end){
        this->batteries.clear();
        for (int i{0}; i < end; i++)
            if(fs::exists(this->batDir(i)))
                if(this->batDirCheck(i))
                    this->add(i);
    };
    void refresh(){
        for (size_t i{0}; i < this->batteries.size(); i++)
            this->refresh(this->batteries[i]);
    };
    void refresh(int &serial){
        std::string readed;
        std::ifstream now_file;
        now_file.open(this->batNow(serial));
        std::getline(now_file, readed);
        this->charges[serial] = (
           (std::stod(readed) / this->fulls[serial])
           * 100
        );
        now_file.close();
    };
    std::vector<double> getAll(){
        std::vector<double> out;
        for (size_t i{0}; i < this->batteries.size(); i++)
            out.push_back(this->charges[this->batteries[i]]);
        return out;
    };
    double charge(int serial){
       return this->charges[serial];
    };
};
}

#endif
