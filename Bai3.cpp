/*
    MSSV: 23110274
    Ho va Ten: Huynh Duy Nguyen
    Ngay sinh: 16/12/2005
    Lop: PRTE230385_05    
*/
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));
    fstream p;
    p.open("Bai3out.txt",ios::out);
    int n,a[1000];
    cin >> n;
    p << n;
    p << endl;
    for(int i=0;i<n;i++){
        a[i] = rand()%(1001);
        p << a[i] << "\t";
    }
    p.close();
    return 0;
}