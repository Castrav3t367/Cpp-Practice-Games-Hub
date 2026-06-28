#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
#include<map>
class asteroid{
public:
std::string metalType;
int amount;
asteroid(std::string n,int a):metalType(n),amount(a){}
~asteroid(){
   std::cout<<"asteroid destroyed"<<std::endl; 
}
};
class sector{
    public:
    sector* nextsector;
    std::string name;
    std::vector<std::unique_ptr<asteroid>> spacestones;

    sector(std::string n):name(n){
std::cout<<"sector"<<name<<"created"<<std::endl;
}
~sector(){
    std::cout<<"sector"<<name<<"destroyed"<<std::endl;
}
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
    ship myship("SHIP");
    std::ifstream infile("savegame.txt");
    std::string saveMetal;
    int saveAmount;
    if (infile.is_open()) {
    while (infile >> saveMetal >> saveAmount) {
        myship.cargohold[saveMetal] = saveAmount;
    }
    infile.close();
    std::cout << "Save file loaded!" << std::endl;
}
    sector* earth=new sector("earth");
    sector* mars=new sector("mars");
    sector* jupiter= new sector("jupiter");
    sector* currentsector=earth;
    earth->nextsector=mars;
    mars->nextsector=jupiter;

    earth->spacestones.push_back(std::make_unique<asteroid>("IRON ",25));
    mars->spacestones.push_back(std::make_unique<asteroid>("GOLD ",53));
    jupiter->spacestones.push_back(std::make_unique<asteroid>("DIAMONT",5));
    while(currentsector !=nullptr){
        std::string option;
        std::cout<<"What would you like to do? STATUS,MINE,JUMP,QUIT,SAVE"<<std::endl;
        std::cin>>option;
        if(option=="STATUS"){
            myship.printstatus();
        }else if(option=="MINE"){
            if(currentsector->spacestones.empty()==false){
               asteroid* target=currentsector->spacestones[0].get();
               myship.mine(target);
               currentsector->spacestones.erase(currentsector->spacestones.begin());
          }else{
            std::cout<<"this zone is empty"<<std::endl;
          }

        }else if(option=="JUMP"){
            currentsector->spacestones.clear(); 
            currentsector = currentsector->nextsector; 
    if(currentsector != nullptr) {
        std::cout << "Jumped to " << currentsector->name << std::endl;
    }
        }else if(option=="QUIT"){
            break;
        }else if(option=="SAVE"){
            std::ofstream outfile("savegame.txt");
            for(auto itm:myship.cargohold){
            outfile<<itm.first<<" "<<itm.second<<std::endl;
            }
        }
    }
    delete earth;
    delete mars;
    delete jupiter;
}