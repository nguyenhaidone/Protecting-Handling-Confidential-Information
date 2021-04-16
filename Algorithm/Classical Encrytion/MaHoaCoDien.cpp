#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

char M[100],K[100];
int key = 0,n = -1, nK = -1;

void Reset()
{
	for(int i = 0; i < 100; i++){
		M[i] = '0';
		K[i] = '0';
	}
	key = 0,n = -1, nK = -1;
}

void convert(int i){			//		chuyen 'a' => 'A'
	if(M[i] > 'Z'){
		M[i] -= 32;
	}
	
	if(K[i] > 'Z'){
		K[i] -= 32;
	}		
}

void inputKeyNumber()
{
	cout<<"K = ";
	cin>>key;
}

void inputKeyChar()
{
//	Nhap Key
	cout<<"K = ";
	for(int i = 0; i <= 100; i++){
		cin>>K[i];
		nK++;
		if(K[i] == '0'){
			break;
		}
	}
}

void inputM()
{
	cout<<"Chu y!!!\n\tDung ky tu '0' de ket thuc chuoi\nChu y!!!\nM = ";
	for(int i = 0; i <= 100; i++){
		cin>>M[i];
		n++;
		if(M[i] == '0'){
			break;
		}
	}
}


void caesar()
{
	inputM();
	inputKeyNumber();
	cout<<"C = ";
	for(int i = 0; i < n; i++){
		if(M[i] > 'Z'){
			M[i] -= 32;
		}
		int var = M[i] + key;
		if(var > 90){
			var -= 26;
		}
		cout<< static_cast<char>(var);
	}
	Reset();
}
void videnereAutoKey()
{
	inputM();
	inputKeyChar();
//	Output
	cout<<"C = ";
	int j = 0;
	for(int i = 0; i < n; i++){
		convert(i);
		int var = 0;
		if(j < nK){
			var = M[i] + K[j] - 65;
			j++;
		}else{
			var = M[i] + M[i-nK] - 65;
		}
		if(var > 90){
			var -= 26;
		}
		
		cout<< static_cast<char>(var);
	}
	Reset();
}
void videnereLK()
{
	inputM();
	inputKeyChar();
	cout<<"C = ";
	int j = 0;
	for(int i = 0; i < n; i++){
		convert(i);
		int var = M[i] + K[j] - 65;
		j++;
		if(j == nK){
			j -= nK;
		}
		if(var > 90){
			var -= 26;
		}
		cout<< static_cast<char>(var);
	}
	Reset();
}

void MMChuDon()
{
	inputM();
	inputKeyChar();
	cout<<"C = ";
	for(int i = 0; i < n; i++){
		convert(i);
		
		int var = M[i] - 65;
		cout<< K[var];
	}
	Reset();
}

void MMHoanVi()
{
	inputM();
	inputKeyNumber();

	cout<<"C = ";
	for(int i = 0; i < key; i++)
		for(int j = i; j < n; j += key){
			cout<< M[j];
		}
	Reset();
}

int menu(){
			
			cout<<"--------------Chon chuc nang tu 1..7-----------------\n";
		    cout<<"-1.Mat ma CAESAR.\n";
			cout<<"-2.Mat ma VIGENERE - Lap Khoa.\n";
			cout<<"-3.Mat ma VIGENERE - Auto Khoa.\n";
			cout<<"-4.Mat ma CHU DON.\n";
			cout<<"-5.Mat ma MA TRAN KHOA PLAYFAIR.\n";
			cout<<"-6.Mat ma HOAN VI.\n";
			cout<<"-7.Ket thuc chuong trinh.\n";
			int n;
			cin>>n; 
			return n;			
}

void run()
	{
		int ch;
		do{
			system("cls"); // xoa man hinh
			ch = menu();
			system("cls");
			switch(ch){
				case 1:
					caesar();
					break;
				case 2:
					videnereLK();
					break;
				case 3:
					videnereAutoKey();
					break;
				case 4:
					MMChuDon();
					break;
				case 5:
					cout<<"Chuong trinh chua hoan thanh!!!";
					break;
				case 6:
					MMHoanVi();
					break;
			}
			getch();
		}while(ch!=7);
}

int main()
{
	run();
	return 0;	
}

