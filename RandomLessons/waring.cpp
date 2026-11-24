#include <iostream>
#include <vector>
#include <string>

//first un string ig where we put the states 
//then the function 
//the ifs to determinate the state
//and to print the state
enum class state{
    CRUISING,
    BRAKING,
    STOPPED
};
class AIcar{
    public:
    state s;
void scanner(float distance){
    if (distance >= 50){
       s=state::CRUISING;
        std::cout<< "sds"<<std::endl;
    }else if (distance>10&&distance<50){
        s=state::BRAKING;
        std::cout<< "sdsd" <<std::endl;

    }else {
       s=state::STOPPED;
        std::cout<< "sdasd" <<std::endl;
    }
}
};
int main (){
    AIcar mycar;
    mycar.scanner(40);
    mycar.scanner(424);
    mycar.scanner(2);
}