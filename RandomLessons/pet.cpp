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

    class Weapon{
        public:
        virtual void use(){
            cout<<"weapon";
        }
    };
    class sword:public Weapon{
        public:
        void use() override{
            cout<<"sword";
        }
    };
    class bow:public Weapon{
        public:
        void use() override{
            cout<<"bow";
        
    }
};
    
    int main() {
    sword s;
    bow b;

    Weapon* w1 = &s;
    Weapon* w2 = &b;

    w1->use();
    w2->use();
}