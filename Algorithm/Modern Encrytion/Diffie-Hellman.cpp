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


int main(){
	int q = 7523;
	int a = 5;
	int xA = 387;
	int xB = 247;
	int total = xA*xB;
	cout<<"\nThuat toan diffie-dellman";
	cout<<"\nKhoa cong khai yA = "<<getValue(a,xA,q);
	cout<<"\nKhoa cong khai yB = "<<getValue(a,xB,q);
	cout<<"\nKhoa phien K la = "<<getValue(a,total,q);
}
