#include <iostream>
#include <string>
#include <vector>
class entity{
    public:
    int health;
    int attackpower;
    entity(int h,int a):health(h),attackpower(a){}
    void attack(entity* target) {   
         target->health -= attackpower; 
        }
};
class player:public entity{
public:
player(int h,int a):entity(h,a){}
};
class enemy:public entity{
public:
enemy(int h,int a):entity(h,a){}
};
class room {
public:
std::vector<enemy*>monsters;
std::string name;
std::string description;
room* nextroom;
room(std::string n,std::string d):name(n),description(d){
    nextroom=nullptr;
}
~room(){
for(enemy* e:monsters){
    delete e;
}
}
};
int main(){
    std::cout<<"-----------------------"<<std::endl;
    player SIMBA(150,15);
    room* entrance = new room("Dungeon Entrance", "It is dark and cold. A door leads north.");
    room* hallway = new room("Cobweb Hallway", "Bones litter the floor. The exit is ahead.");
    room* bossRoom = new room("The Throne Room", "A massive chamber filled with gold!");

    entrance->nextroom=hallway;
    hallway->nextroom=bossRoom;
    room* currentroom=entrance;

    hallway->monsters.push_back(new enemy(30,20));
    bossRoom->monsters.push_back(new enemy(100,20));

    while(currentroom !=nullptr){
        std::cout<<"you are in:"<<currentroom->name<<currentroom->description<<std::endl;
    if(currentroom->monsters.empty()==false){
std::cout<<"Warning! An enemy is blocking the way!" <<std::endl ;
for(enemy* e:currentroom->monsters){
    std::cout<<"he have:"<<e->health<<std::endl;
}
    }else{
        std::cout<<"all clean"<<std::endl;
    }
     std::cout<<"type 'move' to move or attack to attack logic"<<std::endl;
        std::string s;
        std::cin>> s ;
        if(s=="move"){
            if(currentroom->monsters.empty()==false){
                std::cout<<"YOU mush fight the enemy he block the door"<<std::endl;
            }else{
                currentroom=currentroom->nextroom;
            }
        }else if(s=="attack"&&currentroom->monsters.empty()){
            std::cout<<"You fight with the air"<<std::endl;
        }else{
            enemy* target=currentroom->monsters[0];
            SIMBA.attack(target);
            std::cout<<"you hit the monster"<<target->health<<std::endl;
            if(target->health<=0){
                delete target;
                currentroom->monsters.clear();
            }
        }
    }
    std::cout<<"u escaped the dungeon"<<std::endl;
    delete entrance;
    delete hallway;
    delete bossRoom;

}