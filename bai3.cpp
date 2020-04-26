#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

struct dinh
{
    int diemDau;
    int diemCuoi;
};

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
vector<vector<int>> chuyenMaTran(vector<vector<int>>maTran){
    for(int i=0;i<maTran.size();i++){
        for(int j=0;j<maTran.size();j++){
            if(maTran[i][j]==1)
            maTran[j][i]=1;
        }
    }
    return maTran;
}
vector<dinh> danhSachCanh(vector<vector<int>> maTran){
    vector<dinh> danhSachCanh;
    int size=maTran.size();
    for(int i=0;i<size;i++){
        dinh temp;
        for(int j=0;j<size;j++){
            if(maTran[i][j]==1){
                temp.diemDau=i;
                temp.diemCuoi=j;
                danhSachCanh.push_back(temp);
            }
        }
    }
    return danhSachCanh;
}
vector<vector<int>> maTranLienThuoc(vector<vector<int>> maTran){
    vector<vector<int>>maTranLienThuoc;
    int size=maTran.size();
    vector<dinh> dinh;
    dinh = danhSachCanh(maTran);
    for(int i=0;i<size;i++){
        vector<int> temp;
        for(int j=0;j<dinh.size();j++){
            if(i==dinh[j].diemDau /*|| i==dinh[j].diemCuoi-1*/){
                temp.push_back(1);
            }
            else if(i==dinh[j].diemCuoi)
            temp.push_back(-1);
            else
            {
                temp.push_back(0);
            }
        }
     maTranLienThuoc.push_back(temp);
    }
    return maTranLienThuoc;
}
vector<vector<int>> danhSachKe(vector<vector<int>> maTran){
    vector<vector<int>> danhSachKe;
    for(int i=0;i<maTran.size();i++){
        vector<int> temp;
        for(int j=0;j<maTran.size();j++){
            if(maTran[i][j]==1){
                temp.push_back(j+1);
            }
        }
        danhSachKe.push_back(temp);
    }
    return danhSachKe;
}
void inDanhSachKe(vector<vector<int>> danhSachKe){
    for(int i=0;i<danhSachKe.size();i++){
        cout<<"Ke("<<i+1<<")=";
        for(int j=0;j<danhSachKe[i].size();j++){
            cout<<danhSachKe[i][j]<<" ";
        }
        cout<<endl;
    }
}
void inDanhSachCanh(vector<dinh> danhSachCanh){
    for(int i=0;i<danhSachCanh.size();i++){
        cout<<danhSachCanh[i].diemDau+1<<"  "<<danhSachCanh[i].diemCuoi+1<<endl;
    }
}
int main()
{
    vector<vector<int>>maTran;
    vector<vector<int>>maTranLienThuoc1;
    vector<vector<int>>danhSachKe1;
    vector<dinh>danhSachCanh1;
    vector<vector<int>>chuyenMaTran1;
    cout<<"Ma tran ke:"<<endl;
    docFile("matrix.dat", maTran);
    inMaTran(maTran);
    cout<<"Danh sach canh:"<<endl;
    danhSachCanh1=danhSachCanh(maTran);
    inDanhSachCanh(danhSachCanh1);
    cout<<"Ma tran lien thuoc:"<<endl;
    maTranLienThuoc1=maTranLienThuoc(maTran);
    inMaTran(maTranLienThuoc1);
    chuyenMaTran1=chuyenMaTran(maTran);
    cout<<"Danh sach ke:"<<endl;
    danhSachKe1=danhSachKe(chuyenMaTran1);
    inDanhSachKe(danhSachKe1);
    return 0;
}