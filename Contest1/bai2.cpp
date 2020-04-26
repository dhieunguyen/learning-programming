#include<iostream>

using namespace std;
bool check = true;
int N,K;
int array[50];
void inIt(){
    cin>>N>>K;
    for(int i=1;i<=K;i++){
        cin>>array[i];
    }
}
void nextCombination(int N,int K,int array[]){
    int i=K;
    while(i>0&&array[i]==N-K+i)
    i--;
    if(i>0){
        array[i]++;
        for(int j=i+1;j<=K;j++)
        array[j]=array[i]+j-i;
    }
        else
    {
        for(int i=1;i<=K;i++){
            array[i]=i;
        }
    }               
    for(int i=1;i<=K;i++){
        cout<<array[i]<<" ";
        }

}
int main(){
    int t;
    cin>>t;
    while(t--){ 
    inIt();
    nextCombination(N,K,array);
    cout<<endl;
    }
}