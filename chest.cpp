#include <iostream>
#include <vector>
#include<string>



class Item{
public:
std::string  name;
Item(std::string n):name(n){}
};
int main(){
    std::vector<Item*>chest;
    chest.push_back(new Item("soward"));
    chest.push_back(new Item("bow"));
    chest.push_back(new Item("arrow"));

if(!chest.empty()){
    for(Item* it:chest){
        std::cout<<it->name<<std::endl;
    }
}else{
    std::cout<<"the chest is empty no itms "<<std::endl;
}
for(Item* it:chest){
    delete it;
}
chest.clear();

}