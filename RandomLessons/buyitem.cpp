#include <iostream>
#include <string>
#include <vector>
class Item{
public:
std::string name;
int price;
Item(std::string n,int p): name(n),price(p){}

};
int main(){
    std::vector<Item*>shop;
    shop.push_back(new Item("potion",10));
    shop.push_back(new Item("Swoard",50));
int playergold=20;
std::cout<<"u have:"<<playergold<<std::endl;
for(Item* i: shop){
std::cout<<"on stock we ghave:"<<i->name<<"and it cost :"<<i->price<<std::endl;
}
std::cout<<"Witch one would u like to buy?"<<std::endl;
std::string choise;
std::cin>>choise;

bool foundItem = false; 

for(Item* i : shop) {
    if(choise == i->name) {
        foundItem = true;
        if(playergold >= i->price) {
            playergold -= i->price;
            std::cout << "You bought: " << i->name << "!" << std::endl;
        } else {
            std::cout << "I'm sorry, you don't have enough money." << std::endl;
        }
        break; 
}
if(foundItem == false) {
    std::cout << "We don't have that, sorry!" << std::endl;
}
for(Item* e:shop){
    delete e;
}
shop.clear();
}
