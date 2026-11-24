#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <vector>

class Entity {
protected:
    int hp;
public:
    std::string name;
    int damagePower; // Moved here so everyone has an attack value

    Entity(std::string n, int h, int d) : name(n), hp(h), damagePower(d) {}

    // A Getter for HP
    int getHP() { return hp; }
    void sayhi(){
        std::cout<<"WOARRRRRR" <<"\n";
    }

    // This is the "Bridge": It takes ANOTHER Entity as a reference and hurts it
   void attack(Entity& target) {
    // Generate a random number between 1 and 100
    int roll = (std::rand() % 100) + 1; 

    if (roll > 80) { // 20% chance
        std::cout << "CRITICAL HIT! ";
        target.takeDamage(damagePower * 2);
    } else {
        std::cout << name << " attacks " << target.name << "!" << std::endl;
        target.takeDamage(damagePower);
    }
}

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0; // Don't show negative HP
        std::cout << name << " health is now: " << hp << std::endl;
    }
};

class Player : public Entity {
public:
    Player(std::string n, int h, int d) : Entity(n, h, d) {}
};

class Enemy : public Entity {
public:
    Enemy(std::string n, int h, int d) : Entity(n, h, d) {}
};
class world {
private:
Player* activePlayer;
std::vector<Enemy*>enemies;
public:
void setplayer(Player* p){
    activePlayer=p;
}
void addEnemy(Enemy* e){}
void statusreport(){
    if(activePlayer!=nullptr){
std::cout << activePlayer->getHP() <<std::endl;
   activePlayer->sayhi();
    }
    for(Enemy* e:enemies){
        std::cout<<e->name<<e->getHP() <<std::endl;
         e->sayhi();
    }
    for(Enemy* e:enemies){
        delete e;
    }
}



};

int main() {
    world Mygame;
    Mygame.setplayer(new Player("leo",200,10));
    Mygame.addEnemy(new Enemy("goblin",100,2));
    Mygame.statusreport();
    std::vector<Enemy*> wave;

    wave.push_back(new Enemy("LORD",500,50));
    wave.push_back(new Enemy("ZEW",1000,100));
    for(Enemy* e:wave){
        e->sayhi();
    }
    for(Enemy* e:wave){
        delete e;
    }
    wave.clear();

    Player matei("Matei", 100, 20);
    Enemy orc("Orc Brute", 80, 15);

    std::cout << "--- BATTLE START ---" << std::endl;

    while (matei.getHP() > 0 && orc.getHP() > 0) {
        // Player attacks Enemy
        matei.attack(orc);

        // Check if Enemy died before it can counter-attack
        if (orc.getHP() <= 0) break;

        // Enemy attacks Player
        orc.attack(matei);

        std::cout << "--------------------" << std::endl;
    }

    if (matei.getHP() > 0) {
        std::cout << "Matei is VICTORIOUS!" << std::endl;
    } else {
        std::cout << "The Orc has defeated the hero..." << std::endl;
    }

    return 0;
}