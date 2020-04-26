#include<iostream>
#define MAX 100 
#define TRUE 1 
#define FALSE 0 

using namespace std;

int n, C[MAX], k, count, Stop; 

void Init(){ 
    cin>>n; k=1; C[k]=n; 
} 

void Result(){ 
	int i; 
        for(i=1; i<=k; i++) 
       cout<<C[i]<<" ";
       cout<<endl;
}

void Next_Division(){ 
	int i, j, R, S, D; 
        i= k;
        while(i>0 && C[i]==1) 
	                i--; 
        if(i>0){ 
                  C[i] = C[i]-1; 
                  D = k - i +1; 
                  R = D / C[i]; 
                  S = D % C[i]; 
                  k = i; 
                  if(R>0){ 
                              for(j=i+1; j<=i+R; j++) 
	                              C[j] = C[i]; 
                              k = k+R;
                         }
                  if(S>0){
                              k=k+1; C[k] = S;
                         }
                  } 
      else Stop=TRUE;
}

void Division(){ 
	Stop = FALSE; 
         while (!Stop){ 
                           Result(); 
                            Next_Division();
                          }
} 

int main(){ 
Init(); Division();
}