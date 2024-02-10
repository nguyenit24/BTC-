/*
    MSSV: 23110274
    Ho va Ten: Huynh Duy Nguyen
    Ngay sinh: 16/12/2005
    Lop: PRTE230385_05    
*/
#include <fstream>
#include <iostream>
#include <math.h>
bool isprime(int t){
    if(t<2)
        return false;
    for(int i = 2; i <= sqrt(t);i++){
        if(t%i==0)
            return false;
    }
    return true;
}
using namespace std;
int main(){
    fstream in,o;
    in.open("Bai3out.txt",ios::in);
    o.open("Bai5out.txt",ios::out);
    int n, a[1000],d=0;
    in >> n;
    for(int i=0;i<n;i++){
        in >> a[i];
    }
    for(int i=0;i<n;i++){
       if(isprime(a[i]))
            d++;
    }
    o << d;
    in.close();
    o.close();
    return 0;
}