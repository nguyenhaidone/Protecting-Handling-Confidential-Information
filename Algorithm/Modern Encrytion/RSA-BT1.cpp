#include <bits/stdc++.h>
using namespace std;

//tinh modulo theo phuong phap ha bac
int getValue(int &a, int &m, int &n){
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
	int q=47;
	int p=43;
	int e=67;
	int n = q*p;
	int PhiN = (p-1)*(q-1);
	int d = modInverse(e,PhiN);
	cout<<n<<" - "<<PhiN<<" - "<<d<<endl;
	cout<<"Public key: {"<<e<<","<<n<<"}"<<endl;
	cout<<"Private key: {"<<d<<","<<n<<"}"<<endl;
	int M = 59;
	int C = getValue(M,d,n);
	
	cout<<"An ma hoa: \nBan ma: "<<C<<endl;
	cout<<"Ba giai ma: \nBan ro: "<<getValue(C,e,n)<<endl;
}
