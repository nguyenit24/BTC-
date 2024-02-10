//MSSV:23110274

//Ho Ten SV: Huynh Duy Nguyen

//Ngày sinh: 16/12/2005

//Lop: PRTE230385_23_2_05
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct HOCSINH{
	string MS,ten,da,diachi,phai;
	float dtb;
};
int main(){
	HOCSINH a[50];
    fstream u,o;
    u.open("Bai8in.txt",ios::in);
    o.open("Bai8out.txt",ios::out);
	int n,dem = 0;
	u >> n;
	for(int i = 0; i<n;i++)
	{
        u.ignore();
        getline(u,a[i].MS);
        getline(u,a[i].ten);
        getline(u,a[i].da);
        getline(u,a[i].diachi);
        getline(u,a[i].phai);
        u >> a[i].dtb;
        if(a[i].dtb >= 5)
            dem++;
	}
	for(int i = 0;i<n;i++)
	{
		o << a[i].MS << endl;
	    o << a[i].ten << endl;
	    o << a[i].da << endl;
	    o << a[i].diachi << endl;
	    o << a[i].phai << endl;
	    o << a[i].dtb << endl;
	}
	o << dem;
    u.close();
    o.close();
	return 0;
}