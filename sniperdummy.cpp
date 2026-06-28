#include <iostream>
#include <vector>
#include<string>

class target{
public:
std::string name;
int healt;
target(std::string n,int h):name(n),healt(h){}
bool isDead(){
    if(healt<=0){
        return true;
    }else{
        return false;
    }
}
};
class sniper{
private:
target* currectTarge;
public:
sniper():currectTarge(nullptr){}
void aimAt(target* t){
    currectTarge=t;
}
void pulltrigger(){
    if(currectTarge==nullptr){
std::cout<<"no target locked "<<std::endl;
    }else if(currectTarge->isDead()){
std::cout<<"alleardy dead"<<std::endl;
    }else{
       currectTarge->healt-=50;
       std::cout<<"boom headshot on:"<<currectTarge->name<<std::endl;
       if(currectTarge->isDead()){
        std::cout<<"targer:"<<currectTarge->name<<"is dead"<<std::endl;
       }
    }
}
};
int main(){
    target* dumdum=new target("dumdum",100);
    sniper mysniper;
int choise;
while(choise!=0){
    std::cout<<"chose ur action 1 aim,2shoot,3status,0 quit"<< std::endl;
    std::cin>>choise;
if(choise==1){
    mysniper.aimAt(dumdum);
}else if(choise==2){
    mysniper.pulltrigger();
}else if(choise==3){
    dumdum->healt;
}else{
    std::cout<< "ur input is unknound"<<std::endl;
}
}
delete dumdum;
}