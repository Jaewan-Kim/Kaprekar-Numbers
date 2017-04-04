#include<iostream>
#include <vector>
#include <string>
#include<math.h>
using namespace std;

double nofdigits(int x)
{
	if (x == 0)
		return 0;
	else
		return 1 + nofdigits(x / 10);
}

pair<int, int> split(int x)
{

	if (x == 0)
		return pair<int, int>(0, 0);
	else if (nofdigits(x) == 1)
	{
		return pair<int, int>(x, 0);
	}
	else
	{
		int tempi = nofdigits(x) / 2;
		int divisor = pow(10, tempi);
		return pair<int, int>(x / divisor, x %divisor);
		
	}
}

void kaprekar()
{
	vector<int> kaps;
	cout << "Lower bound: ";
	int l;
	cin >> l;
	cout << "Upper bound: ";
	int u;
	cin >> u;
	for (int i = l; i <= u; i++)
	{
		pair<int, int> kap = split(i*i);
		if (kap.first + kap.second == i&& kap.second != 0)
			kaps.push_back(i);
		
	}
	cout << "Kaprekar numbers:" << endl;
	for (int i : kaps)
		cout << i << endl;
}

int main()
{
	kaprekar();
}