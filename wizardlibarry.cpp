#include<iostream>
#include<vector>
#include<string>

class spell{
private:
int manaCost;
std::string efect;
public:
std::string spellName;
spell(std::string n,int m,std::string e):spellName(n),manaCost(m),efect(e){}
void cast(int c,std::string e) {
    c=manaCost;
    e=efect;
    std::cout<<"CASTING"<<spellName<<"IT"<<e<<"and cost"<<c<<"mana"<<std::endl;
}
int getMana(){
    return manaCost;
}
};
int main(){
    std::vector<spell*>spellbook;
    spellbook.push_back(new spell("FIREBALL",20,"burning"));
    spellbook.push_back(new spell("icebolt",25,"freez"));
    spellbook.push_back(new spell("thunder",75,"big amout of dmg"));

    for(spell* s:spellbook){
        if(s->getMana()<50){
           std::cout<<"U casted:"<<s->spellName<<std::endl;
        }else{
            std::cout<<"you are to exhousted to cast:"<<s->spellName<<std::endl;
        }
    }
    int totalmana=0;
    for(spell* s:spellbook){
        totalmana +=s->getMana();
    }
    std::cout<<"total mana is:"<<totalmana<<std::endl;
    for(spell* s:spellbook){
        delete s;
    }
    spellbook.clear();
}
