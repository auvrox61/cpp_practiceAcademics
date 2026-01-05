#include<bits/stdc++.h>
using namespace std;

class person{
    private:
        char name[3][101];
    public:
        void setNames();
        void getNames() const;
};

void person::setNames(){
    for(int i=0;i<3;i++){
        cin.getline(name[i],101);
    }
}

void person::getNames() const{
    for(int i=0;i<3;i++){
        cout<<name[i]<<" ";
    }
}

int main(){
    person p;
    p.setNames();
    p.getNames();
    return 0;
}