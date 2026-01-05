#include<bits/stdc++.h>
using namespace std;

class student{
    private:
        int marks[5];
    public:
        void setIndexMarks(int i,int j);
        int getIndexMarks(int k) const;
};

void student::setIndexMarks(int i,int j){
    if(i>=0&&i<5){
        marks[i]=j;
    } else{
        cout<<"Array size exceeded!"<<endl;
    }
}

int student::getIndexMarks(int k) const{
    if(k>=0&&k<5){
        return marks[k];
    }
    return -1;
}

int main(){
    student s;
    s.setIndexMarks(0,12);
    s.setIndexMarks(1,13);
    s.setIndexMarks(2,14);
    s.setIndexMarks(3,15);
    s.setIndexMarks(4,16);
    cout<<s.getIndexMarks(3)<<endl;
    cout<<s.getIndexMarks(8);
    return 0;
}