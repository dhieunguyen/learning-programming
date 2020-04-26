#include<iostream>

using namespace std;

// int dem(int a){
//     if(a>=0&&a<=9) return a;
//     else
//     return (dem(a/10)+1);
// }

int dem(int a){
    if(a/10 == 0) return 1;
    else
    return (dem(a/10)+1);
}

int main(){
    cout<<dem(10001)<<endl;
}