#include <iostream>
#include <string>
class Vehicle{
protected:
int speed;
public:
std::string brand;
Vehicle(std::string b,int s):brand(b),speed(s){}
virtual void  drive(){
    std::cout<<"THE "<<brand<<"is moving at "<<speed<<"hm/h";
}
    int getSpeed(){
        return speed;
    }
};
class car:public Vehicle{
    private:
    int fuel;
    public:
    car(std::string b,int s,int f):Vehicle(b,s),fuel(f){}
  void refuel(int amount){
    fuel +=amount;
  }
void drive() override{
    std::cout<<"THE "<<brand<<"is moving at "<<speed<<"hm/h"<<"Fuel lvl:"<<fuel;
}
};
int main(){
    car golf("golf",60,200);
    golf.drive();
    golf.refuel(200);
    golf.drive();

}