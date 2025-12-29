#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        int balance;
    public:
        wallet(int a):balance(a){}
        wallet& operator++();
        wallet operator++(int);
        void showDetails() const;
};

wallet& wallet::operator++(){
    balance++;
    return *this;
}

wallet wallet::operator++(int){
    wallet old=*this;
    balance++;
    return old;
}

void wallet::showDetails()const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(10);
    w1.showDetails();
    wallet w2=++w1;
    w1.showDetails();
    w2.showDetails();
    wallet w3=w2++;
    w2.showDetails();
    w3.showDetails();
    return 0;
}