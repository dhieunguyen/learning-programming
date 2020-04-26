#include<iostream>
#include<string>

using namespace std;

string nextBinary(string input){
    int i=input.size()-1;
    while(i>=0&&input[i]=='1'){
        input[i]='0';
        i--;
    }
    if(i>=0){
        input[i]='1';
    }
    return input;
}
int main(){
    int test;
    string input;
    cin>>test;
    while(test--){
        cin>>input;
        cout<<nextBinary(input)<<endl;
    }
}