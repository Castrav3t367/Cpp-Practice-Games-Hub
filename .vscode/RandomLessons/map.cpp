#include <iostream>
#include<string>
#include<vector>
#include <fstream>
#include <map>
#include <memory>
class asteroid{
public:
std::string metalType;
int amount;
asteroid(std::string n,int a):metalType(n),amount(a){}
};
class ship{
public:
std::string name;
ship(std::string n):name(n){}
std::map<std::string,int> cargohold;
void mine(asteroid* target){
    cargohold[target->metalType] += target->amount;
}
void printstatus(){
    for(auto itm:cargohold){
        std::cout<<itm.first<<":"<<itm.second<<std::endl;
    }
}
};

int main(){
  asteroid IRON("iron",42);
  asteroid GOLD("gold",20);
  ship myship("ship");
  myship.mine(&IRON);
  myship.mine(&GOLD);
  myship.printstatus();

}