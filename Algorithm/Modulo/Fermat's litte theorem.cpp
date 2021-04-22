#include<bits/stdc++.h>
using namespace std;

//check gcd(a,p)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

//check prime
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

//calc
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


int main(){
	int a=4;
	int m=13;
	int p=13;
	if(gcd(a,p)==1 && isPrime(p)==true){
		if(m>p){
			m=m/(p-1);
			cout<<m<<endl;
		}
		else if(m==(p-1))
			cout<<"Co the ap dung ferma!\nKet qua la: 1";
		else if(m==p)
			cout<<"Co the ap dung ferma!\nKet qua la: "<<a;
		else
			cout<<"Co the ap dung ferma!\nKet qua la: "<<getValue(a,m,p);
	} else {
		cout<<"Khong ap dung ferma duoc!";
	}
}
