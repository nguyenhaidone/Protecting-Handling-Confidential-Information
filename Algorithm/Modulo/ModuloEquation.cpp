#include<bits/stdc++.h>
using namespace std;

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

//tinh nghich dao modulo

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

// tinh ci

int calcCi(int m1, int m2, int m3, int &c1, int &c2, int &c3){
	int M = m1*m2*m3;
	int M1 = M/m1;
	int M2 = M/m2;
	int M3 = M/m3;
	
	c1 = M1*modInverse(M1,m1);
	c2 = M2*modInverse(M2,m2);
	c3 = M3*modInverse(M3,m3);
}

int main(){
	int m1,m2,m3,a1,a2,a3,c1,c2,c3;
	int kq=0;
	cout<<"Nhap m1->3:";
	cin>>m1>>m2>>m3;
	cout<<"Nhap a1->3:";
	cin>>a1>>a2>>a3;
	calcCi(m1,m2,m3,c1,c2,c3);
	kq = (a1*c1 + a2*c2 + a3*c3)%(m1*m2*m3);
	cout<<"m1: "<<m1<<"\nm2: "<<m2<<"\nm3: "<<m3<<"\na1: "<<a1<<"\na2: "<<a2<<"\na3: "<<a3<<"\nc1: "<<c1<<"\nc2: "<<c2<<"\nc3: "<<c3<<"\ntotal: "<<(a1*c1 + a2*c2 + a3*c3)<<endl;
	cout<<"Vay ket qua "<<"="<<kq;
	
}
