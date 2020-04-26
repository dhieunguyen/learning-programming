#include<iostream>


using namespace std;
int input[50] ;
bool OK = true;
int n;
void inIt(){
    cin>>n;
    for(int i=0;i<n;i++){
        input[i]=0;
    }
}
void display(){
    for(int i=0;i<n;i++){
        cout<<input[i];
    }
    cout<<endl;
}
void nextBinary(){
    int i=n-1;
    while(i>=0&&input[i]==1){
        input[i]=0;
        i--;
    }
    if(i>=0){
        input[i]=1;
    }
    else
    OK=false;
}
void process(){
        inIt();
    while(OK)
    {
        display();
        nextBinary();
    }
    OK=true;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        process();
    }
    return 0;
}