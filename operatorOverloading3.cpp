//object+=double
//object-=double

#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet(double a):balance(a){}
        wallet& operator+=(double amount);
        wallet& operator-=(double amount);
        void showDetails() const;
};

wallet& wallet::operator+=(double amount){
    balance+=amount;
    return *this;
}

wallet& wallet::operator-=(double amount){
    balance-=amount;
    return *this;
}

void wallet::showDetails() const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(100.0);
    w1+=50.0;
    w1.showDetails();
    w1-=30.0;
    w1.showDetails();
    return 0;
}