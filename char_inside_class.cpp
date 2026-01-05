#include<bits/stdc++.h>
using namespace std;

class person{
    private:
        char name[101];
    public:
        const char* getName() const;
        void setName();
};

void person::setName(){
    cout<<"Enter your name : "<<endl;
    cin.getline(name,101);
}

const char* person::getName() const{
    return name;
}

int main(){
    person p;
    p.setName();
    cout<<p.getName()<<endl;
    return 0;
}