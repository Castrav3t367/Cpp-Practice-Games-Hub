#include <iostream>
#include <string>

int main(){
    std::string name;
    std::cout<<"What is youre name, travelere?"<<std::endl;
    std::getline(std::cin, name);
    std::cout<<"oooo GREATINGS "<<name<<std::endl;
    std::string action;
    while(action != "run"){
        std::cout<<"choise ur attion:bribe,fight,run"<<std::endl;
        std::cin>>action;
        if(action=="bribe"){
std::cout<<"the guard takes the gold and let u in"<<std::endl;
break;
        }else if(action=="fight"){
            std::cout<<"the guardian take his swoard game over"<<std::endl;
            break;
        }else if(action=="run"){
            std::cout<<"u sprint away in the forest"<<std::endl;
            break;
        }else{
            std::cout<<"the guard stare at u confused"<<std::endl;
        }
    }

}