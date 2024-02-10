/*
    MSSV: 23110274
    Ho va Ten: Huynh Duy Nguyen
    Ngay sinh: 16/12/2005
    Lop: PRTE230385_05    
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int main(){
    fstream in,o;
    in.open("Bai6in.txt",ios::in);
    o.open("Bai6out.txt",ios::out);
    string vb;
    char kytu;
    do
    {
        cout << "Nhap : ";
        getline(cin,vb);
        o << vb << endl;
        cout << "Nhan enter de nhap/Nhan ESC de thoat: ";
        kytu = _getch();
        cout << endl;
    } while (kytu != 27);
    in.close();
    o.close();
    return 0;
}