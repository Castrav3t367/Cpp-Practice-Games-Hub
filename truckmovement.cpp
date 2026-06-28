#include <iostream>
#include <string>
#include <cmath>

struct Vector3{float x,y,z;};
struct AABB{float minx,maxx,minz,maxz;};
bool checkColision(AABB box1,AABB box2){
    if(box1.minx<=box2.maxx&& box1.maxx>=box2.minx&&box1.minz<=box2.maxz&&box1.maxz>=box2.minz){
            return true;
    }else{
            return false;
        }
}
class truck{
public:
std::string name;
float speed=0.0f;
float heading =0.0f;
Vector3 position;
Vector3 velociity;

void turn(float a){
heading +=a;
std::cout<<"well turent at :"<<heading<<std::endl;
}
void updatephysics(float dt){
    velociity.x=speed*sin(heading);
    velociity.z=speed*cos(heading);
    position.x+=velociity.x*dt;
    position.y+=velociity.y*dt;
    position.z += velociity.z*dt;
    std::cout << name << " is now at X: " << position.x << ", Y: "<< position.y<< ", Z: " << position.z << std::endl;
}
};
int main(){
    AABB truckbox={-2.0f, 2.0f, 0.0f, 10.0f};
    AABB wallBox = {-5.0f, 5.0f, 9.0f, 12.0f};
    if(checkColision(truckbox,wallBox)){
        std::cout << "CRASH! The truck hit the wall :(" << std::endl;
    } else {
        std::cout << "Highway is clear." << std::endl;
    }

    truck mytruck;
    mytruck.position={0.0f,0.0f,0.0f};  
    mytruck.velociity= {0.0f,0.0f,55.0f};
    mytruck.speed=50.0f;
    mytruck.updatephysics(1.0f);
  for(int i=0;i<10;i++){
    mytruck.updatephysics(0.1f);
  }
}