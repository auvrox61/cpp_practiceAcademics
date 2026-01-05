#include<bits/stdc++.h>
using namespace std;

class person{
    private:
        string* names;
        int size;
    public:
        person(int n){
            size=n;
            names=new string[size];
        }
        void setNames();
        void getNames() const;
};

void person::setNames(){
    for(int i=0;i<size;i++){
        getline(cin,names[i]);
    }
}

void person::getNames() const{
    for(int i=0;i<size;i++){
        cout<<names[i]<<" ";
    }
}

int main(){
    person p(3);
    p.setNames();
    p.getNames();
    return 0;
}