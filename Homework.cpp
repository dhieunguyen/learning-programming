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
void inRaMaTran(vector<vector<int>> maTran){
    for(int i=0;i<maTran.size();i++){
        for(int j=0;j<maTran[i].size();j++){
            cout<<maTran[i][j]<<" ";
        }
          cout<<endl;
    }
            cout<<endl;
}
void inRaDanhSachCanh(vector<Canh> danhSachCanh){
    for(int i=0;i<danhSachCanh.size();i++){
        cout<<danhSachCanh[i].diemDau<<" "<<danhSachCanh[i].diemCuoi<<endl;
    }
}
vector<Canh> danhSachCanh(vector<vector<int>> maTran){
    vector<Canh> danhSachCanh;
    int size=maTran.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            Canh temp;
            if(maTran[i][j]==1){
                temp.diemDau=i+1;
                temp.diemCuoi=j+1;
                danhSachCanh.push_back(temp);
            }
        }
    }
    int temp=danhSachCanh.size();
    return danhSachCanh;
}
int main(){
    vector<vector<int> > maTran;
    vector<Canh> danhSachCanh1;
    docFile("matrix.dat",maTran);
    inRaMaTran(maTran);
    cout<<endl;
    danhSachCanh1 = danhSachCanh(maTran);
    inRaDanhSachCanh(danhSachCanh1);
}