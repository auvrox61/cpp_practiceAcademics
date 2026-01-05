#include<bits/stdc++.h>
using namespace std;

class student{
    private:
        int marks[5];
    public:
        student(){
            for(int i=0;i<5;i++){
                marks[i]=-1;
            }
        }
        student(const student& st){
            for(int i=0;i<5;i++){
                marks[i]=st.marks[i];
            }
        }
        void showMarks() const;
};

void student::showMarks() const{
    for(int i=0;i<5;i++){
        cout<<marks[i]<<" ";
    }
}

int main(){
    student s1;
    student s2=s1;
    s2.showMarks();
    return 0;
}