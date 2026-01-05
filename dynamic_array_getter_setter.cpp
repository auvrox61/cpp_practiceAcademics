#include<bits/stdc++.h>
using namespace std;

class student{
    private:
        int* marks;
        int size;
    public:
        student(int n){
            size=n;
            marks=new int[n];
            for(int i=0;i<n;i++){
                marks[i]=-1;
            }
        }
        void setMarks(int i,int j){
            if(i>=0&&i<size){
                marks[i]=j;
            }
        }
        int getMarks(int k) const{
            if(k>=0&&k<size){
                return marks[k];
            }
            return -1;
        }
};

int main(){
    student s(4);
    s.setMarks(2,13);
    cout<<s.getMarks(2)<<endl;
    return 0;
}