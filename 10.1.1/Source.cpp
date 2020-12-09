#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) 
{
	ofstream fout(fname);
	char ch;
	string s; 
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	while (getline(fin, s)) 
	{
		cout << s << endl; 
	}
	cout << endl;
}
int ProcessTXT1(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	int k = 0; 
	while (getline(fin, s)) 
	{ 
		for (unsigned i = 0; i < s.length(); i++)
			if (s[i] == 'c' &&
				s[i + 1] == 'c' &&
				s[i + 2] == 'c' &&
				s[i + 3] == 'c')

				k++;
	}
	return k;
}

void SortTXT(char* fname, char* gname) 
{
	ofstream g(gname); 
	string s, mins, z = ""; 
	int k; 
	do 
	{ 
		k = 0;
		ifstream f(fname);
		while (getline(f, s)) 
		{
			if (s <= z)
				continue;
			mins = s; 
			k++; 
			break; 
		} 
		while (getline(f, s)) 
		{
			if (s <= z) 
				continue;
			if (s < mins) 
			
			{ 
				mins = s;
				k++; 
			} 
		}
		
		z = mins;
		if (k > 0) 
			g << z << endl; 
		f.close();
	}
	while (k > 0); 
}
int main()
{
	
	char fname[100]; 
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname); 
	PrintTXT(fname); 
	cout << "k(cccc) = " << ProcessTXT1(fname) << endl;
	char gname[100]; 
	cout << "enter file name 2: "; cin >> gname;
	SortTXT(fname, gname); 
	PrintTXT(gname); 
	return 0;
}