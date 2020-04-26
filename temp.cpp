#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
const int cohuong = 1;
const int vohuong = 0;
const int MIN = 1;
const int MAX = 20;
const int MTTLT = 1;
const int DSK = 2;
using namespace std;

struct dinh
{
    int diemDau;
    int diemCuoi;
    int trongSo;
};
void randGraph(int soDinh, double matDo, int loai, vector<vector<int> > &maTranKe, vector<vector<int> > &maTranTrongSo)
{
    int size = soDinh;
    int soCanh = 0;
    vector<int>dinhDaTham(size,0);
    vector<vector<int> > maTran(size, vector<int>(size, 0));
    maTranKe = maTran;
    maTranTrongSo = maTran;
    switch (loai)
    {
    case vohuong:
        for (int i = 0; i < size; i++)
        {
            dinh temp;
            int weight;
            for (int j = i + 1; j < size; j++)
            {
                if (((double)(rand()) / RAND_MAX) < matDo)
                {
                    weight = rand() % MAX + MIN;

                    soCanh++;
                    maTranKe[i][j] = 1;
                    maTranKe[j][i] = 1;
                    maTranTrongSo[i][j] = weight;
                    maTranTrongSo[j][i] = weight;
                    
                }
            }
            vector<int>canh(soCanh,0);
        }
        break;
    case cohuong:
        for (int i = 0; i < size; i++)
        {
            int weight;
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                    continue;
                if (((double)(rand()) / RAND_MAX) < matDo)
                {
                    weight = rand() % MAX + MIN;

                    soCanh++;
                    maTranKe[i][j] = 1;
                    maTranTrongSo[i][j] = weight;
                }
            }
        }
        vector<int>canh(soCanh,0);
        break;
    default:
        break;
    }
}
void inMaTran(vector<vector<int> > maTran,string filePath)
{
        ofstream file(filePath,ios::app);

    for (int i = 0; i < maTran.size(); i++)
    {
        for (int j = 0; j < maTran[i].size(); j++)
        {
            file << maTran[i][j] << " ";
        }
        file << endl;
    }
    file << endl;
    file.close();
}
vector<vector<int> > chuyenMaTran(vector<vector<int> > maTran)
{
    for (int i = 0; i < maTran.size(); i++)
    {
        for (int j = 0; j < maTran.size(); j++)
        {
            if (maTran[i][j] == 1)
                maTran[j][i] = 1;
        }
    }
    return maTran;
}
vector<dinh> danhSachCanh(vector<vector<int> > maTran, int loai)
{
    vector<dinh> danhSachCanh;
    int size = maTran.size();
    int trongSo;
    switch (loai)
    {
    case vohuong:
    {
        for (int i = 0; i < size; i++)
        {
            dinh temp;
            for (int j = i + 1; j < size; j++)
            {
                trongSo = rand() % MAX + MIN;
                if (maTran[i][j] != 0)
                {
                    temp.diemDau = i;
                    temp.diemCuoi = j;
                    temp.trongSo = trongSo;
                    danhSachCanh.push_back(temp);
                }
            }
        }
        break;
    }
    case cohuong:
    {
        for (int i = 0; i < size; i++)
        {
            dinh temp;
            for (int j = 0; j < size; j++)
            {
                trongSo = rand() % MAX + MIN;
                if (maTran[i][j] != 0)
                {
                    temp.diemDau = i;
                    temp.diemCuoi = j;
                    temp.trongSo = trongSo;
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
vector<vector<int> > maTranLienThuoc(vector<vector<int> > maTran, int loai)
{
    vector<vector<int> > maTranLienThuoc;
    int size = maTran.size();
    vector<dinh> dinh;
    dinh = danhSachCanh(maTran, loai);
    switch (loai)
    {
    case vohuong:
    {
        for (int i = 0; i < size; i++)
        {
            vector<int> temp;
            for (int j = 0; j < dinh.size(); j++)
            {
                if (i == dinh[j].diemDau || i == dinh[j].diemCuoi)
                    temp.push_back(1);
                else
                    temp.push_back(0);
            }
            maTranLienThuoc.push_back(temp);
        }
        break;
    }
    case cohuong:
    {
        for (int i = 0; i < size; i++)
        {
            vector<int> temp;
            for (int j = 0; j < dinh.size(); j++)
            {
                if (i == dinh[j].diemDau)
                    temp.push_back(1);
                else if (i == dinh[j].diemCuoi)
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
vector<vector<int> > danhSachKe(vector<vector<int> > maTran)
{
    vector<vector<int> > danhSachKe;
    for (int i = 0; i < maTran.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < maTran.size(); j++)
        {
            if (maTran[i][j] == 1)
            {
                temp.push_back(j + 1);
            }
        }
        danhSachKe.push_back(temp);
    }
    return danhSachKe;
}
void inDanhSachKe(vector<vector<int> > danhSachKe,string filePath)
{
    ofstream file(filePath,ios::app);
    for (int i = 0; i < danhSachKe.size(); i++)
    {
        file << "Ke(" << i + 1 << ")=";
        for (int j = 0; j < danhSachKe[i].size(); j++)
        {
            file << danhSachKe[i][j] << " ";
        }
        file << endl;
    }
}
void inDanhSachCanh(vector<dinh> danhSachCanh,string filePath)
{
    ofstream file(filePath,ios::app);
    file << "Diem dau"
         << "\t"
         << "Diem cuoi"
         << "\tTrong so" << endl;
    for (int i = 0; i < danhSachCanh.size(); i++)
    {
        file << "   " << danhSachCanh[i].diemDau + 1 << "\t\t"
             << "   " << danhSachCanh[i].diemCuoi + 1 << "\t\t   " << danhSachCanh[i].trongSo << endl;
    }
}
void dfsRecursion(int startPoint, int type){
    vector<int> canhDaTham = canh;
    cout<<startPoint+1<<" ";
    dinhDaTham[startPoint]=1;
    for(int i=0;i<canhDaTham.size();i++){
        if(maTranLienThuoc[startPoint][i]==1&&canhDaTham[i]==0)// tham canh chua dinh va dinh chua tham
        {
            canhDaTham[i]=1;
            for(int j=0;j<dinhDaTham.size();j++){
                if(maTranLienThuoc[j][i]==-1&&dinhDaTham[j]==0)
                dfsRecursion(j,MTTLT);
            }
        }
    }
}
int main()
{
    // vector<vector<int> > maTranKe;
    // vector<vector<int> > maTranTrongSo;
    // vector<vector<int> > maTran;
    // vector<vector<int> > maTranLienThuoc1;
    // vector<vector<int> > danhSachKe1;
    // vector<dinh> danhSachCanh1;
    // vector<vector<int> > chuyenMaTran1;
    // vector<vector<int> > maTranTrongSo1;
    // //dua ra ma tran ke vo huong
    // randGraph(20, 0.2, vohuong, maTranKe, maTranTrongSo);//thay doi vohuong -> cohuong de tao ma tran co huong
    // randGraph(50, 0.2, vohuong, maTranKe, maTranTrongSo);
    // randGraph(100, 0.2, vohuong, maTranKe, maTranTrongSo);
    // inMaTran(maTranKe,"matrix20.dat");
    // inMaTran(maTranKe,"matrix50.dat");
    // inMaTran(maTranKe,"matrix100.dat");

    // //dua ra ma tran trong so vo huong
    // inMaTran(maTranTrongSo,"matrix20.dat");//thay doi vohuong -> cohuong de tao ma tran trong so co huong
    // inMaTran(maTranTrongSo,"matrix50.dat");
    // inMaTran(maTranTrongSo,"matrix100.dat");

    // //dua ra danh sach canh
    // danhSachCanh1 = danhSachCanh(maTranKe, vohuong);//thay doi vohuong -> cohuong de tao danh sach canh co huong
    // inDanhSachCanh(danhSachCanh1,"matrix20.dat");
    // inDanhSachCanh(danhSachCanh1,"matrix50.dat");
    // inDanhSachCanh(danhSachCanh1,"matrix100.dat");
    // //dua ra ma tran lien thuoc vo huong
    // maTranLienThuoc1 = maTranLienThuoc(maTranKe, vohuong);//thay doi vohuong -> cohuong de tao ma tran lien thuoc co huong
    // inMaTran(maTranLienThuoc1,"matrix20.dat");
    // inMaTran(maTranLienThuoc1,"matrix50.dat");
    // inMaTran(maTranLienThuoc1,"matrix100.dat");

    // //dua ra danh sach ke
    // chuyenMaTran1 = chuyenMaTran(maTranKe);
    // danhSachKe1 = danhSachKe(chuyenMaTran1);
    // inDanhSachKe(danhSachKe1,"matrix20.dat");
    // inDanhSachKe(danhSachKe1,"matrix50.dat");
    // inDanhSachKe(danhSachKe1,"matrix100.dat");
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
    dfsRecursion(1,MTTLT);
    return 0;
}