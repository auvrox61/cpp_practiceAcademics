#include<bits/stdc++.h>
using namespace std;

class stopwatch{
    private:
        int hours,minutes,seconds;
    public:
        stopwatch():hours(0),minutes(0),seconds(0){}
        void normalize();
        friend istream& operator>>(istream& in,stopwatch& sw);
        friend ostream& operator<<(ostream& out,const stopwatch& sw);
        stopwatch& operator++();
        stopwatch operator++(int);
};

void stopwatch::normalize(){
    minutes+=seconds/60;
    seconds=seconds%60;
    hours+=minutes/60;
    minutes=minutes%60;
}

istream& operator>>(istream& in,stopwatch& sw){
    cout<<"Input the time to normalize : "<<endl;
    in>>sw.hours;
    in>>sw.minutes;
    in>>sw.seconds;
    sw.normalize();
    return in;
}

ostream& operator<<(ostream& out,const stopwatch& sw){
    out<<setw(2)<<setfill('0')<<sw.hours<<":";
    out<<setw(2)<<setfill('0')<<sw.minutes<<":";
    out<<setw(2)<<setfill('0')<<sw.seconds;
}

stopwatch& stopwatch::operator++(){
    seconds++;
    return* this;
}

stopwatch stopwatch::operator++(int){
    stopwatch old=*this;
    seconds++;
    return old;
}

int main(){
    stopwatch stw;
    cin>>stw;
    cout<<stw<<endl;
    stopwatch stw2=++stw;
    cout<<stw2<<endl;
    stopwatch stw3=stw++;
    cout<<stw3<<endl;
    return 0;
}