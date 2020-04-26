#include<iostream>
#include<string>

using namespace std;
string input;
bool OK = true;
int n;
void inIt(){
    cin>>n;
    for(int i=0;i<n;i++){
        input[i]='A';
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
    while(i>=0&&input[i]=='B'){
        input[i]='A';
        i--;
    }
    if(i>=0){
        input[i]='B';
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