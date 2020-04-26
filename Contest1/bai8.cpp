#include<iostream>

using namespace std;
bool check = true;
int N,K;
int array[50];
void inIt(){
    cin>>N;
    for(int i=1;i<=N;i++){
        array[i]=i;
    }
}
void display(){
    for(int i=1;i<=N;i++){
        cout<<N-array[i]+1;
    }
    cout<<endl;
}
void nextCombination(){
    int i=N-1;
    while(i>0&&array[i]>array[i+1])
    i--;
    if(i>0){
        K=N;
        while(array[i]>array[K]){
            K--;
        }
        int t = array[i];  
        array[i]=array[K];
        array[K] = t; 
		int r = i + 1, s = N;
		while( r <= s ){ 
			int t = array[r]; 
            array[r] = array[s]; 
            array[s] = t;
			r++; s--;
        }
    }
        else
        check=false;
}
void process(){
    inIt();
    while (check)
    {
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
    }
}