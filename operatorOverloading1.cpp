//member function
//object+double

#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet(double a):balance(a){}
        wallet operator+(double amount) const;
        void displayDetails() const;
};

wallet wallet::operator+(double amount) const{
    return wallet(balance+amount);
}

void wallet::displayDetails() const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(100.0);
    wallet w2=w1+50;
    w1.displayDetails();
    w2.displayDetails();
    return 0;
}