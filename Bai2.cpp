/*
    MSSV: 23110274
    Ho va Ten: Huynh Duy Nguyen
    Ngay sinh: 16/12/2005
    Lop: PRTE230385_05    
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(){
    fstream in,ou;
    ou.open("Bai2out.txt",ios::out);
    in.open("Bai2in.txt",ios::in);
    int a,b,c;
    in >> a >> b >> c;
    double delta = b*b - 4*a*c;
    if(delta < 0)
        ou << "Phuong trinh vo nghiem ";
    else if(delta == 0)
        ou << "Phuong trinh co nghiem kep: x = " << -1.0*b/(2*a);
    else
    {
        ou << "Phuong trinh co hai nghiem phan biet :\n";
        ou << "x1 = " << 1.0*(-b+sqrt(delta))/(2*a);
        ou << "\nx2 = " << 1.0*(-b-sqrt(delta))/(2*a);

    }
    ou.close();
    in.close();
    return 0;
}