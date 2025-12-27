#include<bits/stdc++.h>
using namespace std;

class gymProfile{
    private:
        string memberName;
        string memberShipTier;
        double bodyWeight;
        double benchPressMax;
    public:
        gymProfile():memberName("N/A"),memberShipTier("N/A"),bodyWeight(0.0),benchPressMax(0.0){}
        gymProfile(string a,string b,double c,double d):memberName(a),memberShipTier(b),bodyWeight(c),benchPressMax(d){}
        string getMemberName() const;
        string getMemberShipTier() const;
        double getBodyWeight() const;
        double getBenchPressMax() const;
        void setMemberName(string e);
        void setMemberShipTier(string f);
        void setBodyWeight(double g);
        void setBenchPressMax(double h);
        void displayStats() const;
};

string gymProfile::getMemberName() const{
    return memberName;
}

string gymProfile::getMemberShipTier() const{
    return memberShipTier;
}

double gymProfile::getBodyWeight() const{
    return bodyWeight;
}

double gymProfile::getBenchPressMax() const{
    return benchPressMax;
}

void gymProfile::setMemberName(string e){
    memberName=e;
}

void gymProfile::setMemberShipTier(string f){
    if(f.size()>3){
        memberShipTier=f;
        return;
    }
    memberShipTier="Standard";
}

void gymProfile::setBodyWeight(double g){
    if(g>=40&&g<=200){
        bodyWeight=g;
        return;
    }
    bodyWeight=70.0;
}

void gymProfile::setBenchPressMax(double h){
    benchPressMax=h;
}

void completeTrainingSession(gymProfile &profile){
    double ogBenchPressMax=profile.getBenchPressMax();
    profile.setBenchPressMax(ogBenchPressMax*1.05);
    double ogBodyWeight=profile.getBodyWeight();
    profile.setBodyWeight(ogBodyWeight-1.5);
}

void cyberImplant(gymProfile gp[],int size){
    for(int i=0;i<size;i++){
        cout<<"Enter your name : "<<endl;
        string l;
        cin.ignore();
        getline(cin,l);
        gp[i].setMemberName(l);
        cout<<"Enter membership tier : "<<endl;
        string m;
        cin>>m;
        gp[i].setMemberShipTier(m);
        cout<<"Enter your body weight : "<<endl;
        double n;
        cin>>n;
        gp[i].setBodyWeight(n);
        cout<<"Enter max bench press : "<<endl;
        double o;
        cin>>o;
        gp[i].setBenchPressMax(o);
    }
}

void gymProfile::displayStats() const{
    cout<<"Name : "<<memberName<<endl;
    cout<<"Membership tier : "<<memberShipTier<<endl;
    cout<<"Body weight : "<<bodyWeight<<" KG"<<endl;
    cout<<"Maximum bench press : "<<benchPressMax<<" KG"<<endl;
}

int main(){
    gymProfile gp[5];
    int size=5;
    cyberImplant(gp,size);
    for(int i=0;i<size;i++){
        gp[i].displayStats();
    }
    completeTrainingSession(gp[0]);
    completeTrainingSession(gp[1]);
    completeTrainingSession(gp[2]);
    completeTrainingSession(gp[3]);
    completeTrainingSession(gp[4]);
    for(int i=0;i<size;i++){
        gp[i].displayStats();
    }
    return 0;
}