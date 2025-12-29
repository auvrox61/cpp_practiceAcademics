#include<bits/stdc++.h>
using namespace std;

class wallet{
    private:
        double balance;
    public:
        wallet():balance(0.0){}
        wallet(double a):balance(a){}
        friend istream& operator>>(istream& in,wallet& w);
        friend ostream& operator<<(ostream& out,const wallet& w);
};

istream& operator>>(istream& in,wallet& w){
    cout<<"Enter the balance : ";
    in>>w.balance;
    return in;
}

ostream& operator<<(ostream& out,const wallet& w){
    out<<"Your current balance : "<<w.balance;
    return out;
}

int main(){
    wallet w1;
    cin>>w1;
    cout<<w1;
    return 0;
}