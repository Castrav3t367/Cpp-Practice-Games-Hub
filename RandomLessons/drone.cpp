#include <iostream>
#include <string>
#include <memory>

class drone{
public:
std::string name;
drone(std::string n):name(n){
    std::cout<<"drone:"<<name<<"created"<<std::endl;
}

~drone(){
    std::cout<<"drone "<<name<<"deleted"<<std::endl;
}
};
void exploreCave(){
    std::unique_ptr<drone> mydrone=std::make_unique<drone>("scout");
}
int main(){
    std::cout<<"entering the cave!!"<<std::endl;
    exploreCave();
    std::cout<<"left cave"<<std::endl;
}
