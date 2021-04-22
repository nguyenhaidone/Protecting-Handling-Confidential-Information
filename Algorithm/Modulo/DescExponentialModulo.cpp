#include<bits/stdc++.h>
using namespace std;

int ha_bac_1(int a, int m, int n){
	int arr[100];//luu so du
	
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

double ha_bac_2(int a, int m, int n) {
	if (m <= 3)
		return (long)pow(a, m) % n;
		
	if (m % 2 == 0) {
		double sub = ha_bac_2(a, m / 2, n);
		return (long)pow(sub, 2) % n;
	}
	double sub = ha_bac_2(a, (m - 1) / 2, n);
	return (((long)pow(sub, 2) % n) * (a % n)) % n;
}

int main(){
	cout << ha_bac_1(281, 764, 6967) << endl;
	cout << ha_bac_2(281, 764, 6967) << endl;
	return 0;
}
