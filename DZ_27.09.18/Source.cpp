#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream in_file("in.txt");
ofstream out_file("out.txt");



void main()
{
	setlocale(LC_ALL, "Rus");
	int number;
start:
	cout << "������� ����� �������: ";
	cin >> number;
	if (number == 1)
	{
		cout << "��� ��������� ����. ������� �� ���� ��������� ������. ��������� �������� � ������ ����." << endl;
		const int len = 30, strings = 3;
		char str[len][strings];
		for (int i = 0; i < strings - 1; i++)
		{
			in_file.getline(str[i], len - 1);
			out_file << str[i] << endl;
		}

	}

	else if (number == 2)
	{
		cout << "��� ��������� ����. ����� ����� ����� ������� ������." << endl;
		char* str;
		str = new char;
		char max = str[0];
		while (!in_file.eof())
		{
			for (int i = 0; i < 20; i++)
			{
				in_file.getline(str, 20);
				out_file << str << endl;
				if (max > str[i])
					max = str[i];					
			}	
			
		}
		cout << max << endl;
		
		
	}
	else if (number == 3)
	{
		cout << "��� ��������� ����. ���������� ���������� ����, ������������ � �������, ������� ����� ������������." << endl;
		char name[100];		
		char * p, *context;
		int k = 0;
		char choice;
		cout << "������� ��������� �����: ";
		cin >> choice;
		while (!in_file.eof())
		{			
			in_file.getline(name, 100);
			p = strtok_s(name, " ", &context);			
			while (p)
			{				
				out_file << p << endl;				
				if (p[0] == choice) k++;
				p = strtok_s(context, " ", &context);
			}			
		}
		cout << "���������� ���� ������������ � ����� "<<choice<<" ����� "<< k << endl;
	}
	goto start;
	system("pause");
}