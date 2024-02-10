//MSSV:23110274

//Ho Ten SV: Huynh Duy Nguyen

//Ngày sinh: 16/12/2005

//Lop: PRTE230385_23_2_05
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
struct sv{
    string msv,ten,namsinh;
    float dtoan,dly,dhoa,dtb;
};
struct date
{
    int dd,mm,yy;
};

void nhapbp(sv &a){
    cin >> a.msv;
    cin.ignore();
    getline(cin,a.ten);
    getline(cin,a.namsinh);
    cin >> a.dtoan >> a.dly >> a.dhoa;
    a.dtb=(a.dtoan+a.dhoa+a.dly)/3;
}
void xuatfile(sv a,fstream &ou1){
    ou1 << "Ma so sinh vien: " <<a.msv << endl;
    ou1 << "Ho va ten: " << a.ten << endl;
    ou1 << "Ngay sinh: " << a.namsinh << endl;
    ou1 << "Diem toan: " << a.dtoan << endl;
    ou1 << "Diem ly: " << a.dly << endl;
    ou1 << "Diem hoa: " << a.dhoa << endl;  
    ou1 << "Diem trung binh: " << a.dtb << endl;
}
void nhapfile(sv &a,fstream &in1){
    in1 >> a.msv;
    in1.ignore();
    getline(in1,a.ten);
    getline(in1,a.namsinh);
    in1 >> a.dtoan; 
    in1 >> a.dly;
    in1 >> a.dhoa;
    a.dtb=(a.dtoan+a.dhoa+a.dly)/3;
}
void xuatbp(sv a){
    cout << "Ma so sinh vien: " <<a.msv << endl;
    cout << "Ho va ten: " << a.ten << endl;
    cout << "Ngay sinh: " << a.namsinh << endl;
    cout << "Diem toan: " << a.dtoan << endl;
    cout << "Diem ly: " << a.dly << endl;
    cout << "Diem hoa: " << a.dhoa << endl;  
    cout << "Diem trung binh: " << a.dtb << endl;
}
sv svmaxdtb(sv a[],int n){
    sv temp = a[0];
    for(int i=0;i<n;i++)
        if(a[i].dtb>temp.dtb)
            temp = a[i];
    return temp;
}
bool sv53(sv a){
    if(a.dtb <= 5 || a.dhoa < 3 || a.dly < 3 || a.dtoan < 3)
        return false;
    return true;
}
date da(sv a){
   date t;
   string k = a.namsinh;
   t.dd = stoi(k.substr(0,2));
   
   t.mm = stoi(k.substr(3,4));

   t.yy = stoi(k.substr(6,9));
   return t;
}
bool tuoi(sv a,sv b){
   date ta = da(a);
   date tb = da(b);
   if(ta.yy > tb.yy)
       return false;
   if(ta.yy<tb.yy)
       return true;
   else if(ta.mm < tb.mm)
       return true;
   else if(ta.dd < tb.dd)
       return true;
   return false;
}
sv agemax(sv a[],int n){
   sv t = a[0];
   for(int i = 1; i < n;i++)
       if(tuoi(a[i],t))
           t = a[i];
   return t;
}
int main(){
    sv a[100],b[100];int n;    
    fstream ou1,in1,ou2;
    ou1.open("Bai11out1.txt",ios::out);
    in1.open("Bai11in1.txt",ios::in);
    ou2.open("Bai11outd.txt",ios::out);
    // Cau a
    cin >> n;
    for(int i=0;i<n;i++)
        nhapbp(a[i]);
    for(int i=0;i<n;i++)
        xuatfile(a[i],ou1);
    //cau b
    in1 >> n;
    for(int i=0;i<n;i++)
        nhapfile(b[i],in1);
    for(int i=0;i<n;i++)
        xuatbp(b[i]);
    //cau c
    sv sv_max_dtb = svmaxdtb(b,n);  
    cout << "Sinh Vien co diem trung binh cao nhat: \n";
    xuatbp(sv_max_dtb);
    //cau d
    for(int i=0;i<n-1;i++)
        for(int j = i;j<n;j++)
            if(b[j].dtb<b[i].dtb){
                sv t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
    ou2 << "Sap xep theo tang dan diem trung binh\n";        
    for (int i = 0; i < n; i++)
    {
        xuatfile(b[i],ou2);
    }
    //cau e
    for(int i=0;i<n-1;i++)
        for(int j = i;j<n;j++)
            if(b[j].dtoan>b[i].dtoan){
                sv t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
    cout << "Danh sach sinh co diem toan giam dan: \n";
    for(int i=0;i<n;i++)
        xuatbp(b[i]);
    //cau f
    cout << "Cac sinh vien co DTB > 5 va khong mon nao duoi 3 :\n";
    for(int i=0;i<n;i++)
        if(sv53(b[i]))
            xuatbp(b[i]);
    //cau g
    cout << "Sinh vien co tuoi lon nhat:\n";
    sv p = agemax(b,n);
    xuatbp(p);
    //cau h
    string h;
    cout << "Nhap ten sinh vien can tim : ";
    getline(cin,h);
    for(int i =0;i < n;i++)
        if(b[i].ten.find(h) != string::npos)
            xuatbp(b[i]);   
    in1.close();
    ou1.close();
    ou2.close();
    return 0;
}
