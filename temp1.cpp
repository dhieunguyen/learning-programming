#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include <sstream>
const int cohuong = 1;
const int vohuong = 0;
const int MIN=1;
const int MAX=20;
const bool WeightMatrix = 1;
const bool nonWeightMatrix = 0;
using namespace std;

struct dinh
{
    int diemDau;
    int diemCuoi;
    int trongSo;
};
vector<vector<int>>randGraph(int soDinh, double matDo, int loai, bool isWeightMatrix){
    int size = soDinh;
    int soCanh = 0;
    vector<vector<int> > maTran(size, vector<int>(size, 0));
    vector<vector<int> >maTranKe;
    maTranKe = maTran;
    switch (loai)
    {
    case vohuong:
    for(int i = 0 ; i<size;i++){
        dinh temp;
        int trongSo;
        for(int j = i+1;j<size;j++){
            if(((double)(rand()) / RAND_MAX) < matDo){
                trongSo = rand() % MAX + MIN;
                soCanh++;
                maTranKe[i][j]=1;
                maTranKe[j][i]=1;
            }
        }
    }
        break;
    case cohuong:
    for(int i = 0 ; i<size;i++){
        for(int j = 0 ; j<size;j++){
            if(i==j)continue;
            if(((double)(rand()) / RAND_MAX) < matDo){
                soCanh++;
                maTranKe[i][j]=1;
            }
        }
    }
    break;    
    default:
        break;
    }
    return maTranKe;
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
vector<dinh> danhSachCanh(vector<vector<int>> maTran, int loai){
    vector<dinh> danhSachCanh;
    int size=maTran.size();
    int trongSo;
    switch (loai)
    {
    case vohuong:{
        for(int i=0;i<size;i++){
        dinh temp;
        for(int j=i+1;j<size;j++){
            trongSo = rand() % MAX + MIN;
            if(maTran[i][j]!=0){
                temp.diemDau=i;
                temp.diemCuoi=j;
                temp.trongSo=trongSo;
                danhSachCanh.push_back(temp);
            }
        }
    }
        break;
    }
    case cohuong:{
        for(int i=0;i<size;i++){
        dinh temp;
        for(int j=0;j<size;j++){
            trongSo = rand() % MAX + MIN;
            if(maTran[i][j]!=0){
                temp.diemDau=i;
                temp.diemCuoi=j;
                temp.trongSo=trongSo;
                danhSachCanh.push_back(temp);
                    }
                }
            }
    default:
        break;
        }
    }
    return danhSachCanh;
}
vector<vector<int>> maTranLienThuoc(vector<vector<int>> maTran, int loai){
    vector<vector<int>>maTranLienThuoc;
    int size=maTran.size();
    vector<dinh> dinh;
    dinh = danhSachCanh(maTran,loai);
    switch (loai)
    {
    case vohuong:{
        for(int i=0;i<size;i++){
        vector<int> temp;
        for(int j=0;j<dinh.size();j++){
                if(i==dinh[j].diemDau||i==dinh[j].diemCuoi)
                temp.push_back(1);
                else
                temp.push_back(0);
        }
            maTranLienThuoc.push_back(temp);
    }
        break;
    }
    case cohuong:{
         for(int i=0;i<size;i++){
        vector<int> temp;
        for(int j=0;j<dinh.size();j++){
                if(i==dinh[j].diemDau)
                temp.push_back(1);
                else if(i==dinh[j].diemCuoi)
                temp.push_back(-1);
                else
                    temp.push_back(0);
        }
            maTranLienThuoc.push_back(temp);
    }
    break;
    }
    default:
        break;
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
    cout<<"Diem dau"<<"\t"<<"Diem cuoi"<<"\tTrong so"<<endl;
    for(int i=0;i<danhSachCanh.size();i++){
        cout<<"   "<<danhSachCanh[i].diemDau+1<<"\t\t"<<"   "<<danhSachCanh[i].diemCuoi+1<<"\t\t   "<<danhSachCanh[i].trongSo<<endl;
    }
}
int main()
{
    vector<vector<int>>maTranKe;
    vector<vector<int>>maTran;
    vector<vector<int>>maTranLienThuoc1;
    vector<vector<int>>danhSachKe1;
    vector<dinh>danhSachCanh1;
    vector<vector<int>>chuyenMaTran1;
    vector<vector<int>>maTranTrongSo1;
    cout<<"Ma tran ke:"<<endl;
    maTranKe=randGraph(6, 0.2, cohuong,true);
    inMaTran(maTranKe);
    cout<<"Danh sach canh:"<<endl;
    danhSachCanh1=danhSachCanh(maTranKe,cohuong);
    inDanhSachCanh(danhSachCanh1);
    cout<<"Ma tran lien thuoc:"<<endl;
    maTranLienThuoc1=maTranLienThuoc(maTranKe,cohuong);
    inMaTran(maTranLienThuoc1);
    chuyenMaTran1=chuyenMaTran(maTranKe);
    cout<<"Danh sach ke:"<<endl;
    danhSachKe1=danhSachKe(chuyenMaTran1);
    inDanhSachKe(danhSachKe1);
    return 0;
}