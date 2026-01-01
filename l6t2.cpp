#include<bits/stdc++.h>
using namespace std;

class socialPost{
    private:
        int postID;
        int likes;
        int shares;
        int viralScore=(likes*1)+(shares*3);
        void checkUnderZero(){
            if(likes<0&&shares>0){
                likes=0;
            } else if(likes>0&&shares<0){
                shares=0;
            } else if(likes<0&&shares<0){
                likes=0;
                shares=0;
            }
        }
    public:
        int getPostID() const;
        int getLikes() const;
        int getShares() const;
        void setPostID(int a);
        void setLikes(int b);
        void setShares(int c);
        socialPost(int d,int e,int f):postID(d),likes(e),shares(f){}
        ~socialPost(){
            cout<<"Closing the app"<<endl;
        }
        socialPost& operator+=(int g);
        socialPost& operator-=(int g);
        bool operator==(const socialPost& sp) const;
        bool operator>(const socialPost& sp) const;
        bool operator<(const socialPost& sp) const;
};

int socialPost::getPostID() const{
    return postID;
}

int socialPost::getLikes() const{
    return likes;
}

int socialPost::getShares() const{
    return shares;
}

void socialPost::setPostID(int a){
    postID=a;
}

void socialPost::setLikes(int b){
    likes=b;
}

void socialPost::setShares(int c){
    shares=c;
}

socialPost& socialPost::operator+=(int g){
    likes+=g;
}

socialPost& socialPost::operator-=(int g){
    likes-=g;
}

bool socialPost::operator==(const socialPost& sp) const{
    if(viralScore==sp.viralScore){
        return true;
    }
    return false;
}

bool socialPost::operator>(const socialPost& sp) const{
    if(viralScore>sp.viralScore){
        return true;
    }
    return false;
}

bool socialPost::operator<(const socialPost& sp) const{
    if(viralScore<sp.viralScore){
        return true;
    }
    return false;
}

int main(){
    socialPost post1(1,10802,127);
    socialPost post2(2,9597,139);
    post1+=50;
    if(post1>post2){
        cout<<"Post 1 is trending"<<endl;
    } else{
        cout<<"Post 2 is trending"<<endl;
    }
    if(post1==post2){
        cout<<"Both post 1 and post 2 have got the same viral score"<<endl;
    } else{
        cout<<"Both post 1 and post 2 don't have the same viral score"<<endl;
    }
    return 0;
}