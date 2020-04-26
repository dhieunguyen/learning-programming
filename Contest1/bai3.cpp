#include<iostream>

using namespace std;
bool check = true;
int N,K;
int array[50];
void inIt(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>array[i];
    }
}
void nextCombination(int N,int array[]){
    int i=N-1;
    int j=i+1;
    int K=N;
    while(i>0&&array[i]>array[j])
    i--;
    if(i>0){
        while(array[K]<array[j]){
            K--;
        }
        array[j]=array[K];
        	int t = array[i];  
            array[i] = array[K]; 
            array[K] = t; 
		int r = i + 1, s = N;
		while( r <= s ){ 
			int tg = array[r]; 
            array[r] = array[s]; 
            array[s] = tg;
			r++; s--;
        }
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
    nextCombination(N,array);
    cout<<endl;
    }
}