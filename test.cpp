#include <iostream>
#include <string>

struct Position{
    int x;
    int y;
};
class Player{
private:
std::string name;
int health;
Position pos;
public:
Player(std::string n, int h, Position p): name(n), health(h), pos(p) {
    health=100;
    name="Mancioc";
    pos.x=2;
    pos.y=3;
}
void PrintStatus(){
    std::cout<<name<<"has health: "<<health<<" and position: ("<<pos.x<<", "<<pos.y<<")"<<std::endl;
}
};
