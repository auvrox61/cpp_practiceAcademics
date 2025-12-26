#include<bits/stdc++.h>
using namespace std;

class credCard{
    private:
        double limit;
        double curr_bal_owned;
    public:
        credCard(double a):limit(a){
            curr_bal_owned=0.0;
        }
        ~credCard(){
            cout<<"Card Destroyed"<<endl;
        }
        void makePurchase(double b);
        bool compareAvailability(const credCard& other) const;
        void displayInfo() const;
};

void credCard::makePurchase(double b){
    if(curr_bal_owned+b>limit){
        cout<<"Declined"<<endl;
        return;
    }
    curr_bal_owned+=b;
}

bool credCard::compareAvailability(const credCard& other) const{
    double available_limit=limit-curr_bal_owned;
    double other_available_limit=other.limit-other.curr_bal_owned;
    if(available_limit>other_available_limit){
        return true;
    }
    return false;
}

void credCard::displayInfo() const{
    double al=limit-curr_bal_owned;
    cout<<"Limit : "<<limit<<endl;
    cout<<"Current Balance : "<<curr_bal_owned<<endl;
    cout<<"Available Limit : "<<al<<endl;
}

int main(){
    credCard cc(50000);
    cc.displayInfo();
    cc.makePurchase(38000);
    cc.displayInfo();
    credCard cc1(60000);
    cc1.displayInfo();
    cc1.makePurchase(53100);
    if(cc.compareAvailability(cc1)){
        cout<<"The first card has got more availability"<<endl;
    } else{
        cout<<"The second card has got more availability"<<endl;
    }
    return 0;
}