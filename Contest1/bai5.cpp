#include<iostream>
#include<vector>

using namespace std;
bool check = true;
int N,K;
int array[50];
void inIt(){
    cin>>N>>K;
    for(int i=1;i<=K;i++){
        array[i]=i;
    }
}
void display(){
    for(int i=1;i<=K;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void nextCombination(){
    int i=K;
    while(i>0&&array[i]==N-K+i)
    i--;
    if(i>0){
        array[i]++;
        for(int j=i+1;j<=K;j++)
        array[j]=array[i]+j-i;
    }
    else
    check = false;
}
void process(){
    inIt();
        while(check){
        display();
        nextCombination();
    }
    check=true;
}
int main(){
   int t;
   cin>>t;
   while(t--){
       process();
       cout<<endl;
   }
}