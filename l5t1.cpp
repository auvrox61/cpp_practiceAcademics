#include<bits/stdc++.h>
using namespace std;

class pizza{
    private:
        string pizzaName;
        string crustType;
        int spicinessLevel;
        bool isExtraCheesy;
    public:
        pizza():pizzaName("Unnamed"),crustType("Unnamed"),spicinessLevel(0),isExtraCheesy(false){}
        pizza(string a,string b,int c,bool d):pizzaName(a),crustType(b),spicinessLevel(c),isExtraCheesy(d){}
        string getPizzaName() const;
        string getCrustType() const;
        int getSpicinessLevel() const;
        bool getIsExtraCheesy() const;
        void setPizzaName(string e);
        void setCrustType(string f);
        void setSpicinessLevel(int g);
        void setIsExtraCheesy(bool h);
        void displayDetails() const;
};

string pizza::getPizzaName() const{
    return pizzaName;
}

string pizza::getCrustType() const{
    return crustType;
}

int pizza::getSpicinessLevel() const{
    return spicinessLevel;
}

bool pizza::getIsExtraCheesy() const{
    return isExtraCheesy;
}

void pizza::setPizzaName(string e){
    pizzaName=e;
}

void pizza::setCrustType(string f){
    if(f=="Thin"||f=="Thick"||f=="Stuffed"){
        crustType=f;
    } else{
        crustType="Thin";
    }
}

void pizza::setSpicinessLevel(int g){
    if(g>=1&&g<=10){
        spicinessLevel=g;
    } else{
        spicinessLevel=5;
    }
}

void pizza::setIsExtraCheesy(bool h){
    isExtraCheesy=h;
}

void prepareOrders(pizza menu[],int size){
    for(int i=0;i<4;i++){
        cout<<"Enter your Pizza name : "<<endl;
        string e;
        cin.ignore();
        getline(cin,e);
        menu[i].setPizzaName(e);
        cout<<"Enter your preferred crust Type : "<<endl;
        string f;
        cin>>f;
        menu[i].setCrustType(f);
        cout<<"Enter your preferred spiciness level : "<<endl;
        int g;
        cin>>g;
        menu[i].setSpicinessLevel(g);
        cout<<"Do you want your pizza to be extra cheesy?"<<endl;
        bool h;
        cin>>h;
        menu[i].setIsExtraCheesy(h);
    }
    srand(time(0));
    for(int i=4;i<size;i++){
        int randInt=rand()%10+1;
        string j="Mystery Pizza";
        string k="Thick";
        bool l;
        menu[i].setPizzaName(j);
        menu[i].setCrustType(k);
        menu[i].setSpicinessLevel(randInt);
        if(i%2==0){
            l=true;
            menu[i].setIsExtraCheesy(l);
        } else{
            l=false;
            menu[i].setIsExtraCheesy(l);
        }
    }
}

void pizza::displayDetails()  const{
    cout<<"Pizza Name : "<<pizzaName<<endl;
    cout<<"Crust Type : "<<crustType<<endl;
    cout<<"Spiciness Level : "<<spicinessLevel<<endl;
    cout<<"Is your pizza extra cheesy? : "<<((isExtraCheesy)?"Yes":"No")<<endl;
}

int main(){
    pizza menu[30];
    int size=30;
    prepareOrders(menu,size);
    for(int i=0;i<size;i++){
        if(menu[i].getSpicinessLevel()>=7){
            menu[i].displayDetails();
        }
    }
    return 0;
}