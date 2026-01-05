#include<bits/stdc++.h>
using namespace std;

class person{
    private:
        char name[101];
    public:
        person(){
            strcpy(name,"Unnamed");
        }
        person(const person& p){
            strcpy(name,p.name);
        }
        void setName();
        const char* getName() const;
};

void person::setName(){
    cin.getline(name,101);
}

const char* person::getName() const{
    return name;
}

int main(){
    person p;
    person p2=p;
    p2.setName();
    cout<<p2.getName()<<endl;
    return 0;
}