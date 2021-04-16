#include <bits/stdc++.h>
using namespace std;
  
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}
// Driver Program
int main()
{
    int a = 61, m = 3220;
    cout<<modInverse(a, m);
    return 0;
}
