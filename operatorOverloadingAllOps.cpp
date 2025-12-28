//+-*/
//+= -=
//== < >

#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet(double a):balance(a){}
        double getBalance() const;
        wallet operator+(double amount) const;
        wallet operator-(double amount) const;
        wallet operator*(double amount) const;
        wallet operator/(double amount) const;
        friend wallet operator+(double amount,const wallet &other);
        friend wallet operator-(double amount,const wallet &other);
        friend wallet operator*(double amount,const wallet &other);
        friend wallet operator/(double amount,const wallet &other);
        wallet& operator+=(double amount);
        wallet& operator-=(double amount);
        wallet& operator+=(const wallet &other);
        wallet& operator-=(const wallet &other);
        bool operator==(const wallet &other) const;
        bool operator<(const wallet &other) const;
        bool operator>(const wallet &other) const;
        void showDetails() const;
};

double wallet::getBalance() const{
    return balance;
}

wallet wallet::operator+(double amount) const{
    return wallet(balance+amount);
}

wallet wallet::operator-(double amount) const{
    return wallet(balance-amount);
}

wallet wallet::operator*(double amount) const{
    return wallet(balance*amount);
}

wallet wallet::operator/(double amount) const{
    return wallet(balance/amount);
}

wallet operator+(double amount,const wallet& other){
    return wallet(amount+other.getBalance());
}

wallet operator-(double amount,const wallet& other){
    return wallet(amount-other.getBalance());
}

wallet operator*(double amount,const wallet& other){
    return wallet(amount*other.getBalance());
}

wallet operator/(double amount,const wallet& other){
    return wallet(amount/other.getBalance());
}

wallet& wallet::operator+=(double amount){
    balance+=amount;
    return *this;
}

wallet& wallet::operator-=(double amount){
    balance-=amount;
    return *this;
}

wallet& wallet::operator+=(const wallet &other){
    balance+=other.getBalance();
    return *this;
}

wallet& wallet::operator-=(const wallet &other){
    balance-=other.getBalance();
    return *this;
}

bool wallet::operator==(const wallet &other) const{
    if(balance==other.getBalance()){
        return true;
    }
    return false;
}

bool wallet::operator<(const wallet &other) const{
    if(balance<other.getBalance()){
        return true;
    }
    return false;
}

bool wallet::operator>(const wallet &other) const{
    if(balance>other.getBalance()){
        return true;
    }
    return false;
}

void wallet::showDetails() const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(100.0);
    wallet w2(50.0);
    wallet w3(25.0);
    wallet w4=w1+12.8;
    wallet w5=w1-12.8;
    wallet w6=w1*2.8;
    wallet w7=w1/2.4;
    wallet w8=13.4+w2;
    wallet w9=13.4-w2;
    wallet w10=3.4*w2;
    wallet w11=3.4/w2;
    w8+=21.09;
    w9-=12.3;
    w10+=w3;
    w11-=w3;
    w1.showDetails();
    w2.showDetails();
    w3.showDetails();
    w4.showDetails();
    w5.showDetails();
    w6.showDetails();
    w7.showDetails();
    w8.showDetails();
    w9.showDetails();
    w10.showDetails();
    w11.showDetails();
    if(w6==w9){
        cout<<"Both the wallets have similar balance"<<endl;
    } else{
        cout<<"They dont have similar balance"<<endl;
    }

    if(w2>w7){
        cout<<"w2 has more balance than w7"<<endl;
    } else{
        cout<<"w2 does not have more balance than w7"<<endl;
    }

    if(w2<w7){
        cout<<"w2 has lesser balance than w7"<<endl;
    } else{
        cout<<"w2 does not have lesser balance than w7"<<endl;
    }
    return 0;
}