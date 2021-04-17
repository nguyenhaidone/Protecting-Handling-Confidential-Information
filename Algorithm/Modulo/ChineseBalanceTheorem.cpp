#include<bits/stdc++.h>
using namespace std;
//Tam thoi chi tinh duoc khi phan tich thanh phi(n) thanh 2 thua so nguyen to
//phan tich thanh cac thua so nguyen to
void primeAnalys(int N, int &a, int &b){
//    int Euler = 1;
    int kq[2];
    int i=0;
    
    map<int, int> m;
    for(int i = 2; i <= N; i++){
        while(N % i == 0){
            m[i]++;
            N /= i;
        }
    }
    
    for(auto it : m){
    	if(i>=2){
    		cout<<"Khong tinh duoc, cai nay chi tinh duoc 2 phan tu thoi!";
    		break;
		} else {
			kq[i]=it.first;
    		i++;	
		}
//    	Euler*=pow(it.first,it.second)-pow(it.first,it.second-1);
    }
    
    a=kq[0];
    b=kq[1];
}

// dung ha bac de tinh modulo
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

//tinh ai = A mod m1

void calcAmodm(int A, int k, int m1, int m2, int &a1, int &a2){
	cout<<A<<" - "<<k<<" - "<<m1<<" - "<<m2<<endl;
	int rAmodm1 = A%m1;
	int kAmodm1 = k%(m1-1);
	cout<<rAmodm1<<"^"<<kAmodm1<<endl;
	a1 = getValue(rAmodm1,kAmodm1,m1);
	int rAmodm2 = A%m2;
	int kAmodm2 = k%(m2-1);
	a2 = getValue(rAmodm2,kAmodm2,m2);
}

//tinh nghich dao modulo

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

// tinh ci

int calcCi(int N, int m1, int m2, int &c1, int &c2){
	int M1 = N/m1;
	int M2 = N/m2;
	
	c1 = M1*modInverse(M1,m1);
	c2 = M2*modInverse(M2,m2);
}

int main(){
	int m1,m2,a1,a2,c1,c2;
	int kq=0;
	int A = 101;
	int k = 59;
	int n = 323;
	primeAnalys(n,m1,m2);
	calcAmodm(A,k,m1,m2,a1,a2);
	calcCi(n,m1,m2,c1,c2);
	kq = (a1*c1 + a2*c2)%n;
//	if(kq<0){
//		cout<<" "<<m1<<" "<<m2<<" "<<a1<<" "<<a2<<" "<<c1<<" "<<c2<<" "<<(a1*c1 + a2*c2)<<endl;
//		cout<<"Vay ket qua cua "<<A<<"^"<<k<<"mod"<<n<<"="<<n+kq;
//	} else {
//		cout<<" "<<m1<<" "<<m2<<" "<<a1<<" "<<a2<<" "<<c1<<" "<<c2<<" "<<(a1*c1 + a2*c2)<<endl;
//		cout<<"Vay ket qua cua "<<A<<"^"<<k<<"mod"<<n<<"="<<kq;
//	}
	cout<<" "<<m1<<" "<<m2<<" "<<a1<<" "<<a2<<" "<<c1<<" "<<c2<<" "<<(a1*c1 + a2*c2)<<endl;
	cout<<"Vay ket qua cua "<<A<<"^"<<k<<"mod"<<n<<"="<<kq;
	
}
