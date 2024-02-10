//MSSV:23110274

//Ho Ten SV: Huynh Duy Nguyen

//Ngày sinh: 16/12/2005

//Lop: PRTE230385_23_2_05
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct sp
{
    string ma,ten;
    int sl,slton,timebh;
    long dg;
};
void nhap(sp &a,fstream &in){
    in >> a.ma;
    in.ignore();
    getline(in,a.ten);
    in >> a.sl >> a.dg >> a.slton >> a.timebh; 
}
void xuat(sp a, fstream &ou){
    ou << a.ma << endl;
    ou << a.ten << endl;
    ou << a.sl << endl;
    ou << a.dg << endl;
    ou << a.slton << endl;
    ou << a.timebh << endl;
}
int main(){
    int n;
    sp a[100];
    fstream in,ou;
    in.open("Bai10in.txt",ios::in);
    ou.open("Bai10out.txt",ios::out);
    in >> n;
    for(int i=0;i<n;i++)
        nhap(a[i],in);
    sp t = a[0];
    for(int i=0;i<n;i++)
        if(a[i].slton>t.slton){
            t = a[i];
        }    
    ou << "Mat hang co so luong ton lon nhat la : " << t.ten << endl;
    for(int i=0;i<n;i++)
        if(a[i].slton<t.slton){
            t = a[i];
        }    
    ou << "Mat hang co so luong ton it nhat la : " << t.ten << endl;
    for(int i=0;i<n;i++)
        if(a[i].dg>t.dg){
            t = a[i];
        }  
    ou << "Mat hang co gia tien nhat la : " << t.ten << endl;
    ou << "Mat hang co thoi gian bao hanh lon hon 12 thang la : " <<  endl;
    for(int i=0;i<n;i++)
        if(a[i].timebh > 12){
            ou << " + " << a[i].ten << endl;
        }  
    ou << "Theo thu tu tang dan cua so luong ton:\n";
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if(a[i].slton > a[j].slton)
                swap(a[i],a[j]);
    for(int i=0;i<n;i++)
            ou << " + " << a[i].ten << endl;
    in.close();
    ou.close();
    return 0;
}