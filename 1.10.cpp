#include <iostream>
#include <vector>
#include <string>


vector<int> nums = {73, 12, 45, 2, 91, 34, 8};

sort(nums.begin(), nums.end());
for(int i=0;i<nums.size();i++)
{
    cout << nums[i] << " ";
}

sort(nums.begin(), nums.end(), greater<int>());
for(int i=0;i<nums.size();i++)
{
    cout << nums[i] << " ";
}



vector<int> nums = {10, 25, 40, 15, 30, 50};

auto it =find(nums.begin(),nums.end(),40);
if(it==true){
    
    cout<<"Element found"<<*it;
    cout<<distance(nums.begin(),it);
}
else{
    cout<<"Element not found";
}


vector<int> nums = {5, 12, 8, 20, 33, 7};
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
}
reverse(nums.begin(),nums.end());
auto it = find(nums.begin(), nums.end(), 20);
if(it != nums.end()){
    cout<<*it<<distance(nums.begin(),it);
}else{
    cout<<"Element not found";
}



vector<int> nums = {10, 5, 20, 5, 30, 5, 40, 10};

int five=count(nums.begin(), nums.end(), 5);
cout<<five;
int ten=count(nums.begin(), nums.end(), 10);
cout<<ten;
int twenty=count(nums.begin(), nums.end(), 20);
cout<<twenty;


vector<int> nums = {73, 12, 45, 2, 91, 34, 8};
auto min = min_element(nums.begin(), nums.end());
auto max = max_element(nums.begin(), nums.end());
cout << *min << " " << *max;




vector<int> nums = {15, 42, 7, 42, 19, 7, 42, 30};

sort(nums.begin(),nums.end())
auto min=minim(nums.begin(),nums.end())
auto max=maxim(nums.begin(),nums.end())
count(nums.begin(),nums.end(),42)
auto it=find(nums.begin(),nums.end(),42)
distance(nums.begin(),*it)


vector<int> nums = {64, 12, 35, 12, 90, 7, 35, 42, 12};

sort(nums.begin(),nums.end());
auto min=min_element(nums.begin(),nums.end());
auto max=max_element(nums.begin(),nums.end());
int coun12=count(nums.begin(),nums.end(),12);
auto it=fidn(nums.begin(),nums,end(),35);
distance(nums.begin(),it);
for(int i=0;i<=nums.size(),i++){
   std::cout<<nums[i]<<std::endl;
}

vector<int> nums = {73, 12, 45, 2, 91, 34, 8, 50};
sort(nums.begin(),nums.end());
bool found=binnary_search(nums.begin(),nums.end(),45);
bool found100=binnary_search(nums.begin(),nums.end(),100);

std::cout<<"45"<<found<<std::endl;
std::cout<<"100"<<found100<<std::endl;




vector<int> nums = {30, 10, 50, 20, 50, 40, 50, 60};
sort(nums.begin(),nums.end());
bool b50=binary_search(nums.begin(),nums.end(),50);
int c50=count(nums.begin(),nums.end(),50);
lower_bound(nums.begin(), nums.end(), 50)
upper_bound(nums.begin(), nums.end(), 50)

vector<int> nums = {10, 20, 30, 40, 50};

swap(nums[4],nums[0]);
swap(nums[3],nums[1]);

vector<int> nums = {5, 10, 15, 20, 25};
for(int x:nums){
    x=*2;
    cout<<x;
}

for(int& x : nums){
    x+=2152
}

for(int x : nums){
    cout<<x
}

vector<int> nums = {10, 20, 30, 40, 50};

auto first=nums.begin();
auto last=nums.end()-1;

vector<int> nums = {10, 20, 30, 40, 50};

for(const auto& x:nums){
    int sum=0;
    sum+=x;
}

vector<int> nums = {10, 25, 30, 45, 50, 65};
int sum=0;
for(const auto& x:nums){
if(x>30){
    sum+=x
}
}
cout<<sum;




class Character {
private:
    string name;
    int health;

public:
    Character(string n, int h);

    string getName() const;
    int getHealth() const;

    virtual void attack() = 0;
    virtual ~Character() {}
};

class Warrior:public Character{
    public:
    Warrior(string n,int n):name(n),helth(n){}
    void attack( )override{
        cout<<"Arthur swings a sword!";
    }

};
class Mage:public Character{
    public:
    Mage(string n ,int n):name(n),health(n){}
    void attack()override{
        cout<<"merlin cast a fireball";
    }
};


int main (){
    vector<Character*> team;
    team.push_back=new Warrior("Arthur",100);
    team.push_back=new Warrior("Thor",120);
    team.push_back=new Mage("Merlin",80);   
    void startBattle(const vector<Character*>& team)
    for (cosnt auto& character: team){
        character->attack();
    }
    void showCharacter(const Character& character){
        character->getName();
        character->getHealth();
    }
    int count=0;
    for(const auto& character:team){
        if(character->getHealt()==100){
            cout++;
        }
    }
Character* first = team[0];
cout<<first;
Character& firstRef = *first;
firstRef.attack();

for(auto c:team){
    delete c
}

}




class Character{
private:
string name;
int health;
public:
Character(string n,int h):name(n),health(h){}
void getName(){
    Character.name;
}
void getHealth(){
    Character.health;
}
virtual void attack(){
    cout<<"ATTACK";
}

~Character(){
}
};

class Warrior:public Character{
public:
Warrior (string s,int h):Character(s,h){}
 
void attack()override{
    Warrior.getName();
}

};

class Mage:public Character{
public:
Mage (string s,int h):Character(s,h){}
 
void attack()override{
    Mage.getName();
}

};

int main (){

vector<Character*> team;

team.push_back(new Warrior("arthur",100));
team.push_back(new Mage("merlin",80));
team.push_back(new Warrior("Thor",120));


for(const auto& character :auto){
    character->attack();
}

for (auto t : team){
    delete t;
}

}



int main() {

    void() {
        cout << "Hello!";
    };

}


vector<int> nums = {10, 20, 30, 40, 50};

 for_each(nums.begin(),nums.end(),[](int x)){
    cout<<x;
 }



 vector<int> nums = {5, 10, 15, 20};



 for_each(nums.begin(),nums.end(),[](int& x)){
    x*=3;
    cout<<x;
 }




 vector<int> nums = {2, 4, 6, 8};
int multiplier = 5;

for_each(nums.begin(),nums.end,[multiplier&](int x)){

    x*= multiplier;
}


unique_ptr<int> ptr1 = make_unique<int>(100);

ptr1 = 500;
cout<<*ptr1;






class Character{
    private:
    string name;
    int health;
    Character(string n,int h):name(n),health(h){}
    string getName(){
        return name;
    }
    virtual void attack(){
        cout<<"ATTACK";
    }
    virtual ~Character(){
    }

};

class Warrior:public Character{
    public:
    Warrior(string n,int h):Character(n,h){}
    void attack()override{
        cout<<"Warrior attacks with sword!";
    }
};

 class Mage:public Character{
    public:
    Mage(string n,int h):Character(n,h){}
    void attack()override{
        cout<<"Mage casts a fireball!";
    }
};


int main (){
    vector<unique_ptr<Character>>team;
    team.push_back(make_unique<Warrior>("Arthur",100));
    team.push_back(make_unique<Mage>("Merlin",80));
    team.push_back(make_unique<Warrior>("Thor",120));

    for(const auto& character:team){
        character->attack();
    }
}




class Character{
    private:
    string name;

    int health;
    public:
    Character(string n,int h):name(n),health(h){}
    string getName(){
        return name;
    }
    virtual void attack(){
        cout<<"ATTACK";

    }
    int getHealth(){
        return health;
    }
    virtual ~Character(){
    }

};