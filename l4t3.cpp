#include<bits/stdc++.h>
using namespace std;

class zombie{
    private:
        int health;
        static int count;
    public:
        zombie(int a):health(a){
            count++;
            cout<<"A new zombie rises! Total count: "<<count<<endl;
        }
        ~zombie(){
            count--;
            cout<<"Zombie eliminated. Total remaining: "<<count<<endl;
        }
        void takeDamage(int b);
        void getHordeCount() const;
};

void zombie::takeDamage(int b){
    health-=b;
    if(health<=0){
        cout<<"Zombie is down"<<endl;
        count--;
    }
}

void zombie::getHordeCount() const{
    cout<<"Total Active Zombies : "<<count<<endl;
}

int zombie::count=0;

int main(){
    zombie zm(100);
    zm.getHordeCount();
    zm.takeDamage(70);
    zm.getHordeCount();
    zombie zm2(30);
    zm.getHordeCount();
    zombie zm3(30);
    zombie zm4(40);
    zombie zm5(50);
    zombie zm6(60);
    zombie zm7(70);
    zm.getHordeCount();
    zm3.takeDamage(40);
    zm.getHordeCount();
    return 0;
}