//object+=object
//object-=object

#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet(double a):balance(a){}
        double getBalance() const;
        wallet& operator+=(const wallet &other);
        wallet& operator-=(const wallet &other);
        void showDetails() const;
};

double wallet::getBalance() const{
    return balance;
}

wallet& wallet::operator+=(const wallet &other){
    balance+=other.getBalance();
    return *this;
}

wallet& wallet::operator-=(const wallet &other){
    balance-=other.getBalance();
    return *this;
}

void wallet::showDetails() const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(100.0);
    wallet w2(70.0);
    w1+=w2;
    w2-=w1;
    w1.showDetails();
    w2.showDetails();
    return 0;
}