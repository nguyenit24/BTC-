//MSSV:23110274

//Ho Ten SV: Huynh Duy Nguyen

//Ngày sinh: 16/12/2005

//Lop: PRTE230385_23_2_05
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct mve
{
    string name,tloai,tddien,tna9,tn9,hsx;
    int nam;
};
void nhapfile(mve &a,fstream &in){
    getline(in,a.name);
    getline(in,a.tloai);
    getline(in,a.tddien);
    getline(in,a.tna9);
    getline(in,a.tn9);
    in >> a.nam;
    in.ignore();
    getline(in,a.hsx);
}
void infile(mve a,fstream &ou){
    ou << a.name << endl;
    ou << a.tloai << endl;
    ou << a.tddien << endl;
    ou << a.tna9 << endl;
    ou << a.tn9 << endl;
    ou << a.nam << endl;
    ou << a.hsx << endl;
}
void ins(mve a){
    cout << "Ten phim " << a.name << endl;
    cout << "The loai " << a.tloai << endl;
    cout << "Ten dao dien " <<a.tddien << endl;
    cout << "Ten nam chinh " << a.tna9 << endl;
    cout << "Ten nu chinh " << a.tn9 << endl;
    cout << "Nam san xuat " << a.nam << endl;
    cout << "Hang san xuat " << a.hsx << endl;
}
int main(){
    int n;
    mve a[50];
    fstream in,ou;
    in.open("D:\\HT\\C\\ktlt\\file\\Bai12in.txt",ios::in);
    ou.open("Bai12out.txt",ios::out); // lưu cùng thư mục
    // cau a
    in >> n;
    in.ignore();
    for(int i = 0; i < n;i++)
        nhapfile(a[i],in);
    for(int i = 0; i < n;i++)
        infile(a[i],ou);
    // cau b
    string t;
    getline(cin,t);
    for(int i = 0; i < n;i++)
        if(a[i].tloai.find(t) != string::npos)
            ins(a[i]);
    // cau c
    getline(cin,t);
    for(int i = 0; i < n;i++)
        if(a[i].tna9.find(t) != string::npos)
            ins(a[i]); 
    // cau d
    getline(cin,t);
    for(int i = 0; i < n;i++)
        if(a[i].tddien.find(t) != string::npos)
            ins(a[i]); 
    in.close();
    ou.close();
    return 0;
}