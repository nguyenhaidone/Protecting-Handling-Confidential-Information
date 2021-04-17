#include<bits/stdc++.h>
using namespace std;

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

//tinh nghich dao modulo

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

int main(){
	int m1,m2,a1,a2,c1,c2;
	int A = 163;
	int k = 79;
	int N = 70151;
	int M = N;
	int kq[100];
    int counti=0;
	// analyst
    
    map<int, int> m;
    for(int i = 2; i <= N; i++){
        while(N % i == 0){
            m[i]++;
            N /= i;
        }
    }
    
    for(auto it : m){
			kq[counti]=it.first;
    		counti++;	
    }
    for(int i = 0; i<counti;i++){
    	cout<<kq[i]<<endl;
	}
	int ai[counti];
	for(int i = 0; i<counti;i++){
		ai[i]=getValue(A,k,kq[i]);
		cout<<"a["<<i<<"] = "<<ai[i]<<endl;
	}
	int Mi[counti];
	for(int i = 0; i<counti;i++){
		Mi[i]=M/kq[i];
		cout<<"M["<<i<<"] = "<<Mi[i]<<endl;
	}
	int Ci[counti];
	for(int i = 0; i<counti;i++){
		Ci[i]=Mi[i]*modInverse(Mi[i],kq[i]);
		cout<<"C["<<i<<"]"<<Ci[i]<<" - "<<Mi[i]<<" - "<<modInverse(Mi[i],kq[i])<<endl;
	}
	int total = 0;
	for(int i = 0;i<counti;i++){
		total+=ai[i]*Ci[i];
	}
	cout<<"total: "<<total<<"\n ket qua: "<<total%M;
}
