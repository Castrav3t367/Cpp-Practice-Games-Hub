#include <iostream>
#include<string>
#include<vector>
#include <fstream>
class asteroid{
public:
int metalamount;
std::string name;
asteroid(std::string n,int m):name(n),metalamount(m){}
};
class ship{
public:
int cargo=0;
void mine(asteroid* target){
    cargo += target->metalamount;
}
};
class sector{
public:
std::string name;
sector* nextsector;
std::vector<asteroid*> spacestone;
sector(std::string n):name(n){
    nextsector=nullptr;
}
~sector(){
    for(asteroid* a:spacestone){
        delete a;
    }
}
};
int main(){
    std::string filename="savegame.txt";    
    ship myship;
    sector* earth=new sector("earth");
    sector* mars=new sector("Mars");
    sector* jupiter=new sector("Jupiter");
    earth->spacestone.push_back(new asteroid("RUDIGAR",25));
    earth->spacestone.push_back(new asteroid("FALCON",56));
    mars->spacestone.push_back(new asteroid("GLOBUS",24));
    jupiter->spacestone.push_back(new asteroid("NAVI",150));
    jupiter->spacestone.push_back(new asteroid("LIGMA",200));
    sector* currentsector=earth;//from where game begin
    earth->nextsector=mars;
    mars->nextsector=jupiter;

    int loadedcargo=0;
    std::ifstream inFile(filename);
if(inFile.is_open()){
    inFile >> loadedcargo;
    inFile.close();
    std::cout<<"Welcome back capitan u have  :"<<loadedcargo<<std::endl;
    myship.cargo +=loadedcargo;
}else{
    std::cout<<"error loading  the game"<<std::endl;
}

    while(currentsector!=nullptr){
    std::cout<<"welcome at board sir we are curently on "<< currentsector->name<<"would like to : mine? see the status or jump to next orbit or just to save and quit?"<<std::endl;
    std::string option;
    std::cin>> option;
    if(option=="status"){
        std::cout<<myship.cargo<<std::endl;
    }else if(option=="mine"){
        if(currentsector->spacestone.empty()==false){
            asteroid* target=currentsector->spacestone[0];
            myship.mine(target);
            delete target;
            currentsector->spacestone.erase(currentsector->spacestone.begin());
            std::cout<<"asteroid mined"<<std::endl;
        }else{
         std::cout<<"no more asteroids in this orbit"<<std::endl;
        }
    }else if(option=="jump"){
    for(asteroid* a : currentsector->spacestone) {
        delete a;
    }
    currentsector->spacestone.clear(); 
    currentsector = currentsector->nextsector; 
    std::cout << "Jumping to next sector..." << std::endl;
}else if(option=="save"){
    std::ofstream outFile(filename);
    if(outFile.is_open()){
        outFile<<myship.cargo<<std::endl;
        outFile.close();
        std::cout<<"Game saved succesfuly"<<std::endl;
    }else{
        std::cout<<"error saveing the data"<<std::endl;
    }
}else if(option=="quit"){
    break;
}
    }

 



    delete earth;
    delete mars;
    delete jupiter;
}

