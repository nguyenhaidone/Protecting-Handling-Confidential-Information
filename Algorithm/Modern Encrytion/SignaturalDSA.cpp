#include<bits/stdc++.h>

using namespace std;
//Tinh modulo bang cach ha bac
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
//Tinh nghich dao
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}


int main(){
	int p = 23;
	int q = 11;
	int h = 6;
	int xA = 8;
	int k = 9;
	int hm = 10;
	int calcG = (p-1)/q;
	int g = getValue(h,calcG,p);
	int y = getValue(g,xA,p);
	cout<<"Step 1: Cac gia tri dung chung.\n\t\tp="
		<<p<<" : la so nguyen to\n\t\tq="<<q
		<<" : la uoc so nguyen to cua "<<p
		<<"- 1\n\t\th="<<h<<" la so nguyen thoa man 1<"<<h
		<<" <("<<p<<"-1) sao cho g = "<<g<<">1"<<endl;
	cout<<"Step 2: Nguoi dung.\n\t\tKhoa rieng: "<<xA<<" thoa man 0<"<<xA<<"<"<<q<<"\n\t\tKhoa cong khai: y = "<<y<<"\n\t\tSo bi mat k = "<<k<<" thoa man 0<"<<k<<"q"<<endl;
	int r = getValue(g,k,p)%q;
	int s1 = modInverse(k,q);
	int s2 = (hm+xA*r)%q;
	cout<<endl<<s1<<" va "<<s2<<endl;
	int s = (s1*s2)%q;
	cout<<"Step 3: Chu ki so: \n\t\tr="<<r<<"\n\t\ts="<<s<<"\n\t\tChu ki so: ("<<r<<" , "<<s<<")"<<endl;
	int hmFake = hm;
	int sFake = s;
	int rFake = r;
	int w = modInverse(sFake,q);
	int u1 = (hmFake*w)%q;
	int u2 = (rFake*w)%q;
	int gu1 = getValue(g,u1,p);
	int yu2 = getValue(y,u2,p);
	int v = ((gu1*yu2)%p)%q;
	cout<<endl<<w<<" - "<<u1<<" - "<<u2<<" - "<<gu1<<" - "<<yu2<<" - "<<v<<endl;
	if(v==rFake)
		cout<<"Dung roi!";
	else
		cout<<"Sai roi!";
	
//	cout<<"Step 4: Xac minh chu ky: \n\t\tw = "<<sFake
	
		
}
