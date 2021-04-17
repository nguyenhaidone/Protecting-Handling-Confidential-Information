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
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

int main(){
	int a = 83;
	int b = 17;
	int x = 354;
	int y = 314;
	int n = 241;
	int amodn = getValue(a,x,n);
//	cout<<amodn<<endl;
	
	int bmodn = getValue(b,y,n);
//	cout<<bmodn<<endl;
	
	int reverseb = modInverse(bmodn,n);
//	cout<<reverseb<<endl;
	
	cout<<"A1 = ("<<a<<"^"<<x<<"+"<<b<<"^"<<y<<") mod "<<n<<" = "<<(amodn+bmodn)%n<<endl;
	cout<<"A2 = ("<<a<<"^"<<x<<"-"<<b<<"^"<<y<<") mod "<<n<<" = "<<(amodn-bmodn)%n<<endl;
	cout<<"A3 = ("<<a<<"^"<<x<<"*"<<b<<"^"<<y<<") mod "<<n<<" = "<<(amodn*bmodn)%n<<endl;
	cout<<"A4 = ("<<b<<"^-"<<y<<") mod "<<n<<" = "<<reverseb<<endl;
	cout<<"A5 = ("<<a<<"^"<<x<<"/"<<b<<"^"<<y<<") mod "<<n<<" = "<<(amodn*reverseb)%n<<endl;
}
