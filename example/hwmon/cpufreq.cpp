#include <memory>
#include <vector>
#include "../../hwmon/cpufreq.hpp"

int main(){
    std::vector<double> freqs;
    std::shared_ptr<pai_cpufreq::Reader> freq (new pai_cpufreq::Reader());
    freq->discovery();
    freq->refresh();
    freqs = freq->freqAll();
    for (size_t i{0}; i < freqs.size(); i++)
        std::cout << freqs[i] << std::endl;
}
