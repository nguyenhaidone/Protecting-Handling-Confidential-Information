#include <bits/stdc++.h>
using namespace std;

 
int main(){
    int N;
    int Euler = 1;
    int a[100];
    int i=0;
    cout << "\nNhap n = ";
    cin >> N;
    
    map<int, int> m;
    for(int i = 2; i <= N; i++){
        while(N % i == 0){
            m[i]++;
            N /= i;
        }
    }
    
    for(auto it : m){
    	a[i]=it.first;
    	i++;
    	Euler*=pow(it.first,it.second)-pow(it.first,it.second-1);
    }
    cout<<"Phi(n) = "<<Euler;
}

