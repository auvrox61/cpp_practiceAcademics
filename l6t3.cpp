#include<bits/stdc++.h>
using namespace std;

class stopWatch{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;
        void setHours(int a);
        void setMinutes(int b);
        void setSeconds(int c);
        stopWatch():hours(0),minutes(0),seconds(0){}
        ~stopWatch(){
            cout<<"Stopping the stopwatch"<<endl;
        }
        stopWatch& operator++();
        stopWatch operator++(int);
        friend ostream& operator<<(ostream& out,const stopWatch& sw);
        friend istream& operator>>(istream& in,stopWatch& sw);
        void normalize();
};

int stopWatch::getHours() const{
    return hours;
}

int stopWatch::getMinutes() const{
    return minutes;
}

int stopWatch::getSeconds() const{
    return seconds;
}

void stopWatch::setHours(int a){
    hours=a;
}

void stopWatch::setMinutes(int b){
    minutes=b;
}

void stopWatch::setSeconds(int c){
    seconds=c;
}

stopWatch& stopWatch::operator++(){
    seconds++;
    return *this;
}

stopWatch stopWatch::operator++(int){
    stopWatch old=*this;
    seconds++;
    return old;
}

ostream& operator<<(ostream& out,const stopWatch& sw){
    out<<setw(2)<<setfill('0')<<sw.getHours()<<":";
    out<<setw(2)<<setfill('0')<<sw.getMinutes()<<":";
    out<<setw(2)<<setfill('0')<<sw.getSeconds();
    return out;
}

istream& operator>>(istream& in,stopWatch& sw){
    cout<<"Enter hours,minutes and seconds to normalize : "<<endl;
    in>>sw.hours;
    in>>sw.minutes;
    in>>sw.seconds;
    sw.normalize();
    return in;
}

void stopWatch::normalize(){
    minutes+=seconds/60;
    seconds=seconds%60;

    hours+=minutes/60;
    minutes=minutes%60;
}

int main(){
    stopWatch s1;
    cin>>s1;
    ++s1;
    s1++;
    cout<<endl;
    cout<<s1;
    return 0;
}