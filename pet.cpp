#include <iostream>
#include<vector>
#include <string>
    class Pet{
public:
std::string type;
Pet(std::string t):type(t){}


    };
    int main(){
        std::vector<Pet*>shelter;
        shelter.push_back(new Pet("DOG"));
        shelter.push_back(new Pet("monkey"));
        if(!shelter.empty()){
            for(Pet* p:shelter){
                std::cout<<"the shelter has a "<<p->type<<std::endl;
            }
        }else{
            std::cout<<"there is no shelter :( "<<std::endl;
        }
        for(Pet* p:shelter){
            delete p;
        }
        shelter.clear();
        
    }