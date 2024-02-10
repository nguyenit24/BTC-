/*
    MSSV: 23110274
    Ho va Ten: Huynh Duy Nguyen
    Ngay sinh: 16/12/2005
    Lop: PRTE230385_05    
*/
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
int main(){
    fstream in,o;
    in.open("Bai3out.txt",ios::in);
    o.open("Bai4out.txt",ios::out);
    int n, a[1000];
    in >> n;
    for(int i=0;i<n;i++){
        in >> a[i];
    }
    sort(a,a+n);
    o << n << endl;
    for(int i=0;i<n;i++){
        o << a[i] << " ";
    }
    in.close();
    o.close();
    return 0;
}