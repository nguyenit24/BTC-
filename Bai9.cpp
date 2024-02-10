//MSSV:23110274

//Ho Ten SV: Huynh Duy Nguyen

//Ngày sinh: 16/12/2005

//Lop: PRTE230385_23_2_05
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
struct ps
{
    long t,m;
};
void toigian(ps &j){
    long a = abs(j.t), b = abs(j.m);
    while(a!=b){
        if(a>b)
            a -= b;
        else    
            b-= a;
    }
    j.t = j.t/a;
    j.m = j.m/a;
}
void chuanhoa(ps &j){
    if(j.t != 0)
        toigian(j);
    j.t = j.t*(j.m/abs(j.m));
    j.m = abs(j.m);
}
float value(ps b){
    return 1.0*b.t/b.m;
}
ps sum2(ps a,ps b){
    ps t;
    t.t=a.t*b.m+b.t*a.m;
    t.m=a.m*b.m;
    chuanhoa(t);
    return t;
}
ps sum(ps a[],int n){
    ps tong=a[0];
    for(int i = 1; i<n;i++ ){
        tong = sum2(tong,a[i]);
    }
    return tong;
}
ps tich2(ps a,ps b){
    ps t;
    t.t=a.t*b.t;
    t.m=a.m*b.m;
    chuanhoa(t);
    return t;
}
ps tich(ps a[],int n){
     ps t=a[0];
    for(int i = 1; i<n;i++ ){
        t = tich2(t,a[i]);
    }
    return t;
}
void dn(ps &a){
    long c = a.t;
    a.t=a.m;
    a.m = c;
    chuanhoa(a);
}
int main(){
    fstream infile,outfile;
    infile.open("Bai9in.txt",ios::in);
    outfile.open("Bai9out.txt",ios::out);
    int n;
    ps a[50];
    infile >> n;
    for(int i = 0; i<n;i++){
        infile >> a[i].t;
        infile >> a[i].m;
    }
    for(int i = 0; i<n;i++){
       chuanhoa(a[i]);
    }
    // psmax
    ps ln = a[0];
    for(int i = 0; i<n;i++){
        if(value(a[i]) > value(ln))
            ln = a[i];
    }
    chuanhoa(ln);
    outfile << ln.t << " " << ln.m << endl;
    ps sums=sum(a,n);
    outfile << sums.t << " " << sums.m << endl;
    ps t=tich(a,n);
    outfile << t.t << " " << t.m << endl;
    for(int i = 0; i<n;i++){
        dn(a[i]);
        outfile << a[i].t << " " << a[i].m << "  ";
    }
    infile.close();
    outfile.close();
    return 0;
}
