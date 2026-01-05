#include<bits/stdc++.h>
using namespace std;

class student{
    private:
        int marks[3];
    public:
        student(){
            for(int i=0;i<3;i++){
                marks[i]=-1;
            }
        }
        void showMarks() const;
};

void student::showMarks() const{
    for(int i=0;i<3;i++){
        cout<<marks[i]<<" ";
    }
}

int main(){
    student s;
    s.showMarks();
    return 0;
}