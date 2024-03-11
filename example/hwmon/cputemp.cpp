#include <memory>
#include <vector>
#include "cputemp.hpp"

int main(){
    std::vector<double> temps;
    std::shared_ptr<cputemp_cpp::Reader> temp (new cputemp_cpp::Reader());
    temp->discovery();
    temp->refresh();
    temps = temp->tempAll();
    for (int i{0}; i < temps.size(); i++)
        std::cout << temps[i] << std::endl;
}
