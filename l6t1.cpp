#include<bits/stdc++.h>
using namespace std;

class digitalWallet{
    private:
        int ownerID;
        double curr_balance;
        bool isOverdraft() const{
            if(curr_balance<0){
                return true;
            }
            return false;
        }
    public:
        int getOwnerID() const;
        double getCurrBalance() const;
        void setOwnerID(int a);
        void setCurrBalance(double b);
        digitalWallet(int c,double d):ownerID(c),curr_balance(d){}
        ~digitalWallet(){
            cout<<"Closing the program  and the final balance is : "<<curr_balance<<endl;
        }
        digitalWallet operator+(double amount);
        friend digitalWallet operator+(double amount,const digitalWallet& dw);
        digitalWallet operator-(double amount);
        friend digitalWallet operator-(double amount,const digitalWallet& dw);
        digitalWallet operator*(double amount);
        friend digitalWallet operator*(double amount,const digitalWallet& dw);
        operator long() const;
        void displayStatus() const;
};

int digitalWallet::getOwnerID() const{
    return ownerID;
}

double digitalWallet::getCurrBalance() const{
    return curr_balance;
}

void digitalWallet::setOwnerID(int a){
    ownerID=a;
}

void digitalWallet::setCurrBalance(double b){
    curr_balance=b;
}

digitalWallet digitalWallet::operator+(double amount){
    return digitalWallet(getOwnerID(),curr_balance+amount);
}

digitalWallet operator+(double amount,const digitalWallet& dw){
    return digitalWallet(dw.getOwnerID(),amount+dw.curr_balance);
}

digitalWallet digitalWallet::operator-(double amount){
    return digitalWallet(getOwnerID(),curr_balance-amount);
}

digitalWallet operator-(double amount,const digitalWallet& dw){
    return digitalWallet(dw.getOwnerID(),amount-dw.curr_balance);
}

digitalWallet digitalWallet::operator*(double amount){
    return digitalWallet(getOwnerID(),curr_balance*amount);
}

digitalWallet operator*(double amount,const digitalWallet& dw){
    return digitalWallet(dw.getOwnerID(),amount*dw.curr_balance);
}

digitalWallet::operator long() const{
    return static_cast<long>(curr_balance*100);
}

void digitalWallet::displayStatus() const{
    cout<<"Owner ID : "<<ownerID<<endl;
    cout<<"Current Balance : "<<curr_balance<<endl;
}

int main(){
    digitalWallet w1(1,20000.0);
    digitalWallet w2(2,25000.0);
    w1.displayStatus();
    w2.displayStatus();
    w2=w1+50.0;
    w2.displayStatus();
    w2=50.0+w1;
    w2.displayStatus();
    w2=w1-12.50;
    w2.displayStatus();
    w2=w1*1.05;
    w2.displayStatus();
    long totalCents=w1;
    cout<<totalCents<<endl;
    return 0;
}