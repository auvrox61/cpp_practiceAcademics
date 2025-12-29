#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet(double a):balance(a){}
        operator long() const;
        void showDetails() const;
};

wallet::operator long() const{
    return static_cast<long> (balance*100);
}

void wallet::showDetails() const{
    cout<<"Balance : "<<balance<<endl;
}

int main(){
    wallet w1(12.342);
    w1.showDetails();
    long cents=w1;
    cout<<cents<<endl;
    return 0;
}