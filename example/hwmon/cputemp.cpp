#include <memory>
#include <vector>
#include "../../hwmon/cputemp.hpp"

int main(){
    std::vector<double> temps;
    std::shared_ptr<pai_cputemp::Reader> temp (new pai_cputemp::Reader());
    temp->discovery();
    temp->refresh();
    temps = temp->tempAll();
    for (int i{0}; i < temps.size(); i++)
        std::cout << temps[i] << std::endl;
}
