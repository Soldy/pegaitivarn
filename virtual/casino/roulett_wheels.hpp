/*
 * I built a minimum of 30 roulette games in my life 
 * I always wanted to build a good one. 
 * But we always have no time to do one that can manage
 * every situation, and the perfect is enemy of profit.
 *
 * This is part of a hobby roulette game tool.
 */
#include <vector>
#include <string>
#include <random>
#include <map>


namespace casino_roulette{


class Wheel {
  private:
     std::vector<int> _history;
     std::vector<std::string> list;
     std::vector<std::vector<std::string>> types {
       {
         "0", "32", "15", "19", "4", "21", "2", "25",
         "17", "34", "6", "27", "13", "36", "11", "30",
         "8", "23", "10", "5", "24", "16", "33", "1",
         "20", "14", "31", "9", "22", "18", "29", "7",
         "28", "12", "35", "3", "26"
       },
       {
         "0", "28", "9", "26", "30", "11", "7", "20",
         "32", "17", "5", "22", "34", "15", "3", "24",
         "36", "13", "1", "00", "27", "10", "25", "29",
         "12", "8", "19", "31", "18", "6", "21", "33",
         "16", "4", "23", "35", "14", "2"
       },
       {
         "0", "000", "00", "32", "15", "19", "4", "21",
         "2", "25", "17", "34", "6", "27", "13", "36",
         "11", "30", "8", "23", "10", "5", "24", "16",
         "33", "1", "20", "14", "31", "9", "22", "18",
         "29", "7", "28", "12", "35", "3", "26"
       }
     };
     std::map<std::string, int> names {
       {"one zero", 0},
       {"two zero", 1},
       {"three zero", 2}
     };
     int size = 36;
   public:
     Wheel(std::string type){
         if (this->names.find(type) == names.end()) {
             this->list = this->types[0];
         }else
             this->list = this->types[this->names[type]];
     };
     Wheel (std::vector<std::string> custom_wheel){
         this->list = custom_wheel;
     };
     std::string spin (){
         int out;
         std::random_device dev;
         std::mt19937 rng(dev());
         std::uniform_int_distribution<
          std::mt19937::result_type
         > random(0,(this->list.size()-1));
         out = random(rng);
         this->_history.push_back(out);
         return this->list[out];
     };
     std::vector<std::string> history (){
         std::vector<std::string> out;
         for (int i{0}; i < this->_history.size(); i++)
             out.push_back(this->list[this->_history[i]]);
         return out;
     };
};
}



