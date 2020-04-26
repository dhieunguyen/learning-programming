#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#define TRUE 1
#define FALSE 0

using namespace std;

void docFile(string fileName, vector<vector<int>> &maTran)
{
    fstream input;
    input.open(fileName, ios::in);
    int size;
    int temp;
    input >> size;
    for(int i=0;i<size;i++){
        vector<int> tempA;
        for(int j=0;j<size;j++){
            input >> temp;
            tempA.push_back(temp);
        }
        maTran.push_back(tempA);
    }
}
void inMaTran(vector<vector<int>> maTran){
    for(int i=0;i<maTran.size();i++){
        for(int j=0;j<maTran[i].size();j++){
            cout<<maTran[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//xem từ đây
vector<int> chuaxet;
void inIt(vector<vector<int>> maTran){
    for(int i=1;i<=maTran.size();i++){
        chuaxet.push_back(TRUE);
    }
}
void DFS(int u,vector<vector<int>> maTran){
    int v;
    cout<<u;
    chuaxet[u]=FALSE;
    for(v=1;v<=maTran.size();v++){
        if(maTran[u][v]&&chuaxet[v])
        DFS(v,maTran);
    }
    
}
int main()
{
    vector<vector<int>>maTran;
    docFile("matrix2.dat", maTran);
    inMaTran(maTran);
    int u;
    cout<<"Nhap u:";
    cin>>u;
    inIt(maTran);
    DFS(u,maTran);
    return 0;
}