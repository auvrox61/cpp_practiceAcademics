#include<bits/stdc++.h>
using namespace std;

class smartE{
    private:
        int curr_floor_num;
        double curr_tot_weight;
        int max_floor_num;
    public:
        smartE(int a):max_floor_num(a){
            curr_floor_num=0;
            curr_tot_weight=0.0;
        }
        ~smartE(){
            cout<<"Elevator system entering maintenance mode."<<endl;
        }
        void boardPassenger(double b);
        void goToFloor(int c);
        void displayPanel() const;
};

void smartE::boardPassenger(double b){
    if(curr_tot_weight+b>4302.0){
        cout<<"Overload! Someone must exit."<<endl;
        return;
    }
    curr_tot_weight+=b;
}

void smartE::goToFloor(int c){
    if(c>=0 && c<=max_floor_num && c!=curr_floor_num){
        curr_floor_num=c;
    } else if(c<0 || c>max_floor_num){
        cout<<"Error 404: Floor not found. Try reality instead."<<endl;
        return;
    } else if(c==curr_floor_num){
        cout<<"Staying put engaged. Enjoy the view!"<<endl;
        return;
    }
}

void smartE::displayPanel() const{
    cout<<"Current Floor : "<<curr_floor_num<<endl;
    cout<<"Current Load Status : "<<curr_tot_weight<<endl;
}

int main(){
    smartE se(100);
    se.displayPanel();
    se.boardPassenger(740.0);
    se.goToFloor(45);
    se.displayPanel();
    se.boardPassenger(3500.6);
    se.goToFloor(64);
    se.displayPanel();
    return 0;
}