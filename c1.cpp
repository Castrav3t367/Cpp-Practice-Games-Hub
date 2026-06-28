#include <iostream>
#include <string>
#include <memory>
#include <vector>

class asteroid{
public:
std::string name;
asteroid(std::string n):name(n){
std::cout<<"asteroid:"<<name<<"spawned"<<std::endl;
}
~asteroid(){
   std::cout<<"asteroid:"<<name<<"destroyed"<<std::endl; 
}
};
class sector{
    public:
    std::string name;
    std::vector<std::unique_ptr<asteroid>> spacestones;

    sector(std::string n):name(n){
std::cout<<"sector"<<name<<"created"<<std::endl;
}
~sector(){
    std::cout<<"sector"<<name<<"destroyed"<<std::endl;
}
};
int main(){
sector earthOrbit("eart");
earthOrbit.spacestones.push_back(std::make_unique<asteroid>("MARCUS"));
earthOrbit.spacestones.push_back(std::make_unique<asteroid>("GALACTICUS"));
std::cout<<"end of game"<<std::endl;


}