#include <bits/stdc++.h>
using namespace std;
  
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++){
//    	cout<<"x="<<x<<" - m="<<m<<endl;
//		tim x sao cho x*a mod m == 1
        if (((a%m) * (x%m)) % m == 1){
//			cout<<"a = "<<a<<" m = "<<m<<" x = "<<x<<" (a%m) * (x%m)) % m = "<<(a%m) * (x%m) % m<<endl;
            return x;
		}
    }
    	
}
// Driver Program
int main()
{
    int a = 116, m = 241;
    cout<<modInverse(a, m);
    return 0;
}
