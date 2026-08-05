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
void move(char direction){
    switch(direction){
        case 'w':
            pos.y += 1;
            break;
        case 's':
            pos.y -= 1;
            break;
        case 'a':
            pos.x -= 1;
            break;
        case 'd':
            pos.x += 1;
            break;
        default:
            std::cout<<"Invalid direction!"<<std::endl;
    }
}
Player(std::string n, int startX, int startY) {
    name = n;
    health = 100;
    pos.x = startX;
    pos.y = startY;
}
void PrintStatus(){
    std::cout<<name<<"has health: "<<health<<" and position: ("<<pos.x<<", "<<pos.y<<")"<<std::endl;
}
};
int main (){
    Player player1("Mancioc", 2, 3);
    player1.PrintStatus();
    return 0;
    char input='w';
   while(input != 'q') {
        std::cout << "Enter direction (w/a/s/d) or 'q' to quit: ";
        std::cin >> input;
        
        if (input != 'q') {
            player1.move(input);
            player1.PrintStatus();
        }
    }

    std::cout << "Game Over!\n";
    return 0; // Move this to the very end!
}

