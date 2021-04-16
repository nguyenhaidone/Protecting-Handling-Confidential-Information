#include <bits/stdc++.h>
using namespace std;

//tinh modulo theo phuong phap ha bac
int getValue(int a, int m, int n){
	int arr[100];
	int x=0;
	while(m>3){
		if(m%2==0){
			m=m/2;
			arr[x]=0;
		}
		else{
			m=m/2;
			arr[x]=1;
		}
		x++;
	}
	long long t=(long long)(pow(a,m))%n;
	for(int i=x-1;i>=0;i--){
		if(arr[i]==0){
			int r=t;
			t=(long long)pow(t,2)%n;
		}
		else if(arr[i]==1){
			int r=t;
			t=(long long)(pow(t,2)*a)%n;
		}
	}
	return t;
}

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

int main(){
	int q = 809;
	int a = 3;
	int xA = 57;
	int khoa = 150;
	int M = 270;
	int yA = getValue(a,xA,q);
	int K = getValue(yA,khoa,q);
	int kq = K*M;
	int asd = 1;
	cout<<"yA = "<<yA;
	cout<<"\nKhi Ba gui tin nhan:"<<K<<endl;
	int c1 = getValue(a,khoa,q);
	int c2 = getValue(kq,asd,q);
	cout<<"\nGia tri C1: "<<c1;//c1 = a^k mod q
	cout<<"\nGia tri C2: "<<c2;
	cout<<"\nBan ma (C1,C2) = ("<<c1<<","<<c2<<")";
	int kC=getValue(c1,xA,q);
	cout<<"\nAn giai ma: ";
	cout<<"\n"<<kC;
	int m1 = c2%q;
	int m2 = modInverse(kC,q);
	cout<<"\nKet qua: "<<(m1*m2)%q;
}
