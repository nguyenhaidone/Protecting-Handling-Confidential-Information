#include<bits/stdc++.h>
using namespace std;

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
	int a,m,n;
	
	cout<<"b=a^m mod n\n";
	cout<<"Nhap a: ";cin>>a;
	cout<<"Nhap m: ";cin>>m;
	cout<<"Nhap n: ";cin>>n;
	cout<<"\nha bac luy thua:";
	
	cout<<"\nb= "<<getValue(a,m,n);
}
