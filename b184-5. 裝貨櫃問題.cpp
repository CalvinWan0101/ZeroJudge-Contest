#include <iostream>
#include <algorithm>
using namespace std;
int cha[200] = { 0 };
int DP(int n, int w[], int v[], int C)
{
	int buffer = -1000;
	//chartone[i]的i為背包的容量上限
	//數據
	for (int q = 0; q < n; q++)
		//背包容量
	{
		for (int p = C; p >= 0; p--)
			if (p < w[q])
				continue;
			else
				cha[p] = max(cha[p], cha[p - w[q]] + v[q]);
		/*cout << "q = " << q << "的時候" << endl;
		for (int i = 0; i <= C; i++)
			cout << cha[i] << " ";
		cout << endl;*/
	}
	for (int i = 0; i < C; i++)
		if (cha[i] > buffer)
			buffer = cha[i];
	return buffer;
}
int main()
{
	int w[100];
	int v[100];
	int n, i;
	int C, buffer;
	C = 100;
	while (cin >> n)
	{
		for (int i = 0; i <= C; i++)
			cha[i] = { 0 };
		for (i = 0; i < n; i++)
			cin >> w[i] >> v[i];
		//用重量排序一次
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (w[i] > w[j])
				{
					buffer = w[i];
					w[i] = w[j];
					w[j] = buffer;
					buffer = v[i];
					v[i] = v[j];
					v[j] = buffer;
				}
		cout << DP(n, w, v, C) << endl;
	}
}