#include<bits/stdc++.h>
using namespace std;

//check gcd(a,p)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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

// calc phi(n)
int findFi(int N){
    int Euler = 1;
    
    map<int, int> m;
    for(int i = 2; i <= N; i++){
        while(N % i == 0){
            m[i]++;
            N /= i;
        }
    }
    
    for(auto it : m){
    	Euler*=pow(it.first,it.second)-pow(it.first,it.second-1);
    }
    return Euler;
}

int main(){
	//a^m mod n
	int a = 3;
	int m = 8;
	int n = 10;
	int phiN = findFi(n);
	if(gcd(a,n)==1 && phiN<=m){
		cout<<"Co the ap dung Euler: \n\tPhi(n) = "<<phiN<<endl<<a<<"^"<<m<<" mod "<<n<<" = ";
		if(m==phiN)
			cout<<1;
		else{
			m = m%phiN;
			cout<<getValue(a,m,n);
		}
	}
}
