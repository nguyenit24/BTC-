/*
    MSSV: 23110274
    Ho va Ten: Huynh Duy Nguyen
    Ngay sinh: 16/12/2005
    Lop: PRTE230385_05    
*/
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    fstream p;
    p.open("Bai1out.txt",ios::out);
    int a,b,c;
    cin >> a >> b >> c; 
    p << a << " " << b << " " << c; 
    p.close();
    return 0;
}