#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct Canh
{
    int diemDau;
    int diemCuoi;
};
void docFile(string tenFile, vector<vector<int>> &maTran){
    int size;
    int temp;
    fstream input;
    input.open(tenFile,ios::in);
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
void dfsRecursion(int startPoint, int type, vector<vector<int>>maTran){
    int size;
    fstream input;
    input.open(tenFile,ios::in);
    input >> size;
    vector<int> dinhDaTham(size,0);
    cout<<startPoint+1<<" ";
    dinhDaTham[startPoint]=1;
    for(int i=0;i<canhDaTham.size();i++){
        if(maTran[startPoint][i]==1&&canhDaTham[i]==0)// tham canh chua dinh va dinh chua tham
        {
            canhDaTham[i]=1;
            for(int j=0;j<dinhDaTham.size();j++){
                if(maTran[j][i]==-1&&dinhDaTham[j]==0)
                dfsRecursion(j,MTTLT);
            }
        }
    }
}
