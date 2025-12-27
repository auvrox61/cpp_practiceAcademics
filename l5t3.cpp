#include<bits/stdc++.h>
using namespace std;

class wizard{
    private:
        string wizardName;
        string familiarType;
        double spellPower;
        double manaPool;
    public:
        wizard():wizardName("N/A"),familiarType("N/A"),spellPower(0),manaPool(0){}
        wizard(string a,string b,double c,double d):wizardName(a),familiarType(b),spellPower(c),manaPool(d){}
        string getWizardName() const;
        string getFamiliarType() const;
        double getSpellPower() const;
        double getManaPool() const;
        void setWizardName(string e);
        void setFamiliarType(string f);
        void setSpellPower(double g);
        void setManaPool(double h);
        wizard duel(const wizard &opponent);
        void displayDetails() const;
};

string wizard::getWizardName() const{
    return wizardName;
}

string wizard::getFamiliarType() const{
    return familiarType;
}

double wizard::getSpellPower() const{
    return spellPower;
}

double wizard::getManaPool() const{
    return manaPool;
}

void wizard::setWizardName(string e){
    wizardName=e;
}

void wizard::setFamiliarType(string f){
    familiarType=f;
}

void wizard::setSpellPower(double g){
    spellPower=g;
}

void wizard::setManaPool(double h){
    manaPool=h;
}

wizard wizard::duel(const wizard &opponent){
    double arcane_potential=(pow(spellPower,0.8)*(manaPool/(manaPool+spellPower)))+(log(spellPower+1)*sqrt(manaPool));
    double opp_arcane_potential=(pow(opponent.spellPower,0.8)*(opponent.manaPool/(opponent.manaPool+opponent.spellPower)))+(log(opponent.spellPower+1)*sqrt(opponent.manaPool));
    if(arcane_potential>=opp_arcane_potential){
        return *this;
    } 
    return opponent;
}

void tournament(wizard wz[],int size){
    for(int i=0;i<size;i++){
        cout<<"Enter wizard name : "<<endl;
        string j;
        cin>>j;
        wz[i].setWizardName(j);
        cout<<"Enter familiar type : "<<endl;
        string k;
        cin>>k;
        wz[i].setFamiliarType(k);
        cout<<"Enter spell power : "<<endl;
        double l;
        cin>>l;
        wz[i].setSpellPower(l);
        cout<<"Enter mana pool : "<<endl;
        double m;
        cin>>m;
        wz[i].setManaPool(m);
    }
}

void wizard::displayDetails() const{
    cout<<"Wizard : "<<wizardName<<endl;
    cout<<"Familiar : "<<familiarType<<endl;
    cout<<"Spell Power : "<<spellPower<<endl;
    cout<<"Mana : "<<manaPool<<endl;
}

int main(){
    wizard wz[5];
    int size=5;
    tournament(wz,size);
    for(int i=0;i<size;i++){
        wz[i].displayDetails();
    }
    wizard winner=wz[0];
    for(int i=1;i<size;i++){
        winner=winner.duel(wz[i]);
    }
    cout<<"Champion : "<<endl;
    winner.displayDetails();
    return 0;
}