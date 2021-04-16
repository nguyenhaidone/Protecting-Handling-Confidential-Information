#include<bits/stdc++.h>
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


// tính tim phi(n) 
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

// kiem tra can nguyen thuy theo cong thuc 
// a^(phi(n)/pi)mod n = 1 => a khong phai can nguyen thuy cua n
// voi p1.p2.p3....pk = phi(n) 
bool checkNaturalSqrt(int a, int n){
	// phan tich phi(n) thanh thua so nguyen to
    int Euler = 1;
	int N=findFi(n);
	int FiN = findFi(n);
    int elem[100];
    int temp = 0; // luu findFi/pi;
    int lengthArr=0;
    
    map<int, int> m;
    for(int i = 2; i <= N; i++){
        while(N % i == 0){
            m[i]++;
            N /= i;
        }
    }
    
    for(auto it : m){
    	elem[lengthArr]=it.first;
    	lengthArr++;
    	Euler*=pow(it.first,it.second)-pow(it.first,it.second-1);
    	
    }
    
    for(int i=0;i<lengthArr;i++){
    	temp = FiN/elem[i];
    	if(getValue(a,temp,n)==1){
    		return false;
		}
	}
	return true;
}
//tim logarithm
int findLog(int a, int b, int n){
	if(checkNaturalSqrt(a,n)==true){
		cout<<"\nCo la can nguyen thuy!";
		for(int i=0;i<n;i++){
			if(getValue(a,i,n)==b){
				return i;
			}
		}
	}
	else
		cout<<"\nKhong phai la can nguyen thuy nen khong co log!";
	return 0;
}

int main()
{
    int a;
    cout<<"\nNhap a = ";
    cin>>a;
    
    int b;
   	cout<<"\nNhap b = ";
    cin>>b;
    
    int n;
    cout<<"\nNhap n = ";
    cin>>n;
    
    
    
    if(findLog(a,b,n)!=0){
    	cout<<endl<<"log("<<a<<")"<<b<<" mod "<<n<<" = "<<findLog(a,b,n);
	} else 
		cout<<"\nkhong tim duoc";
}

