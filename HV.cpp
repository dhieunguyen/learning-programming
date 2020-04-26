#include<iostream>

using namespace std;
int count,i,a[1001];
bool OK=true;
void Init(){
    cin>>count;
    for (size_t i = 1; i <= count; i++)
    {
        a[i]=i;
    }
}
void Display(){
    for (size_t i = 1; i <= count; i++)
    {
        cout<<a[i];
    }
    cout<<"\n";
}
void HoanVi(){
   int i = count- 1; 
	while( i > 0 && a[i] > a[i+1] ) i--; 
	if( i > 0 ){
		int k = count; 
		while( a[i] > a[k] ) k--; 
		int t = a[i]; a[i] = a[k]; a[k] = t; 
		int r = i + 1, s = count;
		while( r <= s ){ 
			int tg = a[r]; a[r] = a[s]; a[s] = tg;
			r++; s--;
		}
	}
    else OK=false;
}
int main(){
    Init();
    while(OK){
        Display();
        HoanVi();
    }
}