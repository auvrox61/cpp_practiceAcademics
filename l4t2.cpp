#include<bits/stdc++.h>
using namespace std;

class taxEstimator{
    private:
        double tot_ann_inc;
        double tot_ded_exp;
        double determineBracketRate() const{
            double netIncome=tot_ann_inc-tot_ded_exp;
            if(netIncome<10000){
                return 0.0;
            } else if(netIncome>=10000 && netIncome<=50000){
                return 0.1;
            } else{
                return 0.2;
            }
        }
        public:
            taxEstimator():tot_ann_inc(0.0),tot_ded_exp(0.0){}
            ~taxEstimator(){
                cout<<"Tax session closed."<<endl;
            }
            void addIncomeSource(double a);
            void addExpense(double b);
            void printTaxSlip() const;
};

void taxEstimator::addIncomeSource(double a){
    if(tot_ann_inc+a<0.0){
        cout<<"Negative income is bad for the economy and my code."<<endl;
        return;
    }
    tot_ann_inc+=a;
}

void taxEstimator::addExpense(double b){
    tot_ded_exp+=b;
}

void taxEstimator::printTaxSlip() const{
    double NI=tot_ann_inc-tot_ded_exp;
    double rate=determineBracketRate();
    double taxAmount=NI*rate;
    cout<<"Final tax amount due : "<<taxAmount<<endl;
}

int main(){
    taxEstimator te;
    te.printTaxSlip();
    te.addIncomeSource(50000.0);
    te.addExpense(23500.0);
    te.printTaxSlip();
    return 0;
}