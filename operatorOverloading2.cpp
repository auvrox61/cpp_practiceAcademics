//non-member function
//double+obj

#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet(double a):balance(a){}
        double getBalance() const;
        friend wallet operator+(double amount,const wallet &other);
        void displayDetails() const;
};

double wallet::getBalance() const{
    return balance;
}

wallet operator+(double amount,const wallet& other){
    return wallet(amount+other.getBalance());
}

void wallet::displayDetails() const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(100.0);
    wallet w2=50.0+w1;
    w1.displayDetails();
    w2.displayDetails();
    return 0;
}