#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

int binToten(string s)
{
	int n = 0;
	int r = 0;
	int c = 2;
	for (int i = 0; i < s.size(); i++)
	{
		n += (s[i] - '0') * pow(2, c);
		c--;
	}
	return n;
}
int main()
{
	string s;
	int n = 0;
	int t = 0;
	string st = "000";
	string state[8] = { "SN ","SN " ,"SN ","SN " ,"SN " ,"SN " ,"SN " ,"SN " };
	cout << "Please input actual outcome: ";
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		cout << "state" << setw(50) << "prediction " << setw(10) << "actual " << setw(10) << "miss" << endl;
		if (s[i] == 'T')
		{
			cout << st << " ";
			for (int i = 0; i < 8; i++)
				cout  << state[i] << " ";
			cout << setw(15);
			if (state[binToten(st)] == "SN ")
			{
				cout << setw(10) << "N " << setw(14) << "T " << setw(14) << "yes";
				state[binToten(st)] = "WN1";
			}
			else if (state[binToten(st)] == "WN1")
			{
				cout << setw(10) << "N " << setw(14) << "T " << setw(14) << "yes";
				state[binToten(st)] = "WN2";
			}
			else if (state[binToten(st)] == "WN2")
			{
				cout << setw(10) << "N " << setw(14) << "T " << setw(14) << "yes";
				state[binToten(st)] = "WN3";
			}
			else if (state[binToten(st)] == "WN3")
			{
				cout << setw(10) << "T " << setw(14) << "T " << setw(14) << "no ";
				state[binToten(st)] = "WT1";
			}
			else if (state[binToten(st)] == "WT1")
			{
				cout << setw(10) << "N " << setw(14) << "T " << setw(14) << "yes";
				state[binToten(st)] = "WT2";
			}
			else if (state[binToten(st)] == "WT2")
			{
				cout << setw(10) << "N " << setw(14) << "T " << setw(14) << "yes";
				state[binToten(st)] = "WT3";
			}
			else if (state[binToten(st)] == "WT3")
			{
				cout << setw(10) << "T " << setw(14) << "T " << setw(14) << "no ";
				state[binToten(st)] = "ST ";
			}
			else if (state[binToten(st)] == "ST ")
			{
				cout << setw(10) << "N " << setw(14) << "T " << setw(14) << "yes";
				state[binToten(st)] = "ST ";
			}
			char a = '1';
			st.erase(0, 1);
			st.push_back(a);

		}
		else
		{
			cout << st << " ";
			for (int i = 0; i < 8; i++)
				cout << state[i] << " ";
			if (state[binToten(st)] == "SN ")
			{
				cout << setw(10) << "N " << setw(14) << "N " << setw(14) << "no ";
				state[binToten(st)] = "SN ";
			}
			else if (state[binToten(st)] == "WN1")
			{
				cout << setw(10) << "N " << setw(14) << "N " << setw(14) << "no ";
				state[binToten(st)] = "SN ";
			}
			else if (state[binToten(st)] == "WN2")
			{
				cout << setw(10) << "N " << setw(14) << "N " << setw(14) << "no ";
				state[binToten(st)] = "WN1";
			}
			else if (state[binToten(st)] == "WN3")
			{
				cout << setw(10) << "T " << setw(14) << "N " << setw(14) << "yes";
				state[binToten(st)] = "WN2";
			}
			else if (state[binToten(st)] == "WT1")
			{
				cout << setw(10) << "N " << setw(14) << "N " << setw(14) << "no ";
				state[binToten(st)] = "WN3";
			}
			else if (state[binToten(st)] == "WT2")
			{
				cout << setw(10) << "N " << setw(14) << "N " << setw(14) << "no ";
				state[binToten(st)] = "WT1";
			}
			else if (state[binToten(st)] == "WT3")
			{
				cout << setw(10) << "N " << setw(14) << "N " << setw(14) << "no ";
				state[binToten(st)] = "WT2";
			}
			else if (state[binToten(st)] == "ST ")
			{
				cout << setw(10) << "T " << setw(14) << "N " << setw(14) << "yes";
				state[binToten(st)] = "WT3";
			}
			char a = '0';
			st.erase(0, 1);
			st.push_back(a);
		}
		cout << endl << endl;
	}
}
